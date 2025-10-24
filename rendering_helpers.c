/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_helpers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaidaou <nbaidaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 16:50:44 by nbaidaou          #+#    #+#             */
/*   Updated: 2025/10/24 11:39:59 by nbaidaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	my_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= WIN_W || y < 0 || y >= WIN_H)
		return ;
	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	floor_or_ceilling(t_map *map, int i, int color)
{
	if (i)
		map->floor_color = color;
	else
		map->ceiling_color = color;
}
