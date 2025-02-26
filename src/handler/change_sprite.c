/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_sprite.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miniklar <miniklar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 02:56:35 by lomont            #+#    #+#             */
/*   Updated: 2025/02/26 14:58:45 by miniklar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	change_sprite(t_struct *all_struct)
{
	int x;
	int y;
	int z;

	all_struct->init->mov_counter++;
	if (all_struct->data->img_player->instances->enabled == false)
	{
		all_struct->data->img_player_right->instances->enabled = false;
		x = all_struct->data->img_player_right->instances->x;
		y = all_struct->data->img_player_right->instances->y;
		z = all_struct->data->img_player_right->instances->z;
		all_struct->data->img_player->instances->x = x;
		all_struct->data->img_player->instances->x = y;
		all_struct->data->img_player->instances->x = z;
		all_struct->data->img_player->instances->enabled = true;
	}
}

void	change_sprite_right(t_struct *all_struct)
{
	int x;
	int y;
	int z;

	all_struct->init->mov_counter++;
	if (all_struct->data->img_player_right->instances->enabled == false)
	{
		x = all_struct->data->img_player->instances->x;
		y = all_struct->data->img_player->instances->y;
		z = all_struct->data->img_player->instances->z;
		all_struct->data->img_player->instances->enabled = false;
		all_struct->data->img_player_right->instances->x = x;
		all_struct->data->img_player_right->instances->x = y;
		all_struct->data->img_player_right->instances->x = z;
		all_struct->data->img_player_right->instances->enabled = true;
	}
}
