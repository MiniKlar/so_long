/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomont <lomont@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 03:56:55 by lomont            #+#    #+#             */
/*   Updated: 2025/02/28 20:17:28 by lomont           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	key_handler(mlx_key_data_t keydata, void *param)
{
	t_struct	*struct_all;

	struct_all = (t_struct *) param;
	if (keydata.key == MLX_KEY_ESCAPE)
		free_all(struct_all);
	else
		move_player(keydata, struct_all, 0, 0);
}

void	move_player(mlx_key_data_t keydata, t_struct *all_struct, int x, int y)
{
	t_C_info	*tmp;
	char		**tab;

	x = all_struct->init->player_pos_x;
	y = all_struct->init->player_pos_y;
	tab = all_struct->init->tab;
	tmp = all_struct->first_node->node;
	if (keydata.action != MLX_RELEASE)
	{
		if (keydata.key == MLX_KEY_UP || keydata.key == MLX_KEY_W)
			move_player_up(all_struct, tab, x, y);
		else if (keydata.key == MLX_KEY_DOWN || keydata.key == MLX_KEY_S)
			move_player_down(all_struct, tab, x, y);
		else if (keydata.key == MLX_KEY_RIGHT || keydata.key == MLX_KEY_D)
			move_player_right(all_struct, tab, x, y);
		else if (keydata.key == MLX_KEY_LEFT || keydata.key == MLX_KEY_A)
			move_player_left(all_struct, tab, x, y);
		all_struct->first_node->node = tmp;
		if (all_struct->init->mov_counter > all_struct->init->prev_mov_counter)
			counter_to_window(all_struct);
	}
}

void	remove_items(t_struct *all_struct, int x, int y)
{
	int	i;

	i = ft_search_items_instances(all_struct, x, y);
	mlx_set_instance_depth(&all_struct->data->img_c4->instances[i], 0);
	mlx_set_instance_depth(&all_struct->data->img_c4_red->instances[i], 0);
	all_struct->init->n_collectibles--;
}
