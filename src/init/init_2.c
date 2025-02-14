/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomont <lomont@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 23:21:52 by lomont            #+#    #+#             */
/*   Updated: 2025/02/13 23:33:30 by lomont           ###   ########.fr       */
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
