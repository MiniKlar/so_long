/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomont <lomont@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 01:58:48 by lomont            #+#    #+#             */
/*   Updated: 2025/02/13 04:07:33 by lomont           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/so_long.h"

int main(int argc, char **argv)
{
	t_data	*game_data;
	t_init 	*init_data;
	void *mlx;

	if (argc == 2)
	{
		init_data = init_struct();
		game_data = init_game_data();
		init_all(argc, argv, init_data);
		if (init_data->fd > 0)
		{
			fill_tab(init_data);
			print_map(init_data->tab);
			check_all_parsing(init_data);
			mlx = mlx_init(1920, 1080, "so_long", true);
			if(!mlx)
				return (free_struct(init_data), ft_putstr_fd("Error failed to init MLX\n", 2), 1);
			//img = mlx_new_image(mlx, 1920, 1080);
			game_data->C4 = mlx_load_png("./src/img/C4.png");
			game_data->perso_T = mlx_load_png("./src/img/player.png");
			game_data->exit = mlx_load_png("./src/img/B.png");
			if (!game_data->C4)
				printf("error\n");
			else
				printf("good\n");
			game_data->img3 = mlx_texture_to_image(mlx, game_data->C4);
			game_data->img2 = mlx_texture_to_image(mlx, game_data->perso_T);
			game_data->img = mlx_texture_to_image(mlx, game_data->exit);
			mlx_image_to_window(mlx, game_data->img3, (1920 / 3) * 2, (1080 / 3) * 2);
			mlx_image_to_window(mlx, game_data->img2, 0 * 2, 0 * 2);
			mlx_image_to_window(mlx, game_data->img, 1920/2, 1080/2);
			mlx_key_hook(mlx, close_window, mlx);
			mlx_loop(mlx);
		}
		ft_printf("\nTOUT EST BON\n");
		free_struct(init_data);
	}
	else
		ft_printf("Error\n");
	return (0);
}
