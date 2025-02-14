/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomont <lomont@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 01:58:48 by lomont            #+#    #+#             */
/*   Updated: 2025/02/14 04:37:24 by lomont           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/so_long.h"

int main(int argc, char **argv)
{
	t_data	*game_data;
	t_init 	*init_data;
	t_struct *all_struct;

	if (argc == 2)
	{
		init_data = init_struct();
		game_data = init_game_data();
		all_struct = init_ptr_to_struct();
		all_struct->struct_data = game_data;
		all_struct->struct_init = init_data;
		init_all(argc, argv, init_data);
		if (init_data->fd > 0)
		{
			fill_tab(init_data);
			print_map(init_data->tab);
			check_all_parsing(init_data);
			all_struct->mlx = mlx_init(init_data->y_max * SIZE, init_data->x_max * SIZE, "so_long", true);
			if(!all_struct->mlx)
				return (free_struct(all_struct), ft_putstr_fd("Error failed to init MLX\n", 2), 1);
			//img = mlx_new_image(all_struct->mlx, 1920, 1080);
			// game_data->C4 = mlx_load_png("./src/img/C4.png");
			//game_data->perso_T = mlx_load_png("./src/img/player.png");
			// game_data->exit = mlx_load_png("./src/img/B.png");
			// if (!game_data->C4)
			// 	printf("error\n");
			// else
			// 	printf("good\n");
			// game_data->img3 = mlx_texture_to_image(all_struct->mlx, game_data->C4);
			//game_data->img = mlx_texture_to_image(all_struct->mlx, game_data->perso_T);
			// game_data->img = mlx_texture_to_image(all_struct->mlx, game_data->exit);
			//mlx_image_to_window(mlx, game_data->img3, (1920 / 3) * 2, (1080 / 3) * 2);
			//mlx_image_to_window(all_struct->mlx, game_data->img2, 640 / 2, 480 / 2);
			//mlx_image_to_window(mlx, game_data->img, 1920/2, 1080/2);
			game_data->img = mlx_put_string(all_struct->mlx, "LE ARTHUR HEIN JE LUI BOUFFE LE CUL", 640/3, 480/3);
			mlx_key_hook(all_struct->mlx, key_handler, all_struct);
			//mlx_close_hook(all_struct->mlx, free_all, all_struct);
			mlx_loop(all_struct->mlx);
			mlx_delete_image(all_struct->mlx, game_data->img);
		}
		ft_printf("\nTOUT EST BON\n");
		ft_printf("\n%d et %d\n", init_data->x_max, init_data->y_max);
		free_all(all_struct);
	}
	else
		ft_printf("Error\n");
	return (0);
}
