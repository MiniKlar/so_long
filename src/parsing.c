/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomont <lomont@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 07:54:51 by lomont            #+#    #+#             */
/*   Updated: 2025/02/12 04:32:06 by lomont           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

//TODO VERIFIER SI ON PEUT PASSER PORTE (condition en plus pour qu'on puisse marcher dessus)
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
	//printf("%zu", ft_strlen(tab[0]));
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
	{
		return (true);
	}
	else
		return (false);
}

void fill_tab(t_init *init_data)
{
	char *line;
	char *map_in_line;
	char *temp;

	line = get_next_line(init_data->fd);
	if (!line)
	{
		printf("Error\nMap is empty\n");
		free_struct(init_data);
		exit(EXIT_FAILURE);
	}
	map_in_line = ft_strdup("");
	while (line)
	{
		temp = map_in_line;
		map_in_line = ft_strjoin(map_in_line, line);
		if (!map_in_line)
		{
			free_struct(init_data);
			exit(EXIT_FAILURE);
		}
		free(temp);
		free(line);
		line = get_next_line(init_data->fd);
	}
	init_data->tab = ft_split(map_in_line, '\n');
	free(map_in_line);
}

bool check_map_only_charset(t_init *init_data)
{
	char **tableau;
	int i;
	int k;

	ft_printf("TU ES LA only charset\n");
	tableau = init_data->tab;
	i = 0;
	while (tableau[i] != 0)
	{
		k = 0;
		while(tableau[i][k] != '\0')
		{
			if (ft_isalnum(tableau[i][k]) == 0)
			{
				ft_printf("\nMAP INVALIDE ICI :%d et voici le char invalide :%c |\n", k, ft_isalnum(tableau[i][k]));
				return (false);
			}
			else
			{
				//ft_printf("is_alnum = %d | ",ft_isalnum(tableau[i][k]));
				k++;
			}
		}
		//ft_printf("\nk = %d\n", k);
		i++;
	}
	return (true);
}

bool map_is_enclosed_by_wall(t_init *init_data)
{
	char **tableau = init_data->tab;
	int x = 0; int y = 0; int x_max = 0; int y_max = 0;
	bool lol;

	while (tableau[x][y] != '\0')
		y++;
	y_max = y;
	y = 0;
	while(tableau[x] != 0)
		x++;
	x_max = x;
	x = 0;
	printf("\n\nx_max = %d & y_max = %d\n\n", x_max, y_max);
	if (check_if_wall(tableau[x][y]) == true && check_if_wall(tableau[x][y_max - 1]) == true
		&& check_if_wall(tableau[x_max - 1][y]) == true && check_if_wall(tableau[x_max - 1][y_max - 1]) == true)
	{
		printf("LES ANGLES DE LA MAP SONT BONS\n");
	}
	else
		printf("LES ANGLES DE LA MAP SONT PAS BONS\n");
	while (tableau[x][y] != '\0')
	{
		if (check_if_wall(tableau[x][y]) == true)
			lol = true;
		else
		{
			lol = false;
			break;
		}
		y++;
	}
	y = 0;
	while (tableau[x] != 0 && lol == true)
	{
		if (check_if_wall(tableau[x][y]) == true)
			lol = true;
		else
		{
			lol = false;
			break;
		}
		x++;
	}
	y = 0;
	while (tableau[x_max - 1][y] != '\0' && lol == true)
	{
		if (check_if_wall(tableau[x_max - 1][y]) == true)
			lol = true;
		else
			lol = false;
		y++;
	}
	x = 0;
	while (tableau[x] != 0 && lol == true)
	{
		if (check_if_wall(tableau[x][y_max - 1]) == true)
			lol = true;
		else
			lol = false;
		x++;
	}
	if (lol == true)
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

bool check_if_wall(char c)
{
	if (c == '1')
		return (true);
	else
		return (false);
}

bool check_E_P_C(t_init *init_data)
{
	char **tableau;
	int P;
	int x;
	int y;

	P = 0;
	x = 0;
	y = 0;
	tableau = init_data->tab;
	while (tableau[x] != 0)
	{
		y = 0;
		while (tableau[x][y] != '\0')
		{
			if (tableau[x][y] == 'E')
				init_data->exit++;
			else if (tableau[x][y] == 'P')
				P++;
			else if (tableau[x][y] == 'C')
			{
				ft_printf("\nLOL JAI TROUVE UN COLLECTIBLE\n");
				init_data->collectibles++;
			}
			y++;
		}
		x++;
	}
	ft_printf("\nVOICI E: %d | VOICI P: %d | VOICI C: %d\n", init_data->exit, P, init_data->collectibles);
	if (init_data->exit != 1 || P != 1)
	{
		if (init_data->exit > 1)
			ft_printf("\ntrop d'exit\n");
		else
			ft_printf("\ntrop de start position\n");
		return (false);
	}
	else if (init_data->collectibles < 1)
	{
		ft_printf("\nPas assez de collectibles\n");
		return (false);
	}
	return (true);
}

bool flood_fill_map(t_init *init_data)
{
	char **tableau;
	int x;
	int y;

	x = 0;
	y = 0;
	tableau = init_data->tab;
	while (tableau[x] != 0 && tableau[x][y] != 'P')
	{
		y = 0;
		while (tableau[x][y] != '\0' && tableau[x][y] != 'P')
		{
			y++;
		}
		if (tableau[x][y] == 'P')
			;
		else
			x++;
	}
	printf("la start position est situe a x: %d et y: %d et le char est : %c\n", x, y, tableau[x][y]);
	if (tableau[x + 1][y] == '0' || tableau[x + 1][y] == 'E')
	{
		x++;
		tableau = flood(init_data,tableau, x, y);
	}
	if (tableau[x - 1][y] == '0' || tableau[x - 1][y] == 'E')
	{
		x--;
		tableau = flood(init_data,tableau, x, y);
	}
	if (tableau[x][y + 1] == '0' || tableau[x][y + 1] == 'E')
	{
		y++;
		tableau = flood(init_data,tableau, x, y);
	}
	if (tableau[x][y - 1] == '0' || tableau[x][y - 1] == 'E')
	{
		y--;
		tableau = flood(init_data,tableau, x, y);
	}
	print_map(tableau);
	printf("\n%d et %d et %d et %d\n", init_data->N_exit, init_data->exit, init_data->N_collectibles, init_data->collectibles);
	if (init_data->N_exit == init_data->exit && init_data->N_collectibles == init_data->collectibles)
	{
		printf("\nMAP EST REALISABLE\n");
		return (true);
	}
	else
		return (false);
}
char **flood(t_init *init_data,char **tableau, int x, int y)
{
	//printf("\ndans le flood, tableau = %c\n", tableau[x][y]);
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
