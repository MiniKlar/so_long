/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomont <lomont@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 06:31:26 by lomont            #+#    #+#             */
/*   Updated: 2025/02/16 13:37:58 by lomont           ###   ########.fr       */
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
	all_struct->data->player = mlx_load_png("./src/img/player.png");
	all_struct->data->img_player = mlx_texture_to_image(all_struct->mlx,
			all_struct->data->player);
	all_struct->data->c4 = mlx_load_png("./src/img/C4_final_1.png");
	all_struct->data->img_c4 = mlx_texture_to_image(all_struct->mlx,
			all_struct->data->c4);
}
