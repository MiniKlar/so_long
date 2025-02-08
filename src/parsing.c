/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomont <lomont@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 07:54:51 by lomont            #+#    #+#             */
/*   Updated: 2025/02/08 20:16:23 by lomont           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int init_map(int argc, char **argv)
{
	int fd;
	char *map_name;

	map_name = ft_strjoin("./maps/", argv[argc - 1]);
	fd = open(map_name, O_RDONLY);
	free(map_name);
	return (fd);
}

bool check_extension_map(int argc, char **argv, int fd)
{
	char *map_name;
	int i;

	map_name = argv[argc - 1];
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
bool check_map_is_rectangular(int fd)
{
	char *first_line = get_next_line(fd);
	char *line = get_next_line(fd);
	int i, count;
	i = 0;
	count = 2;
	while (ft_strchr(line, '\n') != NULL)
	{
		if (ft_strlen(first_line) == ft_strlen(line))
		{
			ft_printf("1ere ligne %d & %d ligne %d\n", ft_strlen(first_line), count, ft_strlen(line));
			line = get_next_line(fd);
			i++;
			count++;
		}
		else
			return (false);
	}
	//ft_printf("1ere ligne %s & derniere ligne %s\n", first_line, line);
	ft_printf("1ere ligne %d & derniere ligne %d\n", ft_strlen(first_line), ft_strlen(line) + 1);
	if (ft_strlen(first_line) == ft_strlen(line) + 1)
	{
		ft_printf("1ere ligne %d & %d ligne %d\n", ft_strlen(first_line), count, ft_strlen(line) + 1);
	}
	else
		return (false);
	return (true);
}

char **fill_tab_map(int fd)
{ 
	char *tab;
	char *line;
	char *tmp;
	char **tableau;
	int i;
	
	i = 0;
	tab = get_next_line(fd);
	while (i < 4)
	{
		line = get_next_line(fd);
		tmp = ft_strjoin(tab, line);
		tab = tmp;
		tmp = NULL;
		i++;
	}
	tableau = ft_split(tab, '\n');
	free(tab);
	free(tmp);
	free(line);
	return (tableau);
}
