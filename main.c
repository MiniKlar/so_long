/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomont <lomont@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 01:58:48 by lomont            #+#    #+#             */
/*   Updated: 2025/02/08 20:16:20 by lomont           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/so_long.h"

int main(int argc, char **argv)
{
	void *mlx;
	mlx_image_t *img;
	int fd;
	char **tmp;

	if (argc == 2)
	{
		fd = init_map(argc, argv);
		tmp = fill_tab_map(fd);
		//if (check_extension_map(argc, argv, fd) == false)
			//exit(EXIT_FAILURE);
		//if (check_map_is_rectangular(fd) == false)
		//{
		//	ft_printf("CE NEST PAS RECTANGULAIRE");
		//	exit(EXIT_FAILURE);
		//}
		mlx = mlx_init(1920, 1080, "so_long", true);
		img = mlx_new_image(mlx, 1920, 1080);
		
		mlx_image_to_window(mlx, img, 0, 0);
		mlx_put_pixel(img, 1920/2, 1080/2, 0x00FF00FF);
		mlx_key_hook(mlx, close_window, mlx);
		mlx_loop(mlx);
		printf("%s", argv[argc-1]);
	}
	else
		ft_printf("Error\n");
	return (0);
}
