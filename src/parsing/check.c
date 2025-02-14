/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomont <lomont@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 01:54:00 by lomont            #+#    #+#             */
/*   Updated: 2025/02/14 03:21:28 by lomont           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void check_all_parsing(t_init *init_data)
{
	check_parsing(init_data);
}
void check_parsing(t_init *init_data)
{
	if (check_extension_map(init_data) == false)
	{
		ft_printf("PAS LA BONNE EXTENSION");
		free_parsing(init_data);
		exit(EXIT_FAILURE);
	}
	else if (check_map_is_rectangular(init_data) == false)
	{
		ft_printf("MAP PAS RECTANGULAIRE");
		free_parsing(init_data);
		exit(EXIT_FAILURE);
	}
	else if (check_map_is_not_empty(init_data) == false)
	{
		ft_printf("MAP VIDE\n");
		free_parsing(init_data);
		exit(EXIT_FAILURE);
	}
	else if (check_map_only_charset(init_data) == false)
	{
		ft_printf("MAP INVALIDE\n");
		free_parsing(init_data);
		exit(EXIT_FAILURE);
	}
	check_parsing_alt(init_data);
}
void check_parsing_alt(t_init *init_data)
{
	if (map_is_enclosed_by_wall(init_data, 0, 0) == false)
	{
		ft_printf("MAP NEST PAS ENTOURE DE MUR\n");
		free_parsing(init_data);
		exit(EXIT_FAILURE);
	}
	else if (check_E_P_C(init_data) == false)
	{
		ft_printf("CHECK E P C INVALIDE\n");
		free_parsing(init_data);
		exit(EXIT_FAILURE);
	}
	else if (flood_fill_map(init_data) == false)
	{
		ft_printf("MAP NON REALISABLE\n");
		free_parsing(init_data);
		exit(EXIT_FAILURE);
	}
}
