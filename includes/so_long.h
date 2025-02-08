/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomont <lomont@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 03:42:07 by lomont            #+#    #+#             */
/*   Updated: 2025/02/08 20:16:21 by lomont           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "../minilibx/mlx42.h"
#include "../LIB_C/LIB_C.h"
#include <math.h>
#include <stdio.h>

typedef struct	s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void close_window(mlx_key_data_t keydata, void* param);
bool check_extension_map(int argc, char **argv, int fd);
int init_map(int argc, char **argv);
bool check_map_is_rectangular(int fd);
char **fill_tab_map(int fd);
#endif