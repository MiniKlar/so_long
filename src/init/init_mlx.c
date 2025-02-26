/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miniklar <miniklar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 06:31:26 by lomont            #+#    #+#             */
/*   Updated: 2025/02/26 14:06:04 by miniklar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	init_texture_image(t_struct *all_struct)
{
	all_struct->data->floor = mlx_load_png("./src/img/floor.png");
	all_struct->data->img_floor = mlx_texture_to_image(all_struct->mlx,
			all_struct->data->floor);
	all_struct->data->wall = mlx_load_png("./src/img/wall.png");
	all_struct->data->img_wall = mlx_texture_to_image(all_struct->mlx,
			all_struct->data->wall);
	all_struct->data->exit = mlx_load_png("./src/img/B.png");
	all_struct->data->img_exit = mlx_texture_to_image(all_struct->mlx,
			all_struct->data->exit);
	all_struct->data->player = mlx_load_png("./src/img/player_left.png");
	all_struct->data->img_player = mlx_texture_to_image(all_struct->mlx,
			all_struct->data->player);
	all_struct->data->player_right = mlx_load_png("./src/img/player_right.png");
	all_struct->data->img_player_right = mlx_texture_to_image(all_struct->mlx, all_struct->data->player_right);
	all_struct->data->c4 = mlx_load_png("./src/img/C4_final_red.png");
	all_struct->data->img_c4 = mlx_texture_to_image(all_struct->mlx,
			all_struct->data->c4);
}
