/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomont <lomont@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 23:21:52 by lomont            #+#    #+#             */
/*   Updated: 2025/02/16 13:47:55 by lomont           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

t_struct	*init_ptr_to_struct(void)
{
	t_struct	*new_node;

	new_node = malloc(sizeof(t_struct));
	if (!new_node)
		return (NULL);
	new_node->mlx = NULL;
	new_node->data = NULL;
	new_node->init = NULL;
	return (new_node);
}

t_C_list	*initalisation(void)
{
	t_C_list	*liste;
	t_C_info	*element;

	liste = malloc(sizeof(*liste));
	element = malloc(sizeof(*element));
	if (liste == NULL || element == NULL)
		exit(EXIT_FAILURE);
	element->index = 0;
	element->x = 0;
	element->y = 0;
	element->next = NULL;
	liste->node = element;
	return (liste);
}

void	insertion(t_C_list *liste, int C_count, int x, int y)
{
	t_C_info	*element;

	element = malloc(sizeof(*element));
	if (element == NULL)
		exit(EXIT_FAILURE);
	element->index = C_count;
	element->x = x;
	element->y = y;
	element->next = liste->node;
	liste->node = element;
}

void	free_list(t_C_list *liste)
{
	t_C_info	*tmp;

	if (liste == NULL)
		exit(EXIT_FAILURE);
	while (liste->node->next != NULL)
	{
		tmp = liste->node->next;
		free(liste->node);
		liste->node = tmp;
	}
	free(liste->node);
	free(liste);
}

t_struct	*init_structure(void)
{
	t_struct	*all_struct;
	t_data		*game_data;
	t_init		*init_data;
	t_C_list	*first_node;

	all_struct = init_ptr_to_struct();
	init_data = init_struct();
	game_data = init_game_data();
	first_node = initalisation();
	all_struct->init = init_data;
	all_struct->data = game_data;
	all_struct->first_node = first_node;
	return (all_struct);
}
