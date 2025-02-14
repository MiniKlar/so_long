/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomont <lomont@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 03:56:55 by lomont            #+#    #+#             */
/*   Updated: 2025/02/14 04:22:48 by lomont           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void key_handler(mlx_key_data_t keydata, void* param)
{
	t_struct *struct_all = (t_struct *) param;

	if (keydata.key == MLX_KEY_ESCAPE)
		free_all(struct_all);
	else
		move_player(keydata, struct_all->struct_init, 0, 0);
}
void move_player(mlx_key_data_t keydata, t_init *init_data, int x, int y)
{
	char **tableau;

	x = init_data->player_pos_x;
	y = init_data->player_pos_y;
	tableau = init_data->tab;
	if (keydata.key == MLX_KEY_UP || keydata.key == MLX_KEY_W)
	{
		// if (tableau[x + 1][y] == '0' || tableau[x + 1][y] == 'E' || tableau[x + 1][y] == 'C')
		// 	init_data->player_pos_x += 1;
		printf("LOL1");
	}
	else if (keydata.key == MLX_KEY_DOWN || keydata.key == MLX_KEY_S)
	{
		// if (tableau[x - 1][y] == '0' || tableau[x - 1][y] == 'E' || tableau[x - 1][y] == 'C')
		// 	init_data->player_pos_x -= 1;
		printf("LOL1");
	}
	else if (keydata.key == MLX_KEY_RIGHT || keydata.key == MLX_KEY_D)
	{
		// if (tableau[x][y + 1] == '0' || tableau[x][y + 1] == 'E' || tableau[x][y + 1] == 'C')
		// 	init_data->player_pos_y += 1;
		printf("LOL1");
	}
	else if (keydata.key == MLX_KEY_LEFT || keydata.key == MLX_KEY_A)
	{
		// if (tableau[x][y - 1] == '0' || tableau[x][y - 1] == 'E' || tableau[x][y - 1] == 'C')
		// 	init_data->player_pos_y -= 1;
		printf("LOL1");
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
