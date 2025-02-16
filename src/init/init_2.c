/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomont <lomont@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 23:21:52 by lomont            #+#    #+#             */
/*   Updated: 2025/02/16 01:00:59 by lomont           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

t_struct *init_ptr_to_struct(void)
{
	t_struct	*new_node;

	new_node = malloc(sizeof(t_struct));
	if (!new_node)
		return (NULL);
	new_node->mlx = NULL;
	new_node->struct_data = NULL;
	new_node->struct_init = NULL;
	return (new_node);
}

list	*initalisation(void)
{
	list *liste = malloc(sizeof(*liste));
	t_C_info *element = malloc(sizeof(*element));

	if (liste == NULL || element == NULL)
		exit(EXIT_FAILURE);
	element->index = 0;
	element->x = 0;
	element->y = 0;
	element->next = NULL;
	liste->node = element;

	return (liste);
}
void insertion(list *liste, int C_count, int x, int y)
{
	t_C_info *element = malloc(sizeof(*element));

	if (element == NULL)
		exit(EXIT_FAILURE);
	element->index = C_count;
	element->x = x;
	element->y = y;
	element->next = liste->node;
	liste->node = element;
}
void free_list(list *liste)
{
	t_C_info *tmp;

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
