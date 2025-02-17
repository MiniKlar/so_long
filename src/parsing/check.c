/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomont <lomont@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 01:54:00 by lomont            #+#    #+#             */
/*   Updated: 2025/02/17 22:23:46 by lomont           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	check_all_parsing(t_struct *all_struct)
{
	check_parsing(all_struct);
	check_parsing_alt(all_struct);
	if (check_map_empty_space(all_struct->init) == false)
	{
		ft_putstr_fd("Error\nEMPTY SPACE IN THE MIDDLE OF THE MAP\n", 2);
		free_struct(all_struct);
		exit(EXIT_FAILURE);
	}
}

void	check_parsing(t_struct *all_struct)
{
	if (check_extension_map(all_struct->init) == false)
	{
		ft_putstr_fd("Error\nWrong file extension\n", 2);
		free_struct(all_struct);
		exit(EXIT_FAILURE);
	}
	else if (check_map_is_not_empty(all_struct->init) == false)
	{
		ft_putstr_fd("Error\nEmpty map\n", 2);
		free_struct(all_struct);
		exit(EXIT_FAILURE);
	}
	else if (check_map_is_rectangular(all_struct->init) == false)
	{
		ft_putstr_fd("Error\nMap is not rectangular\n", 2);
		free_struct(all_struct);
		exit(EXIT_FAILURE);
	}
	else if (check_map_only_charset(all_struct->init) == false)
	{
		ft_putstr_fd("Error\nMap invalid\n", 2);
		free_struct(all_struct);
		exit(EXIT_FAILURE);
	}
}

void	check_parsing_alt(t_struct *all_struct)
{
	if (map_is_enclosed_by_wall(all_struct->init) == false)
	{
		ft_putstr_fd("Error\nEdge or outline of the map are not wall\n", 2);
		free_struct(all_struct);
		exit(EXIT_FAILURE);
	}
	else if (check_e_p_c(all_struct->init) == false)
	{
		ft_putstr_fd("Error\nExit, player or items error\n", 2);
		free_struct(all_struct);
		exit(EXIT_FAILURE);
	}
	else if (flood_fill_map(all_struct->init) == false)
	{
		ft_putstr_fd("Error\nMap is not realisable\n", 2);
		free_struct(all_struct);
		exit(EXIT_FAILURE);
	}
	else if (all_struct->init->y_max * SIZE > 1920
		|| all_struct->init->x_max * SIZE > 1024)
	{
		ft_putstr_fd("Error\nMap is too big, out of range of the monitor\n", 2);
		free_struct(all_struct);
		exit(EXIT_FAILURE);
	}
}
