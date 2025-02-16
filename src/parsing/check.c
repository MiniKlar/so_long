/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomont <lomont@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 01:54:00 by lomont            #+#    #+#             */
/*   Updated: 2025/02/16 03:30:53 by lomont           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void check_all_parsing(t_init *init_data)
{
	check_parsing(init_data);
	check_parsing_alt(init_data);
}
void check_parsing(t_init *init_data)
{
	if (check_extension_map(init_data) == false)
	{
		ft_putstr_fd("Error\nPas la bonne extension de fichier\n", 2);
		free_parsing(init_data);
		exit(EXIT_FAILURE);
	}
	else if (check_map_is_not_empty(init_data) == false)
	{
		ft_putstr_fd("Error\nLa map est vide\n", 2);
		free_parsing(init_data);
		exit(EXIT_FAILURE);
	}
	else if (check_map_is_rectangular(init_data) == false)
	{
		ft_putstr_fd("Error\nLa map n'est pas rectangulaire\n", 2);
		free_parsing(init_data);
		exit(EXIT_FAILURE);
	}
	else if (check_map_only_charset(init_data) == false)
	{
		ft_putstr_fd("Error\nLa map est invalide\n", 2);
		free_parsing(init_data);
		exit(EXIT_FAILURE);
	}
}
void check_parsing_alt(t_init *init_data)
{
	if (map_is_enclosed_by_wall(init_data, 0, 0) == false)
	{
		ft_putstr_fd("Error\nLa map n'est pas entoure de mur\n", 2);
		free_parsing(init_data);
		exit(EXIT_FAILURE);
	}
	else if (check_E_P_C(init_data) == false)
	{
		ft_putstr_fd("Error\nIl n'y a une erreur de sortie, de player ou de collectibles\n", 2);
		free_parsing(init_data);
		exit(EXIT_FAILURE);
	}
	else if (flood_fill_map(init_data) == false)
	{
		ft_putstr_fd("Error\nLa map n'est pas realisable\n", 2);
		free_parsing(init_data);
		exit(EXIT_FAILURE);
	}
}
