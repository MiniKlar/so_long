/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomont <lomont@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 01:58:48 by lomont            #+#    #+#             */
/*   Updated: 2025/02/16 02:27:47 by lomont           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/so_long.h"

//TODO VERIFIER QUE CA FREE BIEN SI ERREUR DE PNG / ERREUR DE CHEMIN
// TODO CLOSE FD
//TODO VERIFITER RELINK MAKEFILE
//TODO IMPLEMENTER COMPTEUR MOUVEMENT


int main(int argc, char **argv)
{
	t_data	*game_data;
	t_init 	*init_data;
	t_struct *all_struct;
	list *first_node;
	char **tab;
	int x;
	int y;
	int C_counter;

	all_struct = NULL;
	if (argc == 2)
	{
		init_data = init_struct();
		init_all(argc, argv, init_data);
		fill_tab(init_data);
		tab = init_data->flood_tab;
		check_all_parsing(init_data);
		if (init_data->y_max * SIZE > 1920 || init_data->x_max * SIZE > 1024)
		{
			printf("MAP TROP GRANDE\n");
			return ((free_parsing(init_data), 1));
		}
		game_data = init_game_data();
		all_struct = init_ptr_to_struct();
		first_node = initalisation();
		all_struct->struct_init = init_data;
		all_struct->struct_data = game_data;
		all_struct->first_node = first_node;
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
				mlx_set_instance_depth(&all_struct->struct_data->img_floor->instances[x * all_struct->struct_init->y_max + y], 1);
				y++;
			}
			x++;
		}
		x = 0;
		C_counter = 0;
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
				{
					mlx_image_to_window(all_struct->mlx, game_data->img_exit, y * SIZE, x * SIZE);
					mlx_set_instance_depth(all_struct->struct_data->img_exit->instances, 2);
				}
				if (tab[x][y] == 'C')
				{
					if (C_counter == 0)
					{
						all_struct->first_node->node->x = x;
						all_struct->first_node->node->y = y;
					}
					else
						insertion(first_node, C_counter, x, y);
					mlx_image_to_window(all_struct->mlx, game_data->img_C4, y * SIZE, x * SIZE);
					mlx_set_instance_depth(&all_struct->struct_data->img_C4->instances[C_counter], 2);
					C_counter++;
				}
				y++;
			}
			x++;
		}
		mlx_key_hook(all_struct->mlx, key_handler, all_struct);
		mlx_loop(all_struct->mlx);
	}
	free_all(all_struct); //ne pas supprimer, enlever commentaire
	return (0);
}
