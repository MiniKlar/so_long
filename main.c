/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomont <lomont@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 01:58:48 by lomont            #+#    #+#             */
/*   Updated: 2025/02/11 00:26:42 by lomont           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/so_long.h"

int main(int argc, char **argv)
{
	mlx_image_t *img;
	t_init *init_data;
	void *mlx;

	if (argc == 2)
	{
		init_data = init_struct();
		init_all(argc, argv, init_data);
		printf("%d\n", init_data->fd);
		if (init_data->fd > 0)
		{
			fill_tab_map(init_data);
			if (check_extension_map(init_data) == false)
			{
				exit(EXIT_FAILURE);
			}
			if (check_map_is_rectangular(init_data) == false)
			{
				exit(EXIT_FAILURE);
			}
			if (check_map_is_not_empty(init_data) == false)
			{
				ft_printf("MAP VIDE");
				exit(EXIT_FAILURE);
			}
			mlx = mlx_init(1920, 1080, "so_long", true);
			img = mlx_new_image(mlx, 1920, 1080);
			mlx_image_to_window(mlx, img, 0, 0);
			mlx_put_pixel(img, 1920/2, 1080/2, 0x00FF00FF);
			mlx_key_hook(mlx, close_window, mlx);
			mlx_loop(mlx);
			printf("%s", argv[argc-1]);
		}
	}
	else
		ft_printf("Error\n");
	return (0);
}
