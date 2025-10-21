/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaidaou <nbaidaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 15:30:18 by nbaidaou          #+#    #+#             */
/*   Updated: 2025/10/21 11:40:58 by nbaidaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
#define CUB_H   

# include "get_next_line/get_next_line.h"
# include "/home/nbaidaou/Documents/minilibx-linux-master/mlx.h"
# include "libft/libft.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# define WIN_W 1024
# define WIN_H 768

# define KEY_W 119
# define KEY_A 100
# define KEY_S 115
# define KEY_D 97
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_ESC 65307

# define STEP_SIZE 0.05
# define ROT_SPEED 0.03

# define INFINI 1e30

# define X_SIDE 0
# define Y_SIDE 1

# define EA_TEX 1
# define WE_TEX 2
# define SO_TEX 3
# define NO_TEX 4

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

typedef struct s_img
{
    void    *img;
    char    *addr;
    int     width;
    int     bits_per_pixel;
    int     line_length;
    int     endian;
}               t_img;

typedef struct s_ray
{
    double camera_x;
    double ray_x_dir;
    double ray_y_dir;
    int     current_map_x; 
    int     current_map_y; 
    double delta_dist_x;
    double delta_dist_y;
    int hit;
    int side_hit;
    int step_x;
    int step_y;
    double  side_dist_x;  
    double  side_dist_y; 
    double wall_dist;
    int line_height_wall;
    int draw_pos_start;
    int draw_pos_end;
    double  wall_x_pos;         
    int     tex_x;       
    int     tex_y; 
    double   step_size; 
    double  tex_pos;
    
}t_ray;

typedef struct s_data
{
    void    *mlx;
    void    *win;
    t_map   map;
    t_player player;
    t_img   img;
    t_ray   ray;
}               t_data;

// Parsing functions
int parsing(t_map *map, int fd);
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
int init_window(t_data *data);

// Load_textures
int load_textues(t_data *data);

// free 
void free_map(t_data *data);
void free_all(t_data *data,char *msg,int ex);
void destroy_textures(t_data *data);

// keypress
int handle_keypress(int key_code,t_data * data);
void rotate_left(t_data * data);
void rotate_right(t_data * data);
// rendering
int render_frame(t_data * data);
void	my_pixel_put(t_img *img, int x, int y, int color);

// ray_casting
void ray_casting(t_data *data);

// drawing
void	draw_walls(t_data *data, int x);
#endif