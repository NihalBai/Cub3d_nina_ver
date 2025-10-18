/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaidaou <nbaidaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 20:41:21 by nbaidaou          #+#    #+#             */
/*   Updated: 2025/10/18 21:04:59 by nbaidaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static int	get_wall_texture(t_data *data)
{
	if (data->ray.side_hit == 0)
	{
		if (data->ray.ray_x_dir > 0)
			return EA_TEX;
		return WE_TEX;
	}
	else
	{
		if (data->ray.ray_y_dir > 0)
			return SO_TEX;
		return NO_TEX;
	}
}


void	draw_walls(t_data *data, int x)
{
}