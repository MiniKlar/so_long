/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomont <lomont@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 01:58:48 by lomont            #+#    #+#             */
/*   Updated: 2025/02/13 01:58:28 by lomont           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/so_long.h"

int main(int argc, char **argv)
{
	//mlx_image_t *img;
	t_init *init_data;
	//void *mlx;

	if (argc == 2)
	{
		init_data = init_struct();
		init_all(argc, argv, init_data);
		if (init_data->fd > 0)
		{
			fill_tab(init_data);
			print_map(init_data->tab);
			check_all_parsing(init_data);
			// mlx = mlx_init(1920, 1080, "so_long", true);
			// if(!mlx)
			// 	return (free_struct(init_data), ft_putstr_fd("Error failed to init MLX\n", 2), 1);
			// img = mlx_new_image(mlx, 1920, 1080);
			// mlx_image_to_window(mlx, img, 0, 0);
			// mlx_put_pixel(img, 1920/2, 1080/2, 0x00FF00FF);
			// mlx_key_hook(mlx, close_window, mlx);
			// mlx_loop(mlx);
		}
		ft_printf("\nTOUT EST BON\n");
		free_struct(init_data);
	}
	else
		ft_printf("Error\n");
	return (0);
}
