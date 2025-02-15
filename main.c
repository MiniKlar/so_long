/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomont <lomont@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 01:58:48 by lomont            #+#    #+#             */
/*   Updated: 2025/02/15 07:04:55 by lomont           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/so_long.h"

//TODO VERIFIER QUE CA FREE BIEN SI ERREUR DE PNG / ERREUR DE CHEMIN
// TODO CLOSE FD

int main(int argc, char **argv)
{
	t_data	*game_data;
	t_init 	*init_data;
	t_struct *all_struct;
	char **tab;
	int x;
	int y;

	if (argc == 2)
	{
		init_data = init_struct();
		game_data = init_game_data();
		all_struct = init_ptr_to_struct();
		all_struct->struct_data = game_data;
		all_struct->struct_init = init_data;
		init_all(argc, argv, init_data);
		//printf("\nLOL TOIIII%d\n", all_struct->struct_init->finish_collectibles);
		if (init_data->fd > 0)
		{
			fill_tab(init_data);
			tab = init_data->flood_tab;
			print_map(tab);
			//printf("\n\n%c\n\n", init_data->flood_tab[2][5]);
			check_all_parsing(init_data);
			//printf("\nLOL TOIIII%d\n", init_data->x_max * SIZE);
			if (init_data->y_max * SIZE > 1920 || init_data->x_max * SIZE > 1024)
			{
				printf("MAP TROP GRANDE\n");
				return ((free_parsing(init_data), 1));
			}
			all_struct->mlx = mlx_init(init_data->y_max * SIZE, init_data->x_max * SIZE, "so_long", true);
			if(!all_struct->mlx)
				return (free_struct(all_struct), ft_putstr_fd("Error failed to init MLX\n", 2), 1);
			x = 0;
			game_data->floor = mlx_load_png("./src/img/floor.png");
			game_data->img_floor = mlx_texture_to_image(all_struct->mlx, game_data->floor);
			game_data->wall= mlx_load_png("./src/img/wall.png");
			game_data->img_wall = mlx_texture_to_image(all_struct->mlx, game_data->wall);
			game_data->exit= mlx_load_png("./src/img/B.png");
			game_data->img_exit = mlx_texture_to_image(all_struct->mlx, game_data->exit);
			game_data->player= mlx_load_png("./src/img/player.png");
			game_data->img_player = mlx_texture_to_image(all_struct->mlx, game_data->player);
			game_data->C4= mlx_load_png("./src/img/C4_final_1.png");
			game_data->img_C4 = mlx_texture_to_image(all_struct->mlx, game_data->C4);
			tab = init_data->tab;
			while (tab[x] != 0)
			{
				y = 0;
				while (tab[x][y] != '\0')
				{
					mlx_image_to_window(all_struct->mlx, game_data->img_floor, y * SIZE, x * SIZE);
					mlx_set_instance_depth(&all_struct->struct_data->img_floor->instances[x * all_struct->struct_init->y_max + y], 0);
					y++;
				}
				x++;
			}
			x = 0;
			while (tab[x] != 0)
			{
				y = 0;
				while (tab[x][y] != '\0')
				{
					if (tab[x][y] == '1')
						mlx_image_to_window(all_struct->mlx, game_data->img_wall, y * SIZE, x * SIZE);
					if (tab[x][y] == 'P')
					{
						mlx_image_to_window(all_struct->mlx, game_data->img_player, y * SIZE, x * SIZE);
						mlx_set_instance_depth(all_struct->struct_data->img_player->instances, 3);
					}
					if (tab[x][y] == 'E')
						mlx_image_to_window(all_struct->mlx, game_data->img_exit, y * SIZE, x * SIZE);
					if (tab[x][y] == 'C')
						mlx_image_to_window(all_struct->mlx, game_data->img_C4, y * SIZE, x * SIZE);
					y++;
				}
				x++;
			}
			mlx_key_hook(all_struct->mlx, key_handler, all_struct);
			//mlx_close_hook(all_struct->mlx, free_all, all_struct);
			mlx_loop(all_struct->mlx);
		}
		ft_printf("\nTOUT EST BON\n");
		//ft_printf("\n%d %d\n", init_data->player_pos_x, init_data->player_pos_y);
		//ft_printf("\n%d et %d\n", init_data->x_max, init_data->y_max);
		free_all(all_struct);
	}
	else
		ft_printf("Error\n");
	return (0);
}
