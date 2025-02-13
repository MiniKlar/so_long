/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomont <lomont@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 23:33:12 by lomont            #+#    #+#             */
/*   Updated: 2025/02/13 03:51:58 by lomont           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

//TODO CLEAR MAP_NAME malloc

t_init *init_struct(void)
{
	t_init	*new_node;

	new_node = malloc(sizeof(t_init));
	if (!new_node)
		return (NULL);
	new_node->fd = 0;
	new_node->map_name = NULL;
	new_node->tab = NULL;
	return (new_node);
}
t_data *init_game_data(void)
{
	t_data	*new_node;

	new_node = malloc(sizeof(t_data));
	if (!new_node)
		return (NULL);
	return (new_node);
}

void init_all(int argc, char **argv, t_init *init_data)
{
	init_map(argc, argv, init_data);
	init_fd(init_data);
	init_data->collectibles = 0;
	init_data->exit = 0;
	init_data->N_exit = 0;
	init_data->N_collectibles = 0;
	init_data->x = 0;
	init_data->y = 0;
}

void init_map(int argc, char **argv, t_init *init_data)
{
	char *map_name;

	map_name = ft_strdup(argv[argc - 1]);
	if (!map_name)
		exit(EXIT_FAILURE);
	init_data->map_name = map_name;
}

void init_fd(t_init *init_data)
{
	int fd;

	fd = open(init_data->map_name, O_RDONLY);
	init_data->fd = fd;
}
