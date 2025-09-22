/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaidaou <nbaidaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 17:03:42 by nbaidaou          #+#    #+#             */
/*   Updated: 2025/09/22 17:04:17 by nbaidaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static int handle_before_map(t_map *map, char *line)
{
    if (is_empty_line(line))
        return (1);
    if (pars_textures(map, line) || parse_colors(map, line))
        return (1);
    return (0);
}

static int handle_map_line(t_map *map, char *line)
{
    if (!parse_map(map, line))
        return (0);
    return (1);
}

int parsing(t_map *map, int fd)
{
    char *line;
    int map_started = 0;

    while ((line = get_next_line(fd)))
    {
        if (!map_started && handle_before_map(map, line))
            ;
        else if (is_map_line(line))
        {
            map_started = 1;
            if (!handle_map_line(map, line))
                return (free(line), -1);
        }
        else if (map_started && !is_empty_line(line))
            return (free(line), -1);
        free(line);
    }
    return check_all(map);
}
