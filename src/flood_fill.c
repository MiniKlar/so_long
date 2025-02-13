/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomont <lomont@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 21:08:12 by lomont            #+#    #+#             */
/*   Updated: 2025/02/13 00:24:27 by lomont           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

bool flood_fill_map(t_init *init_data)
{
	char **tableau;

	tableau = init_data->tab;
	start_position_floodfill(init_data, tableau);
	set_next_position_floodfill(tableau, init_data);
	tableau = flood(init_data,tableau, init_data->x, init_data->y);
	print_map(tableau);
	if (init_data->N_exit == init_data->exit && init_data->N_collectibles == init_data->collectibles)
		return (true);
	else
		return (false);
}
void start_position_floodfill(t_init *init_data, char **tableau)
{
	int x;
	int y;

	x = init_data->x;
	y = init_data->y;
	while (tableau[x] != 0 && tableau[x][y] != 'P')
	{
		y = 0;
		while (tableau[x][y] != '\0' && tableau[x][y] != 'P')
			y++;
		if (tableau[x][y] == 'P')
			;
		else
			x++;
	}
	init_data->x = x;
	init_data->y = y;
}

char **set_next_position_floodfill(char **tableau, t_init *init_data)
{
	int x;
	int y;

	x = init_data->x;
	y = init_data->y;
	if (tableau[x + 1][y] == '0' || tableau[x + 1][y] == 'E' || tableau[x + 1][y] == 'C')
		init_data->x++;
	if (tableau[x - 1][y] == '0' || tableau[x - 1][y] == 'E' || tableau[x - 1][y] == 'C')
		init_data->x--;
	if (tableau[x][y + 1] == '0' || tableau[x][y + 1] == 'E' || tableau[x][y + 1] == 'C')
		init_data->y++;
	if (tableau[x][y - 1] == '0' || tableau[x][y - 1] == 'E' || tableau[x][y - 1] == 'C')
		init_data->y--;
	return (tableau);
}

char **flood(t_init *init_data,char **tableau, int x, int y)
{
    if (tableau[x][y] == 'E' || tableau[x][y] == '0' || tableau[x][y] == 'C')
	{
		if (tableau[x][y] == 'E')
			init_data->N_exit++;
		else if (tableau[x][y] == 'C')
			init_data->N_collectibles++;
		tableau[x][y] = 'V';
        flood(init_data, tableau, x + 1, y);
        flood(init_data, tableau, x - 1, y);
        flood(init_data, tableau, x, y + 1);
        flood(init_data, tableau, x, y - 1);
    }
	return (tableau);
}
