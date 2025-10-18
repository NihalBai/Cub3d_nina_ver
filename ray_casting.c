/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaidaou <nbaidaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 13:51:03 by nbaidaou          #+#    #+#             */
/*   Updated: 2025/10/18 15:09:09 by nbaidaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	init_ray(t_data *data, t_ray *ray, int x)
{
	ray->camera_x = 2 * x / (double)WIN_W - 1;
	ray->ray_x_dir = data->player.dir_x + data->player.plane_x * ray->camera_x;
	ray->ray_y_dir = data->player.dir_y + data->player.plane_y * ray->camera_x;
	ray->current_map_x = (int)data->player.x;
	ray->current_map_y = (int)data->player.y;
	if (ray->ray_x_dir == 0)
		ray->delta_dist_x = INFINI;
	else
		ray->delta_dist_x = fabs(1 / ray->ray_x_dir);
	if (ray->ray_x_dir == 0)
		ray->delta_dist_y = INFINI;
	else
		ray->delta_dist_y = fabs(1 / ray->ray_y_dir);
	ray->hit = 0;
}
void steps_dir_init_side_dis(t_data* data,t_ray * ray)
{
    if (ray->ray_x_dir < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (data->player.x - ray->current_map_x) * ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->current_map_x + 1.0 - data->player.x) * ray->delta_dist_x;
	}
	if (ray->ray_y_dir < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (data->player.y - ray->current_map_y) * ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->current_map_y + 1.0 - data->player.y) * ray->delta_dist_y;
	}
}

void wall_height(t_data *data,t_ray *r)
{
    if (r->side_hit == 0)
        r->wall_dist = (r->current_map_x - data->player.x + (1-r->step_x)/2) / r->ray_x_dir;
    else r->wall_dist = (r->current_map_y - data->player.y + (1-r->step_y)/2) / r->ray_y_dir;
    
}

void	ray_casting(t_data *data)
{
	int x;
	t_ray r;

	x = 0;
	while (x < WIN_W)
	{
		init_ray(data, &r, x);
        steps_dir_init_side_dis(data,&r);
        wall_height(data,&r);
	}
}