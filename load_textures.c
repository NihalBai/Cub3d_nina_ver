/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaidaou <nbaidaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 15:36:33 by nbaidaou          #+#    #+#             */
/*   Updated: 2025/10/22 16:27:15 by nbaidaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	load_textues(t_data *data)
{
	int i;

	i = 0;
	while (i < 4)
	{
		char *path = data->map.textures[i].path;
		int w = 0, h = 0;
		void *img = NULL;
		int bpp = 0, line_len = 0, endian = 0;

		/* If path missing, or XPM fails, create a small fallback image so the
		   engine can continue. */
		if (!path)
		{
			printf("no tex num %d, creating fallback\n", i);
		}
		else
			printf("path %d : %s\n", i, path);

		img = mlx_xpm_file_to_image(data->mlx, path, &w, &h);

		if (!img)
		{
			printf("Failed to load texture %d from '%s', using fallback\n", i, path ? path : "(null)");
			w = 64;
			h = 64;
			img = mlx_new_image(data->mlx, w, h);
			if (!img)
				return (0);
			data->map.textures[i].img = img;
			data->map.textures[i].width = w;
			data->map.textures[i].height = h;
			data->map.textures[i].addr = mlx_get_data_addr(img, &bpp, &line_len, &endian);
			/* fill fallback image with a visible color */
			unsigned int color = (i == 0) ? 0xFF0000 : (i == 1) ? 0x00FF00 : (i == 2) ? 0x0000FF : 0xFFFF00;
			for (int yy = 0; yy < h; yy++)
			{
				char *pixel = data->map.textures[i].addr + yy * line_len;
				for (int xx = 0; xx < w; xx++)
				{
					*(unsigned int *)pixel = color;
					pixel += (bpp / 8);
				}
			}
		}
		else
		{
			/* Successfully loaded XPM */
			data->map.textures[i].img = img;
			data->map.textures[i].width = w;
			data->map.textures[i].height = h;
			data->map.textures[i].addr = mlx_get_data_addr(img, &bpp, &line_len, &endian);
		}
		data->map.textures[i].bits_per_pixel = bpp;
		data->map.textures[i].line_length = line_len;
		data->map.textures[i].endian = endian;
		i++;
	}
	return (1);
}