/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomont <lomont@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 01:58:48 by lomont            #+#    #+#             */
/*   Updated: 2025/02/08 06:03:48 by lomont           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/so_long.h"

int main(int argc, char **argv)
{
	void *mlx;
	mlx_image_t *img;
	mlx = mlx_init(1920, 1080, "so_long", true);
	img = mlx_new_image(mlx, 1920, 1080);
	mlx_image_to_window(mlx, img, 0, 0);
	mlx_key_hook(mlx, close_window, mlx);
	mlx_loop(mlx);
	printf("%s", argv[argc-1]);
	return (0);
}