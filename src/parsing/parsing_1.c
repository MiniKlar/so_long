/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomont <lomont@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 00:50:42 by lomont            #+#    #+#             */
/*   Updated: 2025/02/16 10:35:06 by lomont           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

bool	check_rectangle_length(bool is_wall, char **tableau, int y, int y_max)
{
	int	x;

	x = 0;
	while (tableau[x] != 0 && is_wall == true)
	{
		if (check_if_wall(tableau[x][y]) == true)
			is_wall = true;
		else
			return (false);
		x++;
	}
	x = 0;
	while (tableau[x] != 0 && is_wall == true)
	{
		if (check_if_wall(tableau[x][y_max - 1]) == true)
			is_wall = true;
		else
			return (false);
		x++;
	}
	return (is_wall);
}

bool	check_rectangle_width(bool is_wall, char **tableau, int x, int x_max)
{
	int	y;

	y = 0;
	while (tableau[x_max - 1][y] != '\0' && is_wall == true)
	{
		if (check_if_wall(tableau[x_max - 1][y]) == true)
			is_wall = true;
		else
			return (false);
		y++;
	}
	y = 0;
	while (tableau[x][y] != '\0')
	{
		if (check_if_wall(tableau[x][y]) == true)
			is_wall = true;
		else
			return (false);
		y++;
	}
	return (is_wall);
}

bool	check_e_p_c(t_init *init_data)
{
	char	**tableau;

	tableau = init_data->tab;
	check_collectibles_tab(init_data, tableau);
	if (init_data->exit != 1 || init_data->start_position != 1
		|| init_data->collectibles < 1)
		return (false);
	return (true);
}

void	check_collectibles_tab(t_init *init_data, char **tableau)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (tableau[x] != 0)
	{
		y = 0;
		while (tableau[x][y] != '\0')
		{
			if (tableau[x][y] == 'E')
				init_data->exit++;
			else if (tableau[x][y] == 'P')
			{
				init_data->start_position++;
				init_data->player_pos_x = x;
				init_data->player_pos_y = y;
			}
			else if (tableau[x][y] == 'C')
				init_data->collectibles++;
			y++;
		}
		x++;
	}
}
