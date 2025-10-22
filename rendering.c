/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaidaou <nbaidaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 16:35:22 by nbaidaou          #+#    #+#             */
/*   Updated: 2025/10/22 17:02:28 by nbaidaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void draw_floor_ceiling(t_data *data)
{
    int x;
    int y;

    y=0;
    while (y < WIN_H)
    {
       x =0;
       while (x < WIN_W)
       {
        if(y < WIN_H/2)
            my_pixel_put(&data->img,x,y,data->map.ceiling_color);
        else
            my_pixel_put(&data->img,x,y,data->map.floor_color);
        x++;
       }
       y++;
    } 
}

int render_frame(t_data * data)
{
    draw_floor_ceiling(data);
    ray_casting(data);
    mlx_put_image_to_window(data->mlx,data->win,data->img.img,0,0);
    return 0;
}