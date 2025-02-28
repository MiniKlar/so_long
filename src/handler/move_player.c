/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miniklar <miniklar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 12:23:34 by lomont            #+#    #+#             */
/*   Updated: 2025/02/28 02:02:04 by miniklar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	move_player_up(t_struct *all_struct, char **tab, int x, int y)
{
	int i = 0;
	if (tab[x - 1][y] == '0' || tab[x - 1][y] == 'E' || tab[x - 1][y] == 'C'
		|| tab[x - 1][y] == 'T')
	{
		if ((tab[x - 1][y] == 'E' && all_struct->init->n_collectibles == 0)
			|| tab[x - 1][y] == 'T')
			endgame(all_struct, 0, x - 1, y);
		else if (tab[x - 1][y] == 'E' && all_struct->init->n_collectibles != 0)
			tab[x][y] = '0';
		else if (tab[x - 1][y] == '0' && tab[x][y] != 'E')
		{
			tab[x][y] = '0';
			tab[x - 1][y] = 'P';
		}
		else if (tab[x - 1][y] == 'C')
		{
			i = ft_search_items_instances(all_struct, x - 1, y); 
			mlx_set_instance_depth(&all_struct->data->img_c4->instances[i], 0);
			mlx_set_instance_depth(&all_struct->data->img_c4_red->instances[i], 0);
			all_struct->init->n_collectibles--;
			tab[x - 1][y] = 'P';
			if (tab[x][y] != 'E')
				tab[x][y] = '0';
		}
		move_sprite(all_struct, -1);
	}
}

void	move_player_down(t_struct *all_struct, char **tab, int x, int y)
{
	int i;
	
	i = 0;
	if (tab[x + 1][y] == '0' || tab[x + 1][y] == 'E' || tab[x + 1][y] == 'C'
		|| tab[x + 1][y] == 'T')
	{
		if ((tab[x + 1][y] == 'E' && all_struct->init->n_collectibles == 0)
			|| tab[x + 1][y] == 'T')
			endgame(all_struct, 1, x + 1, y);
		else if (tab[x + 1][y] == 'E' && all_struct->init->n_collectibles != 0)
			tab[x][y] = '0';
		else if (tab[x + 1][y] == 'C')
		{
			i = ft_search_items_instances(all_struct, x + 1, y); 
			mlx_set_instance_depth(&all_struct->data->img_c4->instances[i], 0);
			mlx_set_instance_depth(&all_struct->data->img_c4_red->instances[i], 0);
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
		move_sprite(all_struct, 1);
	}
}

void	move_player_right(t_struct *all_struct, char **tab, int x, int y)
{
	int i;

	i = 0;
	if (tab[x][y + 1] == '0' || tab[x][y + 1] == 'E' || tab[x][y + 1] == 'C'
		|| tab[x][y + 1] == 'T')
	{
		if ((tab[x][y + 1] == 'E' && all_struct->init->n_collectibles == 0)
			|| tab[x][y + 1] == 'T')
			endgame(all_struct, 2, x, y + 1);
		else if (tab[x][y + 1] == 'E' && all_struct->init->n_collectibles != 0)
			tab[x][y] = '0';
		else if (tab[x][y + 1] == 'C')
		{
			i = ft_search_items_instances(all_struct, x, y + 1); 
			mlx_set_instance_depth(&all_struct->data->img_c4->instances[i], 0);
			mlx_set_instance_depth(&all_struct->data->img_c4_red->instances[i], 0);
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
	}
}

void	move_player_left(t_struct *all_struct, char **tab, int x, int y)
{
	int i = 0;
	if (tab[x][y - 1] == '0' || tab[x][y - 1] == 'E' || tab[x][y - 1] == 'C'
		|| tab[x][y - 1] == 'T')
	{
		if ((tab[x][y - 1] == 'E' && all_struct->init->n_collectibles == 0)
			|| tab[x][y - 1] == 'T')
			endgame(all_struct, 4, x, y - 1);
		else if (tab[x][y - 1] == 'E' && all_struct->init->n_collectibles != 0)
			tab[x][y] = '0';
		else if (tab[x][y - 1] == 'C')
		{
			i = ft_search_items_instances(all_struct, x, y - 1); 
			mlx_set_instance_depth(&all_struct->data->img_c4->instances[i], 0);
			mlx_set_instance_depth(&all_struct->data->img_c4_red->instances[i], 0);
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
	}
}

void	endgame(t_struct *all_struct, int i, int x, int y)
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
	if (all_struct->init->tab[x][y] == 'T')
		ft_printf("You have hit an enemy, try again!\n");
	else
		ft_printf("IT'S A WIN!\n");
	free_all(all_struct);
}
