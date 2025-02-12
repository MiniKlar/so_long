/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomont <lomont@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 01:58:48 by lomont            #+#    #+#             */
/*   Updated: 2025/02/12 04:10:20 by lomont           ###   ########.fr       */
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
			if (check_extension_map(init_data) == false)
			{
				ft_printf("PAS LA BONNE EXTENSION");
				free_struct(init_data);
				exit(EXIT_FAILURE);
			}
			else if (check_map_is_rectangular(init_data) == false)
			{
				ft_printf("MAP PAS RECTANGULAIRE");
				free_struct(init_data);
				exit(EXIT_FAILURE);
			}
			else if (check_map_is_not_empty(init_data) == false)
			{
				ft_printf("MAP VIDE\n");
				free_struct(init_data);
				exit(EXIT_FAILURE);
			}
			else if (check_map_only_charset(init_data) == false)
			{
				ft_printf("MAP INVALIDE\n");
				free_struct(init_data);
				exit(EXIT_FAILURE);
			}
			else if (map_is_enclosed_by_wall(init_data) == false)
			{
				ft_printf("MAP INVALIDE\n");
				free_struct(init_data);
				exit(EXIT_FAILURE);
			}
			else if (check_E_P_C(init_data) == false)
			{
				ft_printf("CHECK E P C INVALIDE\n");
				free_struct(init_data);
				exit(EXIT_FAILURE);
			}
			else if (flood_fill_map(init_data) == false)
			{
				ft_printf("MAP NON REALISABLE\n");
				free_struct(init_data);
				exit(EXIT_FAILURE);
			}
			// mlx = mlx_init(1920, 1080, "so_long", true);
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
