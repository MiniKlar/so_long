/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomont <lomont@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 03:56:55 by lomont            #+#    #+#             */
/*   Updated: 2025/02/16 03:54:18 by lomont           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void key_handler(mlx_key_data_t keydata, void* param)
{
	t_struct *struct_all = (t_struct *) param;

	if (keydata.key == MLX_KEY_ESCAPE)
		free_all(struct_all);
	else
		move_player(keydata, struct_all, 0, 0);
}
void move_player(mlx_key_data_t keydata, t_struct *all_struct, int x, int y)
{
	char **tableau;
	int index;
	t_C_info *tmp;

	x = all_struct->struct_init->player_pos_x;
	y = all_struct->struct_init->player_pos_y;
	index = 0;
	tableau = all_struct->struct_init->tab;
	tmp = all_struct->first_node->node;
	if (keydata.action != 0)
	{
		if (keydata.key == MLX_KEY_UP || keydata.key == MLX_KEY_W)
		{
			if (tableau[x - 1][y] == '0' || tableau[x - 1][y] == 'E' || tableau[x - 1][y] == 'C')
			{
				if (tableau[x - 1][y] == '0' && tableau[x][y] != 'E')
				{
					tableau[x][y] = '0';
					tableau[x - 1][y] = 'P';
				}
				else if (tableau[x - 1][y] == 'E' && !(all_struct->struct_init->finish_collectibles == all_struct->struct_init->N_collectibles))
				{
					tableau[x][y] = '0';
				}
				else if (tableau[x - 1][y] == 'C')
				{
					index = ft_search_C_instances(all_struct, x - 1, y);
					mlx_set_instance_depth(&all_struct->struct_data->img_C4->instances[index], 0);
					all_struct->struct_init->finish_collectibles++;
					tableau[x - 1][y] = 'P';
					if (tableau[x][y] != 'E')
						tableau[x][y] = '0';
					all_struct->first_node->node = tmp;
				}
				else if (tableau[x - 1][y] == 'E' && all_struct->struct_init->finish_collectibles == all_struct->struct_init->N_collectibles)
				{
					all_struct->struct_data->img_player->instances->y -= SIZE;
					free_all(all_struct);
				}
				all_struct->struct_init->player_pos_x -= 1;
				all_struct->struct_data->img_player->instances->y -= SIZE;
			}
		}
		else if (keydata.key == MLX_KEY_DOWN || keydata.key == MLX_KEY_S)
		{
			if (tableau[x + 1][y] == '0' || tableau[x + 1][y] == 'E' || tableau[x + 1][y] == 'C')
			{
				if (tableau[x + 1][y] == 'E' && all_struct->struct_init->finish_collectibles == all_struct->struct_init->N_collectibles)
				{
					all_struct->struct_data->img_player->instances->y += SIZE;
					free_all(all_struct);
				}
				else if (tableau[x + 1][y] == 'E' && !(all_struct->struct_init->finish_collectibles == all_struct->struct_init->N_collectibles))
				{
					tableau[x][y] = '0';
				}
				else if (tableau[x + 1][y] == 'C')
				{
					index = ft_search_C_instances(all_struct, x + 1, y);
					mlx_set_instance_depth(&all_struct->struct_data->img_C4->instances[index], 0);
					all_struct->struct_init->finish_collectibles++;
					tableau[x + 1][y] = 'P';
					if (tableau[x][y] != 'E')
						tableau[x][y] = '0';
					all_struct->first_node->node = tmp;
				}
				else if (tableau[x + 1][y] == '0' && tableau[x][y] != 'E')
				{
					tableau[x][y] = '0';
					tableau[x + 1][y] = 'P';
				}
				all_struct->struct_data->img_player->instances->y += SIZE;
				all_struct->struct_init->player_pos_x += 1;
			}
		}
		else if (keydata.key == MLX_KEY_RIGHT || keydata.key == MLX_KEY_D)
		{
			if (tableau[x][y + 1] == '0' || tableau[x][y + 1] == 'E' || tableau[x][y + 1] == 'C')
			{
				if (tableau[x][y + 1] == 'E' && all_struct->struct_init->finish_collectibles == all_struct->struct_init->N_collectibles)
				{
					all_struct->struct_data->img_player->instances->y += SIZE;
					free_all(all_struct);
				}
				else if (tableau[x][y + 1] == 'E' && !(all_struct->struct_init->finish_collectibles == all_struct->struct_init->N_collectibles))
				{
					tableau[x][y] = '0';
				}
				else if (tableau[x][y + 1] == 'C')
				{
					index = ft_search_C_instances(all_struct, x, y + 1);
					mlx_set_instance_depth(&all_struct->struct_data->img_C4->instances[index], 0);
					all_struct->struct_init->finish_collectibles++;
					tableau[x][y + 1] = 'P';
					if (tableau[x][y] != 'E')
						tableau[x][y] = '0';
					all_struct->first_node->node = tmp;
				}
				else if (tableau[x][y + 1] == '0' && tableau[x][y] != 'E')
				{
					tableau[x][y + 1] = 'P';
					tableau[x][y] = '0';
				}
				all_struct->struct_data->img_player->instances->x += SIZE; //INVERSION NORMALE X ET Y
				all_struct->struct_init->player_pos_y += 1;
			}
		}
		else if (keydata.key == MLX_KEY_LEFT || keydata.key == MLX_KEY_A)
		{
			if (tableau[x][y - 1] == '0' || tableau[x][y - 1] == 'E' || tableau[x][y - 1] == 'C')
			{
				if (tableau[x][y - 1] == 'E' && all_struct->struct_init->finish_collectibles  == all_struct->struct_init->N_collectibles)
				{
					all_struct->struct_data->img_player->instances->y += SIZE;
					free_all(all_struct);
				}
				else if (tableau[x][y - 1] == 'E' && !(all_struct->struct_init->finish_collectibles == all_struct->struct_init->N_collectibles))
				{
					tableau[x][y] = '0';
				}
				else if (tableau[x][y - 1] == 'C')
				{
					index = ft_search_C_instances(all_struct, x, y - 1);
					mlx_set_instance_depth(&all_struct->struct_data->img_C4->instances[index], 0);
					all_struct->struct_init->finish_collectibles++;
					tableau[x][y - 1] = 'P';
					if (tableau[x][y] != 'E')
						tableau[x][y] = '0';
					all_struct->first_node->node = tmp;
				}
				else if (tableau[x][y - 1] == '0' && tableau[x][y] != 'E')
				{
					tableau[x][y - 1] = 'P';
					tableau[x][y] = '0';
				}
				all_struct->struct_data->img_player->instances->x -= SIZE;
				all_struct->struct_init->player_pos_y -= 1;
			}
		}
	}
}
