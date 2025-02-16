/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomont <lomont@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 01:54:00 by lomont            #+#    #+#             */
/*   Updated: 2025/02/16 12:18:50 by lomont           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	check_all_parsing(t_struct *all_struct)
{
	check_parsing(all_struct);
	check_parsing_alt(all_struct);
}

void	check_parsing(t_struct *all_struct)
{
	if (check_extension_map(all_struct->init) == false)
	{
		ft_putstr_fd("Error\nPas la bonne extension de fichier\n", 2);
		free_struct(all_struct);
		exit(EXIT_FAILURE);
	}
	else if (check_map_is_not_empty(all_struct->init) == false)
	{
		ft_putstr_fd("Error\nLa map est vide\n", 2);
		free_struct(all_struct);
		exit(EXIT_FAILURE);
	}
	else if (check_map_is_rectangular(all_struct->init) == false)
	{
		ft_putstr_fd("Error\nLa map n'est pas rectangulaire\n", 2);
		free_struct(all_struct);
		exit(EXIT_FAILURE);
	}
	else if (check_map_only_charset(all_struct->init) == false)
	{
		ft_putstr_fd("Error\nLa map est invalide\n", 2);
		free_struct(all_struct);
		exit(EXIT_FAILURE);
	}
}

void	check_parsing_alt(t_struct *all_struct)
{
	if (map_is_enclosed_by_wall(all_struct->init) == false)
	{
		ft_putstr_fd("Error\nLa map n'est pas entoure de mur\n", 2);
		free_struct(all_struct);
		exit(EXIT_FAILURE);
	}
	else if (check_e_p_c(all_struct->init) == false)
	{
		ft_putstr_fd("Error\nErreur de sortie, player ou items\n", 2);
		free_struct(all_struct);
		exit(EXIT_FAILURE);
	}
	else if (flood_fill_map(all_struct->init) == false)
	{
		ft_putstr_fd("Error\nLa map n'est pas realisable\n", 2);
		free_struct(all_struct);
		exit(EXIT_FAILURE);
	}
	else if (all_struct->init->y_max * SIZE > 1920
		|| all_struct->init->x_max * SIZE > 1024)
	{
		ft_putstr_fd("Error\nLa map est trop grande\n", 2);
		free_struct(all_struct);
		exit(EXIT_FAILURE);
	}
}
