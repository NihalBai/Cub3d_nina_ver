/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaidaou <nbaidaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 15:36:33 by nbaidaou          #+#    #+#             */
/*   Updated: 2025/10/24 12:00:11 by nbaidaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	load_textures(t_data *data)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		data->map.textures[i].img = mlx_xpm_file_to_image(data->mlx,
				data->map.textures[i].path, &data->map.textures[i].width,
				&data->map.textures[i].height);
		if (!data->map.textures[i].img)
		{
			destroy_textures(data, i - 1);
			return (0);
		}
		data->map.textures[i].addr = mlx_get_data_addr(
				data->map.textures[i].img,
				&data->map.textures[i].bits_per_pixel,
				&data->map.textures[i].line_length,
				&data->map.textures[i].endian);
		i++;
	}
	return (1);
}
