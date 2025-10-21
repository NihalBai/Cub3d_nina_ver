/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaidaou <nbaidaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 15:31:00 by nbaidaou          #+#    #+#             */
/*   Updated: 2025/10/21 13:57:59 by nbaidaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	pars_textures(t_map *map, char *line)
{
	char	*t;
	int		id;

	id = -1;
	if (ft_strncmp(line, "NO ", 3) == 0)
		id = 0;
	else if (ft_strncmp(line, "SO ", 3) == 0)
		id = 1;
	else if (ft_strncmp(line, "WE ", 3) == 0)
		id = 2;
	else if (ft_strncmp(line, "EA ", 3) == 0)
		id = 3;
	if (id == -1)
		return (0);
	if (map->textures[id].path)
		return (0);
	t = ft_strtrim(line + 3, " \n\t");
	if (!t)
		return (0);
	map->textures[id].path = t;
	printf("path %d : %s\n", id, t);
	return (1);
}

// int	parse_colors(t_map *map, char *line)
// {
// 	char	*tr;
// 	int		color;
// 	char	*trim_line;

// 	trim_line = ft_strtrim(line, " \t\n");
// 	if (ft_strncmp(trim_line, "F ", 2) == 0)
// 		tr = ft_strtrim(trim_line + 2, " \n\t");
// 	else if (ft_strncmp(trim_line, "C ", 2) == 0)
// 		tr = ft_strtrim(trim_line + 2, " \n\t");
// 	else
// 	{
// 		free(trim_line);
// 		return (0);
// 	}
// 	if (!tr)
// 		return (0);
// 	color = pars_color(tr);
// 	if (color < 0)
// 		return (0);
// 	if (ft_strncmp(trim_line, "F ", 2) == 0)
// 		map->floor_color = color;
// 	else
// 		map->ceiling_color = color;
// 	free(trim_line);
// 	free(tr);
// 	return (1);
// }
int parse_colors(t_map *map, char *line)
{
    char *trim_line;
    char *tr;
    int color;
    int is_floor = -1;

    if (!line)
        return 0;

    // Trim leading/trailing whitespace
    trim_line = ft_strtrim(line, " \t\n");
    if (!trim_line)
        return 0;

    // Determine if line is floor or ceiling
    if (ft_strncmp(trim_line, "F ", 2) == 0)
        is_floor = 1;
    else if (ft_strncmp(trim_line, "C ", 2) == 0)
        is_floor = 0;
    else
    {
        free(trim_line);
        return 0; // Not a color line
    }

    // Check if color is already set
    if ((is_floor && map->floor_color != -1) ||
        (!is_floor && map->ceiling_color != -1))
    {
        free(trim_line);
        return 0; // Duplicate color line
    }

    // Trim the actual color values after the prefix
    tr = ft_strtrim(trim_line + 2, " \t\n");
    free(trim_line);
    if (!tr)
        return 0;

    // Parse the color
    color = pars_color(tr);
    free(tr);
    if (color < 0)
        return 0;

    // Assign to map
    if (is_floor)
        map->floor_color = color;
    else
        map->ceiling_color = color;

    return 1;
}

int	parse_map(t_map *map, char *line)
{
	char	**new_grid;
	int		i;
	int		len;

	if (!safe_malloc((void **)&new_grid, sizeof(char *) * (map->height + 2)))
		return (0);
	i = 0;
	while (i < map->height)
	{
		new_grid[i] = map->map_grid[i];
		i++;
	}
	new_grid[i] = ft_strtrim(line, "\n");
	if (check_and_free(new_grid[i]) == 0)
		return (0);
	len = ft_strlen(new_grid[i]);
	if (len > map->width)
		map->width = len;
	new_grid[i + 1] = NULL;
	free(map->map_grid);
	map->map_grid = new_grid;
	map->height++;
	return (1);
}

int	check_all(t_map *map)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (!map->textures[i].path)
		{
			printf("no tex num %d\n", i);
			return (0);
		}
		i++;
	}
	if (map->floor_color == -1 || map->ceiling_color == -1)
		return (0);
	return (1);
}

// int parsing(t_map *map, int fd)
// {
//     char *line;
//     int map_started = 0;

//     while ((line = get_next_line(fd)))
//     {
//         if (!map_started && is_empty_line(line))
//         {
//             free(line);
//             continue ;
//         }
//         if (!map_started && (pars_textures(map, line) || parse_colors(map,
// line)))
//         {
//             free(line);
//             continue ;
//         }
//         if (is_map_line(line))
//         {
//             map_started = 1;
//             if (!parse_map(map, line))
//             {
//                 free(line);
//                 return (-1);
//             }
//         }
//         else if (map_started && !is_empty_line(line))
//         {
//             free(line);
//             return (-1);
//         }
//         free(line);
//     }
//     return (check_all(map));
// }
