/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miniklar <miniklar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 12:23:34 by lomont            #+#    #+#             */
/*   Updated: 2025/02/26 14:55:13 by miniklar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	move_player_up(t_struct *all_struct, char **tab, int x, int y)
{
	if (tab[x - 1][y] == '0' || tab[x - 1][y] == 'E' || tab[x - 1][y] == 'C')
	{
		if (tab[x - 1][y] == 'E' && all_struct->init->n_collectibles == 0)
			endgame(all_struct, 0);
		else if (tab[x - 1][y] == 'E' && all_struct->init->n_collectibles != 0)
			tab[x][y] = '0';
		else if (tab[x - 1][y] == '0' && tab[x][y] != 'E')
		{
			tab[x][y] = '0';
			tab[x - 1][y] = 'P';
		}
		else if (tab[x - 1][y] == 'C')
		{
			mlx_set_instance_depth(&all_struct->data->img_c4->instances
			[ft_search_items_instances(all_struct, x - 1, y)], 0);
			all_struct->init->n_collectibles--;
			tab[x - 1][y] = 'P';
			if (tab[x][y] != 'E')
				tab[x][y] = '0';
		}
		all_struct->init->mov_counter++;
		all_struct->init->player_pos_x -= 1;
		all_struct->data->img_player->instances->y -= SIZE;
	}
}

void	move_player_down(t_struct *all_struct, char **tab, int x, int y)
{
	if (tab[x + 1][y] == '0' || tab[x + 1][y] == 'E' || tab[x + 1][y] == 'C')
	{
		if (tab[x + 1][y] == 'E' && all_struct->init->n_collectibles == 0)
			endgame(all_struct, 1);
		else if (tab[x + 1][y] == 'E' && all_struct->init->n_collectibles != 0)
			tab[x][y] = '0';
		else if (tab[x + 1][y] == 'C')
		{
			mlx_set_instance_depth(&all_struct->data->img_c4->instances
			[ft_search_items_instances(all_struct, x + 1, y)], 0);
			all_struct->init->n_collectibles--;
			tab[x + 1][y] = 'P';
			if (tab[x][y] != 'E')
				tab[x][y] = '0';
		}
		else if (tab[x + 1][y] == '0' && tab[x][y] != 'E')
		{
			tab[x][y] = '0';
			tab[x + 1][y] = 'P';
		}
		all_struct->init->mov_counter++;
		all_struct->init->player_pos_x += 1;
		all_struct->data->img_player->instances->y += SIZE;
	}
}

void	move_player_right(t_struct *all_struct, char **tab, int x, int y)
{
	if (tab[x][y + 1] == '0' || tab[x][y + 1] == 'E' || tab[x][y + 1] == 'C')
	{
		if (tab[x][y + 1] == 'E' && all_struct->init->n_collectibles == 0)
			endgame(all_struct, 2);
		else if (tab[x][y + 1] == 'E' && all_struct->init->n_collectibles != 0)
			tab[x][y] = '0';
		else if (tab[x][y + 1] == 'C')
		{
			mlx_set_instance_depth(&all_struct->data->img_c4->instances
			[ft_search_items_instances(all_struct, x, y + 1)], 0);
			all_struct->init->n_collectibles--;
			tab[x][y + 1] = 'P';
			if (tab[x][y] != 'E')
				tab[x][y] = '0';
		}
		else if (tab[x][y + 1] == '0' && tab[x][y] != 'E')
		{
			tab[x][y + 1] = 'P';
			tab[x][y] = '0';
		}
		change_sprite_right(all_struct);
		all_struct->init->player_pos_y += 1;
		all_struct->data->img_player_right->instances->x += SIZE;
	}
}

void	move_player_left(t_struct *all_struct, char **tab, int x, int y)
{
	if (tab[x][y - 1] == '0' || tab[x][y - 1] == 'E' || tab[x][y - 1] == 'C')
	{
		if (tab[x][y - 1] == 'E' && all_struct->init->n_collectibles == 0)
			endgame(all_struct, 4);
		else if (tab[x][y - 1] == 'E' && all_struct->init->n_collectibles != 0)
			tab[x][y] = '0';
		else if (tab[x][y - 1] == 'C')
		{
			mlx_set_instance_depth(&all_struct->data->img_c4->instances
			[ft_search_items_instances(all_struct, x, y - 1)], 0);
			all_struct->init->n_collectibles--;
			tab[x][y - 1] = 'P';
			if (tab[x][y] != 'E')
				tab[x][y] = '0';
		}
		else if (tab[x][y - 1] == '0' && tab[x][y] != 'E')
		{
			tab[x][y - 1] = 'P';
			tab[x][y] = '0';
		}
		change_sprite(all_struct);
		all_struct->init->player_pos_y -= 1;
		all_struct->data->img_player->instances->x -= SIZE;
	}
}

void	endgame(t_struct *all_struct, int i)
{
	if (i == 0)
		all_struct->data->img_player->instances->y -= SIZE;
	else if (i == 1)
		all_struct->data->img_player->instances->y += SIZE;
	else if (i == 2)
		all_struct->data->img_player->instances->x += SIZE;
	else
		all_struct->data->img_player->instances->x -= SIZE;
	all_struct->init->mov_counter++;
	counter_to_window(all_struct);
	free_all(all_struct);
}
