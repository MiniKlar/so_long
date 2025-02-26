/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_sprite.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomont <lomont@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 02:56:35 by lomont            #+#    #+#             */
/*   Updated: 2025/02/26 03:37:02 by lomont           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	change_sprite(t_struct *all_struct)
{
	int x;
	int y;
	int z;

	all_struct->init->mov_counter++;
	x = all_struct->data->img_player->instances->x;
	y = all_struct->data->img_player->instances->y;
	z = all_struct->data->img_player->instances->z;
	mlx_delete_image(all_struct->mlx, all_struct->data->img_player);
	all_struct->data->img_player = mlx_texture_to_image(all_struct->mlx,
		all_struct->data->player);
	mlx_set_instance_depth(all_struct->data->img_player->instances,
			3);
	all_struct->data->img_player->instances->x = x;
	all_struct->data->img_player->instances->x = y;
	all_struct->data->img_player->instances->x = z;
}

void	change_sprite_right(t_struct *all_struct)
{
	int x;
	int y;
	int z;

	all_struct->init->mov_counter++;
	x = all_struct->data->img_player->instances->x;
	y = all_struct->data->img_player->instances->y;
	z = all_struct->data->img_player->instances->z;
	mlx_delete_image(all_struct->mlx, all_struct->data->img_player);
	all_struct->data->img_player = mlx_texture_to_image(all_struct->mlx,
		all_struct->data->player_right);
	//mlx_set_instance_depth(all_struct->data->img_player->instances,
			//3);
	//all_struct->data->img_player->instances->x = x;
	//all_struct->data->img_player->instances->x = y;
	//all_struct->data->img_player->instances->x = z;
}
