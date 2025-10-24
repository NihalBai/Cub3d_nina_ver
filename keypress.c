/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaidaou <nbaidaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 15:58:42 by nbaidaou          #+#    #+#             */
/*   Updated: 2025/10/24 11:50:25 by nbaidaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	move_forward(t_data *data)
{
	double	new_x;
	double	new_y;

	new_x = data->player.x + data->player.dir_x * STEP_SIZE;
	new_y = data->player.y + data->player.dir_y * STEP_SIZE;
	if (new_x >= 0 && new_y >= 0 && new_x < data->map.width
		&& new_y < data->map.height
		&& is_walkable_cell(data->map.map_grid[(int)new_y][(int)new_x]))
	{
		data->player.x = new_x;
		data->player.y = new_y;
	}
}

void	move_backward(t_data *data)
{
	double	new_x;
	double	new_y;

	new_x = data->player.x - data->player.dir_x * STEP_SIZE;
	new_y = data->player.y - data->player.dir_y * STEP_SIZE;
	if (new_x >= 0 && new_y >= 0 && new_x < data->map.width
		&& new_y < data->map.height
		&& is_walkable_cell(data->map.map_grid[(int)new_y][(int)new_x]))
	{
		data->player.x = new_x;
		data->player.y = new_y;
	}
}

void	strafe_left(t_data *data)
{
	double	new_x;
	double	new_y;

	new_x = data->player.x + (-data->player.dir_y) * STEP_SIZE;
	new_y = data->player.y + (data->player.dir_x) * STEP_SIZE;
	if (new_x >= 0 && new_y >= 0 && new_x < data->map.width
		&& new_y < data->map.height
		&& is_walkable_cell(data->map.map_grid[(int)new_y][(int)new_x]))
	{
		data->player.x = new_x;
		data->player.y = new_y;
	}
}

void	strafe_right(t_data *data)
{
	double	new_x;
	double	new_y;

	new_x = data->player.x + (data->player.dir_y) * STEP_SIZE;
	new_y = data->player.y + (-data->player.dir_x) * STEP_SIZE;
	if (new_x >= 0 && new_y >= 0 && new_x < data->map.width
		&& new_y < data->map.height
		&& is_walkable_cell(data->map.map_grid[(int)new_y][(int)new_x]))
	{
		data->player.x = new_x;
		data->player.y = new_y;
	}
}

int	handle_keypress(int keycode, t_data *data)
{
	if (keycode == KEY_ESC)
		free_all(data, NULL, 0);
	else if (keycode == KEY_W)
		move_forward(data);
	else if (keycode == KEY_S)
		move_backward(data);
	else if (keycode == KEY_A)
		strafe_left(data);
	else if (keycode == KEY_D)
		strafe_right(data);
	else if (keycode == KEY_LEFT)
		rotate_left(data);
	else if (keycode == KEY_RIGHT)
		rotate_right(data);
	return (0);
}
