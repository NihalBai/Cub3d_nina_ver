/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaidaou <nbaidaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 15:30:18 by nbaidaou          #+#    #+#             */
/*   Updated: 2025/09/22 18:14:55 by nbaidaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
#define CUB_H   

# include "get_next_line/get_next_line.h"
// # include <mlx.h>
# include "libft/libft.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_texture
{
    void    *img;
    char    *path;
    char    *addr;
    int     width;
    int     height;
    int     bits_per_pixel;
    int     line_length;
    int     endian;
}               t_texture;

typedef struct s_map
{
   char **map_grid;
    int width;
    int height;
   t_texture textures[4];
    int floor_color;
    int ceiling_color;
}               t_map;

typedef struct s_player
{
    double x;
    double y;
    double dir_x;
    double dir_y;
    double plane_x;
    double plane_y;
}               t_player;

typedef struct s_data
{
    void    *mlx;
    void    *win;
    t_map   map;
    t_player player;
}               t_data;

// Parsing functions
int parsing(t_map *map, char *filename);
int pars_textures(t_map *map, char *line);
int parse_colors(t_map *map, char *line);
int parse_map(t_map *map, char *line);
int  safe_malloc(void **ptr, size_t size);
int check_and_free(char *str);
void free_split(char **split);
int pars_color(char *str);
int is_map_line(char *line);
int check_all(t_map *map);

// Helper functions
int is_empty_line(char *line);

// Map validation functions
int is_valid_cell(char c);
int is_walkable_cell(char c);
int is_closed_map(t_map *map);
int has_one_player(t_map *map);
int is_valide_map(t_map *map);

// Initialization functions
int init_data(t_data *data, char *file);
int ini_map(t_map *map);
int init_player(t_player *player, t_map *map);
#endif