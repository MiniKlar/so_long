/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomont <lomont@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 07:54:51 by lomont            #+#    #+#             */
/*   Updated: 2025/02/11 22:45:46 by lomont           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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
	printf("%zu", ft_strlen(tab[0]));
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
