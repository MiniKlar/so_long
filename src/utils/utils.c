/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomont <lomont@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 20:59:31 by lomont            #+#    #+#             */
/*   Updated: 2025/02/13 02:10:39 by lomont           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

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
bool check_if_wall(char c)
{
	if (c == '1')
		return (true);
	else
		return (false);
}
int	ft_ischarnum(int c)
{
	if (c == 'P' || c == 'E' || c == 'C' || ft_isdigit(c))
		return (1);
	else
		return (0);
}
