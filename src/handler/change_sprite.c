/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_sprite.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomont <lomont@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 02:56:35 by lomont            #+#    #+#             */
/*   Updated: 2025/02/28 20:07:09 by lomont           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	change_sprite(t_struct *all_struct)
{
	int	x;
	int	y;
	int	z;

	all_struct->init->mov_counter++;
	if (all_struct->data->img_player->instances->enabled == false)
	{
		x = all_struct->data->img_player_right->instances->x;
		y = all_struct->data->img_player_right->instances->y;
		z = all_struct->data->img_player_right->instances->z;
		all_struct->data->img_player_right->instances->enabled = false;
		all_struct->data->img_player->instances->x = x;
		all_struct->data->img_player->instances->y = y;
		all_struct->data->img_player->instances->z = z;
		all_struct->data->img_player->instances->enabled = true;
	}
	all_struct->data->img_player->instances->x -= SIZE;
	all_struct->init->player_pos_y -= 1;
}

void	change_sprite_right(t_struct *all_struct)
{
	int	x;
	int	y;
	int	z;

	all_struct->init->mov_counter++;
	if (all_struct->data->img_player_right->instances->enabled == false)
	{
		x = all_struct->data->img_player->instances->x;
		y = all_struct->data->img_player->instances->y;
		z = all_struct->data->img_player->instances->z;
		all_struct->data->img_player->instances->enabled = false;
		all_struct->data->img_player_right->instances->x = x;
		all_struct->data->img_player_right->instances->y = y;
		all_struct->data->img_player_right->instances->z = z;
		all_struct->data->img_player_right->instances->enabled = true;
	}
	all_struct->data->img_player_right->instances->x += SIZE;
	all_struct->init->player_pos_y += 1;
}

void	move_sprite(t_struct *all_struct, int x)
{
	if (all_struct->data->img_player->instances->enabled == true && x == 1)
	{
		all_struct->init->player_pos_x += 1;
		all_struct->data->img_player->instances->y += SIZE;
	}
	if (all_struct->data->img_player->instances->enabled == false && x == 1)
	{
		all_struct->init->player_pos_x += 1;
		all_struct->data->img_player_right->instances->y += SIZE;
	}
	if (all_struct->data->img_player->instances->enabled == true && x == -1)
	{
		all_struct->init->player_pos_x -= 1;
		all_struct->data->img_player->instances->y -= SIZE;
	}
	if (all_struct->data->img_player->instances->enabled == false && x == -1)
	{
		all_struct->init->player_pos_x -= 1;
		all_struct->data->img_player_right->instances->y -= SIZE;
	}
	all_struct->init->mov_counter++;
}

void	anime_sprite(void *param)
{
	t_struct	*struct_all;
	int			i;

	i = 0;
	struct_all = (t_struct *) param;
	if (struct_all->init->sprite_anim < 60)
		struct_all->init->sprite_anim += 1;
	else
	{
		struct_all->init->sprite_anim = 0;
		while (i != struct_all->init->collectibles)
		{
			struct_all->data->img_c4->instances[i].enabled = !(struct_all->data
					->img_c4->instances[i].enabled);
			struct_all->data->img_c4_red->instances[i].enabled = !(struct_all
					->data->img_c4->instances[i].enabled);
			i++;
		}
	}
}
