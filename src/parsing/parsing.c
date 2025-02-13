/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomont <lomont@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 07:54:51 by lomont            #+#    #+#             */
/*   Updated: 2025/02/13 01:44:40 by lomont           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

//TODO VERIFIER SI ON PEUT PASSER PORTE (condition en plus pour qu'on puisse marcher dessus) [x]

bool check_extension_map(t_init *init_data)
{
	char *map_name;
	int fd;
	int i;

	map_name = init_data->map_name;
	fd = init_data->fd;
	i = ft_strlen(map_name);
	if (fd == -1)
		return (false);
	if (ft_strnstr(map_name, ".ber", i) != 0)
	{
		if (ft_strncmp(&map_name[i - 4], ".ber", 4) != 0)
			return (false);
		return (true);
	}
	else
		return(false);
}
bool check_map_is_rectangular(t_init *init_data)
{
	char **tab;
	int i;

	tab = init_data->tab;
	if (tab)
	{
		i = 0;
		while (tab[i] != 0 && tab[i + 1])
		{
			if (ft_strlen(tab[i]) == ft_strlen(tab[i + 1]))
				;
			else
				return (false);
			i++;
		}
	}
	return (true);
}
bool check_map_is_not_empty(t_init *init_data)
{
	char **map;

	map = init_data->tab;
	if (init_data->tab != NULL)
		return (true);
	else
		return (false);
}
bool check_map_only_charset(t_init *init_data)
{
	char **tableau;
	int i;
	int k;

	tableau = init_data->tab;
	i = 0;
	while (tableau[i] != 0)
	{
		k = 0;
		while(tableau[i][k] != '\0')
		{
			if (ft_ischarnum(tableau[i][k]) == 0)
				return (false);
			else
				k++;
		}
		i++;
	}
	return (true);
}

bool map_is_enclosed_by_wall(t_init *init_data, int x_max, int y_max)
{
	char **tableau = init_data->tab;
	bool is_wall;
	int x;
	int y;

	x = 0;
	y = 0;
	is_wall = true;
	while (tableau[x][y] != '\0')
		y++;
	y_max = y;
	y = 0;
	while(tableau[x] != 0)
		x++;
	x_max = x;
	x = 0;
	is_wall = check_rectangle_length(is_wall, tableau, x, y, y_max);
	is_wall = check_rectangle_width(is_wall, tableau, x, y, x_max);
	if (is_wall == true)
	{
		printf("\nLES CONTOURS DE LA MAP SONT BONS\n");
		return (true);
	}
	else
	{
		printf("\n!!!!!!!!!!!LES CONTOURS DE LA MAP SONT PAS BONS !!!!!!!!!!\n");
		return (false);
	}
}

bool check_E_P_C(t_init *init_data)
{
	char **tableau;

	tableau = init_data->tab;
	check_collectibles_tab(init_data, tableau);
	if (init_data->exit != 1 || init_data->start_position != 1 || init_data->collectibles < 1)
		return (false);
	return (true);
}
void check_collectibles_tab(t_init *init_data ,char **tableau)
{
	int x;
	int y;

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
				init_data->start_position++;
			else if (tableau[x][y] == 'C')
				init_data->collectibles++;
			y++;
		}
		x++;
	}
}
