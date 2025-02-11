/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomont <lomont@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 02:34:19 by lomont            #+#    #+#             */
/*   Updated: 2025/02/11 02:37:02 by lomont           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_map(char **map)
{
	int	y;

	if (!map)
		return ;
	y = 0;
	while (map[y])
	{
		free(map[y]);
		y++;
	}
	free(map);
}
void free_struct(t_init *init_data)
{
	free_map(init_data->tab);
	free(init_data->map_name);
	free(init_data);
}
