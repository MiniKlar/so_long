/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miniklar <miniklar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 06:01:04 by lomont            #+#    #+#             */
/*   Updated: 2025/02/28 01:43:17 by miniklar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	put_wall_player_image(t_struct *all_struct, char **tableau,
	int x, int y)
{
	if (tableau[x][y] == '1')
		mlx_image_to_window(all_struct->mlx,
			all_struct->data->img_wall, y * SIZE, x * SIZE);
	if (tableau[x][y] == 'P')
	{
		mlx_image_to_window(all_struct->mlx,
			all_struct->data->img_player, y * SIZE, x * SIZE);
		mlx_set_instance_depth(all_struct->data->img_player->instances,
			3);
		mlx_image_to_window(all_struct->mlx,
			all_struct->data->img_player_right, y * SIZE, x * SIZE);
		mlx_set_instance_depth(all_struct->data->img_player_right->instances,
			3);
		all_struct->data->img_player_right->instances->enabled = false;
	}
	if (tableau[x][y] == 'T')
	{
		mlx_image_to_window(all_struct->mlx,
			all_struct->data->img_ct, y * SIZE, x * SIZE);
		mlx_set_instance_depth(all_struct->data->img_ct->instances,
			3);
		all_struct->data->img_ct->instances->enabled = true;
	}
}

void	put_exit_items_image(t_struct *all_struct, char **tableau, int x, int y)
{
	int	*item_counter;

	item_counter = &all_struct->init->item_counter;
	if (tableau[x][y] == 'E')
	{
		mlx_image_to_window(all_struct->mlx, all_struct->data->img_exit,
			y * SIZE, x * SIZE);
		mlx_set_instance_depth(all_struct->data->img_exit->instances, 2);
	}
	if (tableau[x][y] == 'C')
	{
		if (item_counter == 0)
		{
			all_struct->first_node->node->x = x;
			all_struct->first_node->node->y = y;
		}
		else
			insertion(all_struct->first_node, *item_counter, x, y);
		init_c4(all_struct, x, y);
		all_struct->init->item_counter++;
	}
}

void	put_floor_image(t_struct *all_struct)
{
	char	**tab;
	int		x;
	int		y;

	x = 0;
	tab = all_struct->init->tab;
	while (tab[x] != 0)
	{
		y = 0;
		while (tab[x][y] != '\0')
		{
			mlx_image_to_window(all_struct->mlx,
				all_struct->data->img_floor, y * SIZE, x * SIZE);
			mlx_set_instance_depth(&all_struct->data->img_floor
				->instances[x * all_struct->init->y_max + y], 1);
			y++;
		}
		x++;
	}
}

void	put_image_to_window(t_struct *all_struct)
{
	char	**tab;
	int		x;
	int		y;

	x = 0;
	tab = all_struct->init->tab;
	put_floor_image(all_struct);
	while (tab[x] != 0)
	{
		y = 0;
		while (tab[x][y] != '\0')
		{
			put_wall_player_image(all_struct, tab, x, y);
			put_exit_items_image(all_struct, tab, x, y);
			y++;
		}
		x++;
	}
}
void	init_c4(t_struct *all_struct, int x, int y)
{
	mlx_image_to_window(all_struct->mlx, all_struct->data->img_c4,
		y * SIZE, x * SIZE);
	mlx_set_instance_depth(&all_struct->data->img_c4
		->instances[all_struct->init->item_counter], 2);
	mlx_image_to_window(all_struct->mlx, all_struct->data->img_c4_red,
		y * SIZE, x * SIZE);
	mlx_set_instance_depth(&all_struct->data->img_c4_red
		->instances[all_struct->init->item_counter], 2);
	all_struct->data->img_c4_red->instances[all_struct->init->item_counter].enabled = false;
}
