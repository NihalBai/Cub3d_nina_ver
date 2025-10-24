/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaidaou <nbaidaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 11:18:06 by nbaidaou          #+#    #+#             */
/*   Updated: 2025/10/24 11:54:10 by nbaidaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	pars_textures(t_map *map, char *line)
{
	char	*t;
	int		id;

	id = -1;
	if (ft_strncmp(line, "EA ", 3) == 0)
		id = 0;
	else if (ft_strncmp(line, "WE ", 3) == 0)
		id = 1;
	else if (ft_strncmp(line, "SO ", 3) == 0)
		id = 2;
	else if (ft_strncmp(line, "NO ", 3) == 0)
		id = 3;
	if (id == -1)
		return (0);
	if (map->textures[id].path)
		return (0);
	t = ft_strtrim(line + 3, " \n\t");
	if (!t)
		return (0);
	map->textures[id].path = t;
	return (1);
}

static int	get_color_type(t_map *map, char *trim_line)
{
	int	is_floor;

	is_floor = -1;
	if (ft_strncmp(trim_line, "F ", 2) == 0)
		is_floor = 1;
	else if (ft_strncmp(trim_line, "C ", 2) == 0)
		is_floor = 0;
	else
		return (-1);
	if ((is_floor && map->floor_color != -1) || (!is_floor
			&& map->ceiling_color != -1))
		return (-1);
	return (is_floor);
}

int	parse_colors(t_map *map, char *line)
{
	char	*trim_line;
	char	*tr;
	int		color;
	int		is_floor;

	if (!line)
		return (0);
	trim_line = ft_strtrim(line, " \t\n");
	if (!trim_line)
		return (0);
	is_floor = get_color_type(map, trim_line);
	if (is_floor == -1)
		return (free(trim_line), 0);
	tr = ft_strtrim(trim_line + 2, " \t\n");
	free(trim_line);
	if (!tr)
		return (0);
	color = parse_color(tr);
	free(tr);
	if (color < 0)
		return (0);
	floor_or_ceilling(map, is_floor, color);
	return (1);
}

int	parse_map(t_map *map, char *line)
{
	char	**new_grid;

	if (!safe_malloc((void **)&new_grid, sizeof(char *) * (map->height + 2)))
		return (0);
	if (!copy_old_grid(new_grid, map->map_grid, map->height))
		return (free(new_grid), 0);
	char *(new_line) = ft_strtrim(line, "\n");
	if (!new_line)
		return (free(new_grid), 0);
	int (len) = ft_strlen(new_line);
	if (len > map->width && !pad_existing_rows(new_grid, map->height, len))
		return (free(new_grid), free(new_line), 0);
	if (len < map->width)
	{
		new_line = trim_and_pad_new_line(line, map->width);
		if (!new_line)
			return (free(new_grid), 0);
	}
	new_grid[map->height] = new_line;
	new_grid[map->height + 1] = NULL;
	map->width = ft_max(map->width, len);
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
			printf("Missing texture %d\n", i);
			return (0);
		}
		i++;
	}
	if (map->floor_color == -1 || map->ceiling_color == -1)
	{
		printf("Missing floor or ceiling color\n");
		return (0);
	}
	if (!map->map_grid || map->height == 0)
	{
		printf("No map data found\n");
		return (0);
	}
	return (1);
}
