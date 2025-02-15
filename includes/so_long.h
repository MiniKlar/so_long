/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomont <lomont@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 03:42:07 by lomont            #+#    #+#             */
/*   Updated: 2025/02/15 06:57:35 by lomont           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#define SIZE 64

#include "../minilibx/mlx42.h"
#include "../LIB_C/LIB_C.h"
#include <math.h>
#include <stdio.h>


typedef struct 	s_init
{
	char *map_name;
	int fd;
	char **tab;
	char **flood_tab;
	int player_pos_x;
	int player_pos_y;
	int collectibles;
	int finish_collectibles;
	int exit;
	int start_position;
	int N_collectibles;
	int N_exit;
	int x;
	int y;
	int x_max;
	int y_max;
}				t_init;


typedef struct	s_data
{
	mlx_image_t *img_wall;
	mlx_image_t *img_floor;
	mlx_image_t *img_player;
	mlx_image_t *img_exit;
	mlx_image_t *img_C4;
	mlx_texture_t *C4;
	mlx_texture_t *wall;
	mlx_texture_t *floor;
	mlx_texture_t *player;
	mlx_texture_t *exit;
	//void	*img;
	//char	*addr;
	//int		bits_per_pixel;
	//int		line_length;
	//int		endian;
}				t_data;

typedef struct	s_struct
{
	t_data *struct_data;
	mlx_t *mlx;
	t_init *struct_init;
}				t_struct;

void close_window(mlx_key_data_t keydata, mlx_t* param);
bool check_extension_map(t_init *init_data);
void init_map(int argc, char **argv, t_init *init_data);
void init_fd(t_init *init_data);
void init_all(int argc, char **argv, t_init *init_data);
bool check_map_is_rectangular(t_init *init_data);
bool check_map_is_not_empty(t_init *init_data);
t_init *init_struct(void);
void fill_tab(t_init *init_data);
void	print_map(char **map);
void	free_map(char **map);
void free_struct(t_struct *all_struct);
bool check_map_only_charset(t_init *init_data);
bool map_is_enclosed_by_wall(t_init *init_data, int x_max, int y_max);
bool check_if_wall(char c);
bool check_E_P_C(t_init *init_data);
bool flood_fill_map(t_init *init_data);
char **flood(t_init *init_data,char **tableau, int x, int y);
char **set_next_position_floodfill(char **tableau, t_init *init_data);
void start_position_floodfill(t_init *init_data, char **tableau);
int	ft_ischarnum(int c);
void check_collectibles_tab(t_init *init_data ,char **tableau);
bool check_rectangle_width(bool is_wall, char **tableau, int x, int y, int x_max);
bool check_rectangle_length(bool is_wall, char **tableau, int x, int y, int y_max);
void check_parsing_alt(t_init *init_data);
void check_parsing(t_init *init_data);
void check_all_parsing(t_init *init_data);
t_data *init_game_data(void);
void key_handler(mlx_key_data_t keydata, void* param);
t_struct *init_ptr_to_struct();
void move_player(mlx_key_data_t keydata, t_struct *all_struct, int x, int y);
void free_mlx(t_struct *all_struct);
void free_parsing(t_init *init_data);
void free_all(void *param);

#endif
