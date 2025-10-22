/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaidaou <nbaidaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 13:51:03 by nbaidaou          #+#    #+#             */
/*   Updated: 2025/10/22 16:56:46 by nbaidaou         ###   ########.fr       */
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
	if (ray->ray_y_dir == 0)
		ray->delta_dist_y = INFINI;
	else
		ray->delta_dist_y = fabs(1 / ray->ray_y_dir);
	ray->hit = 0;
}
void	steps_dir_init_side_dis(t_data *data, t_ray *ray)
{
	if (ray->ray_x_dir < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (data->player.x - ray->current_map_x)
			* ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->current_map_x + 1.0 - data->player.x)
			* ray->delta_dist_x;
	}
	if (ray->ray_y_dir < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (data->player.y - ray->current_map_y)
			* ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->current_map_y + 1.0 - data->player.y)
			* ray->delta_dist_y;
	}
}

void	wall_height(t_data *data, t_ray *r)
{
	if (r->side_hit == X_SIDE)
		r->wall_dist = (r->current_map_x - data->player.x + (1 - r->step_x) / 2)
			/ r->ray_x_dir;
	else
		r->wall_dist = (r->current_map_y - data->player.y + (1 - r->step_y) / 2)
			/ r->ray_y_dir;
	r->line_height_wall = (int)(WIN_H / r->wall_dist);
	r->draw_pos_start = -r->line_height_wall / 2 + WIN_H / 2;
	if (r->draw_pos_start < 0)
		r->draw_pos_start = 0;
	r->draw_pos_end = r->line_height_wall / 2 + WIN_H / 2;
	if (r->draw_pos_end >= WIN_H)
		r->draw_pos_end = WIN_H - 1;
}

void dda(t_data *data ,t_ray *r)
{
	while (r->hit ==0)
	{
		if (r->side_dist_x < r->side_dist_y)
		{
			r->side_dist_x += r->delta_dist_x;
			r->current_map_x +=r->step_x;
			r->side_hit = X_SIDE;
		}
		else
		{
			r->side_dist_y += r->delta_dist_y;
			r->current_map_y +=r->step_y;
			r->side_hit = Y_SIDE;
		}
		/* safe bounds check and correct indexing: map_grid[row][col] -> [y][x] */
		if (r->current_map_y < 0 || r->current_map_y >= data->map.height ||
			r->current_map_x < 0 || r->current_map_x >= data->map.width)
		{
			/* treat out-of-bounds as a wall to stop the ray */
			r->hit = 1;
			break;
		}
		char cell = data->map.map_grid[r->current_map_y][r->current_map_x];
		if (cell == '1')
			r->hit = 1;
	}
}

void	ray_casting(t_data *data)
{
	int x;
	t_ray r;

	x = 0;
	while (x < WIN_W)
	{
		init_ray(data, &r, x);
		steps_dir_init_side_dis(data, &r);
		dda(data,&r);
		wall_height(data, &r);
		data->ray = r;
		draw_walls(data,x);
		x++;
	}
}