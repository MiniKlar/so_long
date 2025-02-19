/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomont <lomont@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 01:58:48 by lomont            #+#    #+#             */
/*   Updated: 2025/02/20 00:01:28 by lomont           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/so_long.h"

//TODO VERIFIER QUE CA FREE BIEN SI ERREUR DE PNG / ERREUR DE CHEMIN [x]
// TODO CLOSE FD [x]
//TODO VERIFITER RELINK MAKEFILE
//TODO IMPLEMENTER COMPTEUR MOUVEMENT dans le shell [x]
//TODO VOIR DISPLAY= VOIR SI MLX RENVOIE BIEN UN TRUC [v]
//TODO CHECK MAP si vide au dessus, en dessous et au milieu. [x]

int	main(int argc, char **argv)
{
	t_struct	*all_struct;

	if (argc == 2)
	{
		all_struct = init_structure();
		init_all(argc, argv, all_struct->init);
		fill_tab(all_struct->init);
		print_map(all_struct->init->tab);
		check_all_parsing(all_struct);
		all_struct->mlx = mlx_init(all_struct->init->y_max * SIZE,
				all_struct->init->x_max * SIZE, "so_long", true);
		if (!all_struct->mlx)
			return (free_struct(all_struct),
				ft_putstr_fd("Error failed to init MLX\n", 2), 1);
		init_texture_image(all_struct);
		put_image_to_window(all_struct);
		mlx_key_hook(all_struct->mlx, key_handler, all_struct);
		mlx_loop(all_struct->mlx);
		free_all(all_struct);
	}
	return (0);
}
