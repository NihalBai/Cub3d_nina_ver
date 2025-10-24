/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaidaou <nbaidaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 20:41:21 by nbaidaou          #+#    #+#             */
/*   Updated: 2025/10/24 11:52:20 by nbaidaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static int	get_wall_texture(t_data *data)
{
	if (data->ray.side_hit == X_SIDE)
	{
		if (data->ray.ray_x_dir > 0)
			return (EA_TEX);
		return (WE_TEX);
	}
	else
	{
		if (data->ray.ray_y_dir > 0)
			return (SO_TEX);
		return (NO_TEX);
	}
}

void	calculate_tex_coordinates(t_data *data, t_ray *r, int tx_num)
{
	t_texture	*tx;

	tx = &data->map.textures[tx_num];
	if (r->side_hit == X_SIDE)
		r->wall_x_pos = data->player.y + r->wall_dist * r->ray_y_dir;
	else
		r->wall_x_pos = data->player.x + r->wall_dist * r->ray_x_dir;
	r->wall_x_pos -= floor(r->wall_x_pos);
	r->tex_x = (int)(r->wall_x_pos * tx->width);
	if (r->tex_x < 0)
		r->tex_x = 0;
	if (r->tex_x >= tx->width)
		r->tex_x = tx->width - 1;
	if ((r->side_hit == X_SIDE && r->ray_x_dir > 0) || (r->side_hit == Y_SIDE
			&& r->ray_y_dir < 0))
		r->tex_x = tx->width - r->tex_x - 1;
	r->step_size = (double)tx->height / (double)r->line_height_wall;
	r->tex_pos = (r->draw_pos_start - (double)WIN_H / 2
			+ (double)r->line_height_wall / 2) * r->step_size;
}

int	get_texture_color(t_texture *tex, int x, int y)
{
	char	*pixel;

	if (!tex->addr || x < 0 || x >= tex->width || y < 0 || y >= tex->height)
		return (0);
	pixel = tex->addr + (y * tex->line_length + x * (tex->bits_per_pixel / 8));
	return (*(unsigned int *)pixel);
}

void	draw_walls(t_data *data, int x)
{
	int			i;
	int			color;
	int			tx_num;
	int			p_tx;
	t_texture	*tx;

	tx_num = get_wall_texture(data);
	tx = &data->map.textures[tx_num];
	calculate_tex_coordinates(data, &data->ray, tx_num);
	i = data->ray.draw_pos_start;
	while (i <= data->ray.draw_pos_end)
	{
		p_tx = (int)data->ray.tex_pos;
		if (p_tx >= tx->height)
			p_tx = p_tx % tx->height;
		else if (p_tx < 0)
			p_tx = 0;
		color = get_texture_color(tx, data->ray.tex_x, p_tx);
		my_pixel_put(&data->img, x, i, color);
		data->ray.tex_pos += data->ray.step_size;
		i++;
	}
}
