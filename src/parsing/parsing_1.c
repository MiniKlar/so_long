/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomont <lomont@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 00:50:42 by lomont            #+#    #+#             */
/*   Updated: 2025/02/13 01:44:34 by lomont           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

bool check_rectangle_length(bool is_wall, char **tableau, int x, int y, int y_max)
{
	while (tableau[x] != 0 && is_wall == true)
	{
		if (check_if_wall(tableau[x][y]) == true)
			is_wall = true;
		else
		{
			is_wall = false;
			break;
		}
		x++;
	}
	x = 0;
	while (tableau[x] != 0 && is_wall == true)
	{
		if (check_if_wall(tableau[x][y_max - 1]) == true)
			is_wall = true;
		else
			is_wall = false;
		x++;
	}
	return (is_wall);
}
bool check_rectangle_width(bool is_wall, char **tableau, int x, int y, int x_max)
{
	while (tableau[x_max - 1][y] != '\0' && is_wall == true)
	{
		if (check_if_wall(tableau[x_max - 1][y]) == true)
			is_wall = true;
		else
			is_wall = false;
		y++;
	}
	y = 0;
	while (tableau[x][y] != '\0')
	{
		if (check_if_wall(tableau[x][y]) == true)
			is_wall = true;
		else
		{
			is_wall = false;
			break;
		}
		y++;
	}
	return (is_wall);
}
