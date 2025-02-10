/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomont <lomont@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 03:42:07 by lomont            #+#    #+#             */
/*   Updated: 2025/02/11 00:10:09 by lomont           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "../minilibx/mlx42.h"
#include "../LIB_C/LIB_C.h"
#include <math.h>
#include <stdio.h>

typedef struct 	s_init
{
	char *map_name;
	int fd;
	char **tab;
}				t_init;


typedef struct	s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void close_window(mlx_key_data_t keydata, void* param);
bool check_extension_map(t_init *init_data);
void init_map(int argc, char **argv, t_init *init_data);
void init_fd(t_init *init_data);
void init_all(int argc, char **argv, t_init *init_data);
bool check_map_is_rectangular(t_init *init_data);
void fill_tab_map(t_init *init_data);
t_init *init_struct(void);
#endif
