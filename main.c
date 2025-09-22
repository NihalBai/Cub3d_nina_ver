/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaidaou <nbaidaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 15:30:47 by nbaidaou          #+#    #+#             */
/*   Updated: 2025/09/22 18:17:29 by nbaidaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
int check_input(int ac, char **av)
{
    if (ac != 2)
    {
        printf("Error: Invalid number of arguments.\n");
        return (0);
    }
    if (ft_strlen(av[1]) < 4 || ft_strncmp(av[1] + ft_strlen(av[1]) - 4, ".cub", 4) != 0)
    {
        printf("Error: Invalid file extension. Expected a .cub file.\n");
        return (0);
    }
    return (1);
}
int main(int ac, char **av)
{
    t_data data;

    if (!check_input(ac, av))
        return (1);
    if(!init_data(&data, av[1]))
    {
        printf("Error: Initialization failed.\n");
        return (1);
    }
    return 0;
}
