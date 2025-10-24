/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaidaou <nbaidaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 17:30:53 by nbaidaou          #+#    #+#             */
/*   Updated: 2025/10/24 11:54:30 by nbaidaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	is_valid_cell(char c)
{
	return (c == ' ' || c == '0' || c == '1' || c == 'N' || c == 'S' || c == 'E'
		|| c == 'W');
}

int	is_walkable_cell(char c)
{
	return (c == '0' || c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

int	is_closed_map(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (!check_cell(map, i, j))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	has_one_player(t_map *map)
{
	int	i;
	int	j;
	int	player_count;

	player_count = 0;
	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->map_grid[i][j] == 'N' || map->map_grid[i][j] == 'S'
				|| map->map_grid[i][j] == 'E' || map->map_grid[i][j] == 'W')
			{
				player_count++;
				if (player_count > 1)
					return (0);
			}
			j++;
		}
		i++;
	}
	return (player_count == 1);
}

int	is_valide_map(t_map *map)
{
	if (!check_all(map))
		return (0);
	if (!is_closed_map(map))
		return (0);
	if (!has_one_player(map))
		return (0);
	return (1);
}
