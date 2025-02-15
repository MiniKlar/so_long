/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomont <lomont@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 03:56:55 by lomont            #+#    #+#             */
/*   Updated: 2025/02/15 07:19:40 by lomont           ###   ########.fr       */
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

	x = all_struct->struct_init->player_pos_x;
	y = all_struct->struct_init->player_pos_y;
	tableau = all_struct->struct_init->tab;
	if (keydata.action == 1)
	{
		if (keydata.key == MLX_KEY_UP || keydata.key == MLX_KEY_W)
		{
			if (tableau[x - 1][y] == '0' || tableau[x - 1][y] == 'E' || tableau[x - 1][y] == 'C')
			{
				if (tableau[x - 1][y] == '0' || tableau[x][y] != 'E')
				{
					tableau[x][y] = '0';
					tableau[x - 1][y] = 'P';
					//printf("%d", tableau[x][y]);
					//mlx_image_to_window(all_struct->mlx, all_struct->struct_data->img_player, y * SIZE, (x - 1) * SIZE);
				}
				else if (tableau[x - 1][y] == 'C')
				{
					mlx_put_string(all_struct->mlx, "TU ES SUR COLLECTIBLES z", 90, 90);
					all_struct->struct_init->finish_collectibles++;
					tableau[x][y] = '0';
					tableau[x + 1][y] = 'P';
					mlx_image_to_window(all_struct->mlx, all_struct->struct_data->img_floor, y * SIZE, x * SIZE);
					//mlx_image_to_window(all_struct->mlx, all_struct->struct_data->img_player, y * SIZE, (x - 1) * SIZE);
				}
				else if (tableau[x - 1][y] == 'E' && all_struct->struct_init->finish_collectibles == all_struct->struct_init->N_collectibles)
				{
					printf("TU PASSES LA TOII");
					all_struct->struct_data->img_player->instances->y += SIZE;
					free_all(all_struct);
				}
				//mlx_image_to_window(all_struct->mlx, all_struct->struct_data->img_floor, y * SIZE, x * SIZE);
				//all_struct->struct_init->player_pos_x -= 1;
				all_struct->struct_init->player_pos_x -= 1;
				all_struct->struct_data->img_player->instances->y -= SIZE;
			}
			//printf("UP");
		}
		else if (keydata.key == MLX_KEY_DOWN || keydata.key == MLX_KEY_S)
		{
			if (tableau[x + 1][y] == '0' || tableau[x + 1][y] == 'E' || tableau[x + 1][y] == 'C')
			{
				if (tableau[x + 1][y] == '0' || tableau[x][y] != 'E')
				{
					tableau[x][y] = '0';
					tableau[x + 1][y] = 'P';
					//mlx_image_to_window(all_struct->mlx, all_struct->struct_data->img_player, y * SIZE, (x + 1) * SIZE);
				}
				else if (tableau[x + 1][y] == 'C')
				{
					mlx_put_string(all_struct->mlx, "TU ES SUR COLLECTIBLES q f", 90, 90);
					all_struct->struct_init->finish_collectibles++;
					tableau[x][y] = '0';
					tableau[x + 1][y] = 'P';
					printf("\ncoll %d and %d\n", all_struct->struct_init->finish_collectibles, all_struct->struct_init->N_collectibles);
					//mlx_image_to_window(all_struct->mlx, all_struct->struct_data->img_floor, y * SIZE, x * SIZE);
					mlx_image_to_window(all_struct->mlx, all_struct->struct_data->img_player, y * SIZE, (x + 1) * SIZE);
				}
				else if (tableau[x + 1][y] == 'E' && all_struct->struct_init->finish_collectibles == all_struct->struct_init->N_collectibles)
				{
					printf("TU PASSES LA TOII");
					all_struct->struct_data->img_player->instances->y += SIZE;
					free_all(all_struct);
				}
				all_struct->struct_init->player_pos_x += 1;
				all_struct->struct_data->img_player->instances->y += SIZE;
				//all_struct->struct_data->img_player->instances->y += SIZE;
				//mlx_image_to_window(all_struct->mlx, all_struct->struct_data->img_floor, y * SIZE, x * SIZE);
				//all_struct->struct_init->player_pos_x += 1;
			}
			//printf("DOWN");
		}
		else if (keydata.key == MLX_KEY_RIGHT || keydata.key == MLX_KEY_D)
		{
			if (tableau[x][y + 1] == '0' || tableau[x][y + 1] == 'E' || tableau[x][y + 1] == 'C')
			{
				if (tableau[x][y + 1] == 'E' && all_struct->struct_init->finish_collectibles == all_struct->struct_init->N_collectibles)
				{
					printf("TU PASSES LA TOIIadadadad");
					all_struct->struct_data->img_player->instances->y += SIZE;
					free_all(all_struct);
				}
				else if (tableau[x][y + 1] == 'C')
				{
					mlx_put_string(all_struct->mlx, "TU ES SUR COLLECTIBLES", 90, 90);
					all_struct->struct_init->finish_collectibles++;
					tableau[x][y + 1] = 'P';
					tableau[x][y] = '0';
					mlx_image_to_window(all_struct->mlx, all_struct->struct_data->img_floor, y * SIZE, x * SIZE);
				}
				else if (tableau[x][y + 1] == '0' && tableau[x][y] != 'E')
				{
					printf("TU PASSES LA TOII");
					tableau[x][y + 1] = 'P';
					tableau[x][y] = '0';
				}
				//mlx_image_to_window(all_struct->mlx, all_struct->struct_data->img_player, (y + 1) * SIZE, x * SIZE);
				//mlx_image_to_window(all_struct->mlx, all_struct->struct_data->img_floor, y * SIZE, x * SIZE);
				//all_struct->struct_init->player_pos_y += 1;
				all_struct->struct_data->img_player->instances->x += SIZE;
				all_struct->struct_init->player_pos_y += 1;
			}
			//printf("RIGHT");
		}
		else if (keydata.key == MLX_KEY_LEFT || keydata.key == MLX_KEY_A)
		{
			if (tableau[x][y - 1] == '0' || tableau[x][y - 1] == 'E' || tableau[x][y - 1] == 'C')
			{
				//mlx_image_to_window(all_struct->mlx, all_struct->struct_data->img_player, (y - 1) * SIZE, x * SIZE);
				//mlx_image_to_window(all_struct->mlx, all_struct->struct_data->img_floor, y * SIZE, x * SIZE);
				//all_struct->struct_init->player_pos_y -= 1;
				if (tableau[x][y - 1] == '0' || tableau[x][y] != 'E')
				{
					tableau[x][y - 1] = 'P';
					tableau[x][y] = '0';
				}
				else if (tableau[x][y - 1] == 'C')
				{
					mlx_put_string(all_struct->mlx, "TU ES SUR COLLECTIBLES q", 90, 90);
					all_struct->struct_init->finish_collectibles++;
					tableau[x][y - 1] = 'P';
					tableau[x][y] = '0';
					mlx_image_to_window(all_struct->mlx, all_struct->struct_data->img_floor, y * SIZE, x * SIZE);
				}
				else if (tableau[x][y - 1] == 'E' && all_struct->struct_init->finish_collectibles  == all_struct->struct_init->N_collectibles)
				{
					printf("TU PASSES LA TOII");
					all_struct->struct_data->img_player->instances->y += SIZE;
					free_all(all_struct);
				}
				all_struct->struct_data->img_player->instances->x -= SIZE;
				all_struct->struct_init->player_pos_y -= 1;
				//printf("LEFT");
			}
		}
		printf("\ncoll %d anadwadadwadadwadwdawddd %d et %c\n", all_struct->struct_init->finish_collectibles, all_struct->struct_init->N_collectibles, tableau[2][12]);
	}
}
// void close_window(mlx_key_data_t keydata, mlx_t* mlx)
// {
// 	if (keydata.key == MLX_KEY_ESCAPE)
// 	{
// 		//printf("\n\n\ndebug\n\n\n| %d |",keydata.key);
// 		//printf("\n | %d |\n",keydata.action);
// 		free_mlx(mlx);
// 	}
// }
