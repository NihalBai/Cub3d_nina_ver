/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaidaou <nbaidaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 15:31:09 by nbaidaou          #+#    #+#             */
/*   Updated: 2025/09/22 18:16:36 by nbaidaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int init_data(t_data *data, char *file)
{
    int fd;

    data->mlx = NULL;
    data->win = NULL;
    if (ini_map(&data->map) == -1)
        return (-1);
    ini_map(&data->map);
    fd = open(file, O_RDONLY);
    if (fd == -1)
    {
        perror("Error opening file");
        return (-1);
    }
    if (!parsing(&data->map, fd))
    {
        close(fd);
        return (-1);
    }
    close(fd);
   if(!is_valide_map(&data->map))
       return (-1);
    if(!init_player(&data->player, &data->map))
        return (-1);
    return (1);
}

int ini_map(t_map *map)
{
    int i;

    map->map_grid = NULL;
    map->width = 0;
    map->height = 0;
    i = 0;
    while (i < 4)
    {
        map->textures[i].path = NULL;
        map->textures[i].img = NULL;
        map->textures[i].addr = NULL;
        map->textures[i].width = 0;
        map->textures[i].height = 0;
        i++;
    }
    map->floor_color = -1;
    map->ceiling_color = -1;
    return (1);
}

static void choose_player_dir(t_player *player, char dir)
{
        player->dir_x = (dir == 'E') - (dir == 'W');
        player->dir_y = (dir == 'S') - (dir == 'N');
        player->plane_x = (dir == 'S') * -0.66 + (dir == 'N') * 0.66;
        player->plane_y = (dir == 'E') * 0.66 + (dir == 'W') * -0.66;
}


int init_player(t_player *player, t_map *map)
{
    int i;
    int j;

    i = 0;
    while (i < map->height)
    {
        j = 0;
        while (j < map->width)
        {
            if(ft_strchr("NSEW", map->map_grid[i][j]))
            {
                player->x = j + 0.5;
                player->y = i + 0.5;
                choose_player_dir(player, map->map_grid[i][j]);
                return (1);
            }
            j++;
        }
        i++;
    }
    return (0);
}
