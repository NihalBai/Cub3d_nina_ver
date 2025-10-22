/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaidaou <nbaidaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 17:30:53 by nbaidaou          #+#    #+#             */
/*   Updated: 2025/10/22 17:02:28 by nbaidaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int is_valid_cell(char c)
{
    /* Accept space as a valid map character (used in some map files as filler). */
    return (c == ' ' || c == '0' || c == '1' || c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

int is_walkable_cell(char c)
{
    return (c == '0' || c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

int is_closed_map(t_map *map)
{
    int i;
    int j;
    i = 0;
    while (i < map->height)
    {
        j = 0;
        while (j < map->width)
        {
            /* safe accessor: return ' ' for out-of-bounds horizontally */
            char cur = ' ';
            int row_len = map->map_grid[i] ? ft_strlen(map->map_grid[i]) : 0;
            if (j < row_len)
                cur = map->map_grid[i][j];
            if (is_walkable_cell(cur))
            {
                /* if on the outer border of the grid, it's not closed */
                if (i == 0 || i == map->height - 1 || j == 0 || j == map->width - 1)
                    return (0);
                /* check neighbors using safe access */
                char up = ' ';
                char down = ' ';
                char left = ' ';
                char right = ' ';
                int up_len = map->map_grid[i - 1] ? ft_strlen(map->map_grid[i - 1]) : 0;
                int down_len = map->map_grid[i + 1] ? ft_strlen(map->map_grid[i + 1]) : 0;
                int left_len = row_len;
                int right_len = row_len;
                if (j < up_len)
                    up = map->map_grid[i - 1][j];
                if (j < down_len)
                    down = map->map_grid[i + 1][j];
                if (j - 1 >= 0 && (j - 1) < left_len)
                    left = map->map_grid[i][j - 1];
                if (j + 1 < right_len)
                    right = map->map_grid[i][j + 1];
                /* if any neighbor is a space (meaning empty) or not a valid cell, map is open */
                if (up == ' ' || down == ' ' || left == ' ' || right == ' ' ||
                    !is_valid_cell(up) || !is_valid_cell(down) || !is_valid_cell(left) || !is_valid_cell(right))
                    return (0);
            }
            j++;
        }
        i++;
    }
    return (1);
}

int has_one_player(t_map *map)
{
    int i;
    int j;
    int player_count = 0;
    i = 0;
    while (i < map->height)
    {
        j = 0;
        while ( j < map->width)
        {
            if (map->map_grid[i][j] == 'N' || map->map_grid[i][j] == 'S' || 
                map->map_grid[i][j] == 'E' || map->map_grid[i][j] == 'W')
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

int is_valide_map(t_map *map)
{
    if (!check_all(map))
        return (0);
    if (!is_closed_map(map))
        return (0);
    if (!has_one_player(map))
        return (0);
    return (1);
}