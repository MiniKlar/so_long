/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomont <lomont@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 03:42:07 by lomont            #+#    #+#             */
/*   Updated: 2025/02/28 21:05:52 by lomont           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef SIZE
#  define SIZE 64
# endif

# ifndef BUFFER_MAP_MAX
#  define BUFFER_MAP_MAX 480
# endif

# include "../MLX42/mlx42.h"
# include "../LIB_C/LIB_C.h"
# include <math.h>
# include <stdio.h>

typedef struct s_C_info
{
	int		x;
	int		y;
	int		index;
	void	*next;
}				t_C_info;

typedef struct s_List
{
	t_C_info	*node;
}				t_C_list;

typedef struct s_init
{
	char	**flood_tab;
	char	**tab;
	char	*map_name;
	int		prev_mov_counter;
	int		fd;
	int		player_pos_x;
	int		player_pos_y;
	int		collectibles;
	int		items_collect;
	int		exit;
	int		start_position;
	int		n_collectibles;
	int		n_exit;
	int		x;
	int		y;
	int		x_max;
	int		y_max;
	int		item_counter;
	int		mov_counter;
	int		sprite_anim;
}				t_init;

typedef struct s_data
{
	mlx_image_t		*img_wall;
	mlx_image_t		*img_floor;
	mlx_image_t		*img_player;
	mlx_image_t		*img_player_right;
	mlx_image_t		*img_exit;
	mlx_image_t		*img_c4;
	mlx_image_t		*img_c4_red;
	mlx_image_t		*img_ct;
	mlx_image_t		*str_counter;
	mlx_texture_t	*c4;
	mlx_texture_t	*c4_red;
	mlx_texture_t	*wall;
	mlx_texture_t	*floor;
	mlx_texture_t	*player;
	mlx_texture_t	*player_right;
	mlx_texture_t	*exit;
	mlx_texture_t	*ct;
}				t_data;

typedef struct s_struct
{
	t_data		*data;
	mlx_t		*mlx;
	t_init		*init;
	t_C_list	*first_node;
}				t_struct;

t_init		*init_struct(void);
t_C_list	*initalisation(void);
t_data		*init_game_data(void);
t_struct	*init_structure(void);
t_struct	*init_ptr_to_struct(void);

bool		fill_tab(t_init *init_data);
bool		check_e_p_c(t_init *init_data);
bool		check_if_wall(char c);
bool		flood_fill_map(t_init *init_data);
bool		check_extension_map(t_init *init_data);
bool		check_map_empty_space(t_init *init_data);
bool		check_map_is_not_empty(t_init *init_data);
bool		check_map_only_charset(t_init *init_data);
bool		map_is_enclosed_by_wall(t_init *init_data);
bool		check_map_is_rectangular(t_init *init_data);
bool		check_rectangle_width(bool is_wall, char **tableau,
				int x, int x_max);
bool		check_rectangle_length(bool is_wall, char **tableau,
				int y, int y_max);

void		init_c4(t_struct *all_struct, int x, int y);
void		endgame(t_struct *all_struct, int i, int x, int y);
void		init_fd(t_init *init_data);
void		free_mlx(t_struct *all_struct);
void		init_all(int argc, char **argv, t_init *init_data);
void		free_all(void *param);
void		free_map(char **map);
void		print_map(char **map);
void		insertion(t_C_list *liste, int C_count, int x, int y);
void		free_list(t_C_list *liste);
void		move_sprite(t_struct *all_struct, int x);
void		free_struct(t_struct *all_struct);
void		key_handler(mlx_key_data_t keydata, void *param);
void		anime_sprite(void *param);
void		init_map_name(int argc, char **argv, t_init *init_data);
void		check_parsing(t_struct *all_struct);
void		put_floor_image(t_struct *all_struct);
void		check_parsing_alt(t_struct *all_struct);
void		check_all_parsing(t_struct *all_struct);
void		counter_to_window(t_struct *all_struct);
void		remove_items(t_struct *all_struct, int x, int y);
void		change_sprite(t_struct *all_struct);
void		move_player_up(t_struct *all_struct, char **tab, int x, int y);
void		move_player_down(t_struct *all_struct, char **tab, int x, int y);
void		move_player_left(t_struct *all_struct, char **tab, int x, int y);
void		move_player_right(t_struct *all_struct, char **tab, int x, int y);
void		init_texture_image(t_struct *all_struct);
void		change_sprite_right(t_struct *all_struct);
void		put_image_to_window(t_struct *all_struct);
void		check_collectibles_tab(t_init *init_data, char **tableau);
void		start_position_floodfill(t_init *init_data, char **tableau);
void		move_player(mlx_key_data_t keydata, t_struct *all_struct,
				int x, int y);
void		put_exit_items_image(t_struct *all_struct, char **tableau,
				int x, int y);

char		**flood(t_init *init_data, char **tableau, int x, int y);
char		**set_next_position_floodfill(char **tableau, t_init *init_data);

int			ft_ischarnum(int c);
int			ft_search_items_instances(t_struct *all_struct, int x, int y);

#endif
