/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomont <lomont@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 16:44:14 by lomont            #+#    #+#             */
/*   Updated: 2025/02/16 14:06:48 by lomont           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	print_map(char **map)
{
	int	y;

	y = 0;
	while (map[y])
	{
		ft_printf("%s\n", map[y]);
		y++;
	}
	ft_printf("\nMAP PRINT\n");
}
