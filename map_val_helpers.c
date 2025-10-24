/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_val_helpers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaidaou <nbaidaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 11:45:23 by nbaidaou          #+#    #+#             */
/*   Updated: 2025/10/24 11:46:45 by nbaidaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	get_vertical_neighbors(t_map *map, int i, int j, t_neighbors *n)
{
	int	up_len;
	int	down_len;

	up_len = 0;
	if (map->map_grid[i - 1])
		up_len = ft_strlen(map->map_grid[i - 1]);
	down_len = 0;
	if (map->map_grid[i + 1])
		down_len = ft_strlen(map->map_grid[i + 1]);
	if (j < up_len)
		n->up = map->map_grid[i - 1][j];
	else
		n->up = ' ';
	if (j < down_len)
		n->down = map->map_grid[i + 1][j];
	else
		n->down = ' ';
}

void	get_horizontal_neighbors(t_map *map, int i, int j, t_neighbors *n)
{
	int	row_len;

	row_len = 0;
	if (map->map_grid[i])
		row_len = ft_strlen(map->map_grid[i]);
	if (j > 0 && j - 1 < row_len)
		n->left = map->map_grid[i][j - 1];
	else
		n->left = ' ';
	if (j + 1 < row_len)
		n->right = map->map_grid[i][j + 1];
	else
		n->right = ' ';
}

t_neighbors	get_neighbors(t_map *map, int i, int j)
{
	t_neighbors	n;

	get_vertical_neighbors(map, i, j, &n);
	get_horizontal_neighbors(map, i, j, &n);
	return (n);
}

int	check_cell(t_map *map, int i, int j)
{
	char		cur;
	t_neighbors	n;
	int			row_len;

	row_len = 0;
	if (map->map_grid[i])
		row_len = ft_strlen(map->map_grid[i]);
	if (j < row_len)
		cur = map->map_grid[i][j];
	else
		cur = ' ';
	if (!is_walkable_cell(cur))
		return (1);
	if (i == 0 || i == map->height - 1 || j == 0 || j == map->width - 1)
		return (0);
	n = get_neighbors(map, i, j);
	if (n.up == ' ' || n.down == ' ' || n.left == ' ' || n.right == ' ')
		return (0);
	if (!is_valid_cell(n.up) || !is_valid_cell(n.down) || !is_valid_cell(n.left)
		|| !is_valid_cell(n.right))
		return (0);
	return (1);
}
