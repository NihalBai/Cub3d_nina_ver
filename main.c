/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaidaou <nbaidaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 15:30:47 by nbaidaou          #+#    #+#             */
/*   Updated: 2025/10/24 10:05:31 by nbaidaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	check_input(int ac, char **av)
{
	if (ac != 2)
	{
		printf("Usage: %s map.cub\n", av[0]);
		return (0);
	}
	if (ft_strlen(av[1]) < 4 || ft_strncmp(av[1] + ft_strlen(av[1]) - 4, ".cub",
			4) != 0)
	{
		printf("Error: Invalid file extension. Expected a .cub file.\n");
		return (0);
	}
	return (1);
}

int	handle_close(t_data *data)
{
	free_all(data, NULL, 0);
	return (0);
}
int	main(int ac, char **av)
{
	t_data	data;

	if (!check_input(ac, av))
		return (1);
	if (!init_data(&data, av[1]))
	{
		printf("Error: Initialization failed.\n");
		return (1);
	}
	if (!init_window(&data))
	{
		free_map(&data);
		printf("Error: Window initialization failed.\n");
		return (1);
	}
	if (!load_textures(&data))
	{
		free_all(&data, "Error : Failed to load textures", 1);
		return (1);
	}
	mlx_hook(data.win, 2, 1 << 0, handle_keypress, &data);
	mlx_hook(data.win, 17, 1L << 17, handle_close, &data);
	mlx_loop_hook(data.mlx, render_frame, &data);
	mlx_loop(data.mlx);
	return (0);
}
