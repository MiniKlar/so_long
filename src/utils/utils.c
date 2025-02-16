/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomont <lomont@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 20:59:31 by lomont            #+#    #+#             */
/*   Updated: 2025/02/16 07:36:18 by lomont           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

//TODO REVOIR FILL TAB POUR REMPLIR FLOOD FILL [v]
// ft_strnstr()

bool	fill_tab(t_init *init_data)
{
	char	*line;
	char	*map_in_line;
	char	*temp;

	line = get_next_line(init_data->fd);
	if (!line)
		return (free(line), false);
	map_in_line = ft_strdup("");
	while (line)
	{
		temp = map_in_line;
		map_in_line = ft_strjoin(map_in_line, line);
		if (!map_in_line)
			return (free(map_in_line), free(line), false);
		free(temp);
		free(line);
		line = get_next_line(init_data->fd);
	}
	init_data->tab = ft_split(map_in_line, '\n');
	init_data->flood_tab = ft_split(map_in_line, '\n');
	free(map_in_line);
	return (true);
}

bool	check_if_wall(char c)
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

int	ft_search_items_instances(t_struct *all_struct, int x, int y)
{
	while (all_struct->first_node->node != NULL)
	{
		if (all_struct->first_node->node->x == x && all_struct->first_node
			->node->y == y)
			return (all_struct->first_node->node->index);
		else
			all_struct->first_node->node = all_struct->first_node->node->next;
	}
	return (0);
}
