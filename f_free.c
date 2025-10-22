/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_free.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaidaou <nbaidaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 15:32:40 by nbaidaou          #+#    #+#             */
/*   Updated: 2025/10/22 13:54:42 by nbaidaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void free_map(t_data *data)
{
    int i;

    if (data->map.map_grid)
    {
        i = 0;
        while (i < data->map.height)
        {
            free(data->map.map_grid[i]);
            i++;
        }
        free(data->map.map_grid);
    }
    i = 0;
    while (i < 4)
    {
        if (data->map.textures[i].path)
            free(data->map.textures[i].path);
        i++;
    }
}

void destroy_textures(t_data *data)
{
    int i;

    i =0;
    while (i < 4)
    {
        if (data->map.textures[i].img)
            mlx_destroy_image(data->mlx, data->map.textures[i].img);
        i++;
    }
}

void free_all(t_data *data,char * msg,int ex)
{
    if(msg)
        printf("%s\n",msg);
    destroy_textures(data);
    if (data->mlx && data->win)
        mlx_destroy_window(data->mlx, data->win);
    if (data->mlx)
    {
        mlx_destroy_display(data->mlx);
        free(data->mlx);
    }
    free_map(data);
    exit(ex);
}