#include "cub.h"

int	pars_textures(t_map *map, char *line)
{
	char	*t;
	int		id;

	id = -1;
	// Match texture indices with your header defines
	// EA_TEX 1 -> index 0, WE_TEX 2 -> index 1, SO_TEX 3 -> index 2, NO_TEX 4 -> index 3
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
		/* If this row is longer than previous width, we need to extend all earlier rows
		   to the new width by padding with '1' so the map stays rectangular/closed. */
		return (0);
	map->textures[id].path = t;
	return (1);
}

int parse_colors(t_map *map, char *line)
{
    char *trim_line;
    char *tr;
    int color;
    int is_floor = -1;

    if (!line)
        return 0;

    trim_line = ft_strtrim(line, " \t\n");
    if (!trim_line)
        return 0;

    if (ft_strncmp(trim_line, "F ", 2) == 0)
        is_floor = 1;
    else if (ft_strncmp(trim_line, "C ", 2) == 0)
        is_floor = 0;
    else
    {
        free(trim_line);
        return 0;
    }

    if ((is_floor && map->floor_color != -1) ||
        (!is_floor && map->ceiling_color != -1))
    {
        free(trim_line);
        return 0;
    }

    tr = ft_strtrim(trim_line + 2, " \t\n");
    free(trim_line);
    if (!tr)
        return 0;

    color = pars_color(tr);
    free(tr);
    if (color < 0)
        return 0;

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
	if (!new_grid[i])
	{
		free(new_grid);
		return (0);
	}
	len = ft_strlen(new_grid[i]);
	/* If this row is longer than previous width, extend earlier rows */
	if (len > map->width)
	{
	int r;

		map->width = len;
		r = 0;
		while (r < map->height)
		{
			int cur_len = ft_strlen(new_grid[r]);
			if (cur_len < map->width)
			{
				char *padded = malloc(map->width + 1);
				if (!padded)
				{
					free(new_grid);
					return (0);
				}
				ft_memcpy(padded, new_grid[r], cur_len);
				ft_memset(padded + cur_len, '1', map->width - cur_len);
				padded[map->width] = '\0';
				free(new_grid[r]);
				new_grid[r] = padded;
			}
			r++;
		}
	}
	else if (len < map->width)
	{
		/* pad this new row to current map width with '1's */
		char *padded = malloc(map->width + 1);
		if (!padded)
		{
			free(new_grid);
			return (0);
		}
		ft_memcpy(padded, new_grid[i], len);
		ft_memset(padded + len, '1', map->width - len);
		padded[map->width] = '\0';
		free(new_grid[i]);
		new_grid[i] = padded;
		len = map->width;
	}
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