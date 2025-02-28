/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miniklar <miniklar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 23:33:12 by lomont            #+#    #+#             */
/*   Updated: 2025/02/28 01:03:19 by miniklar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

//TODO CLEAR MAP_NAME malloc [v]

t_init	*init_struct(void)
{
	t_init	*new_node;

	new_node = malloc(sizeof(t_init));
	if (!new_node)
		return (NULL);
	new_node->fd = 0;
	new_node->map_name = NULL;
	new_node->tab = NULL;
	new_node->flood_tab = NULL;
	return (new_node);
}

t_data	*init_game_data(void)
{
	t_data	*new_node;

	new_node = malloc(sizeof(t_data));
	if (!new_node)
		return (NULL);
	new_node->c4 = NULL;
	new_node->c4_red = NULL;
	new_node->exit = NULL;
	new_node->floor = NULL;
	new_node->player = NULL;
	new_node->player_right = NULL;
	new_node->wall = NULL;
	new_node->ct = NULL;
	new_node->img_c4 = NULL;
	new_node->img_c4_red = NULL;
	new_node->img_exit = NULL;
	new_node->img_floor = NULL;
	new_node->img_player = NULL;
	new_node->img_player_right = NULL;
	new_node->img_wall = NULL;
	new_node->img_ct = NULL;
	new_node->str_counter = NULL;
	return (new_node);
}

void	init_all(int argc, char **argv, t_init *init_data)
{
	init_map_name(argc, argv, init_data);
	init_fd(init_data);
	init_data->collectibles = 0;
	init_data->exit = 0;
	init_data->n_exit = 0;
	init_data->start_position = 0;
	init_data->n_collectibles = 0;
	init_data->x = 0;
	init_data->y = 0;
	init_data->x_max = 0;
	init_data->y_max = 0;
	init_data->player_pos_x = 0;
	init_data->player_pos_y = 0;
	init_data->items_collect = 0;
	init_data->item_counter = 0;
	init_data->mov_counter = 0;
	init_data->prev_mov_counter = 0;
	init_data->sprite_anim = 0;
}

void	init_map_name(int argc, char **argv, t_init *init_data)
{
	char	*map_name;

	map_name = ft_strdup(argv[argc - 1]);
	if (!map_name)
		exit(EXIT_FAILURE);
	init_data->map_name = map_name;
}

void	init_fd(t_init *init_data)
{
	int	fd;

	fd = open(init_data->map_name, O_RDONLY);
	init_data->fd = fd;
}
