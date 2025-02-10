/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomont <lomont@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 07:54:51 by lomont            #+#    #+#             */
/*   Updated: 2025/02/11 00:16:12 by lomont           ###   ########.fr       */
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
	i = 0;
	while (tab[i] != 0 && tab[i + 1])
	{
		if (ft_strlen(tab[i]) == ft_strlen(tab[i + 1]))
			;
		else
			return (false);
		i++;
	}
	return (true);
}

void fill_tab_map(t_init *init_data)
{
	char *tab;
	char *line;
	char *tmp;
	int i;

	i = 0;
	tab = get_next_line(init_data->fd);
	if (!tab)
	{
		ft_printf("TAB RIEN\n");
		exit(EXIT_FAILURE);
	}
	while (i < 4)
	{
		line = get_next_line(init_data->fd);
		if (!line)
		{
			ft_printf("LINE RIEN\n");
			exit(EXIT_FAILURE);
		}
		//printf("tab:%s et line:%s\n", tab, line);
		tmp = ft_strjoin(tab, line);
		tab = tmp;
		tmp = NULL;
		i++;
	}
	init_data->tab = ft_split(tab, '\n');
	free(tab);
	free(tmp);
	free(line);
}
