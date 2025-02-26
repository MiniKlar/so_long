/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomont <lomont@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 16:44:14 by lomont            #+#    #+#             */
/*   Updated: 2025/02/25 23:45:37 by lomont           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	print_map(char **map)
{
	int	y;

	y = 0;
	while (map[y])
	{
		ft_printf("%s\n", map[y]);
		y++;
	}
	ft_printf("\nMAP PRINT\n");
}

void	counter_to_window(t_struct *all_struct)
{
	char	*str;

	str = ft_strjoin("counter :", ft_itoa(all_struct->init->mov_counter));
	if (all_struct->data->str_counter != NULL)
		mlx_delete_image(all_struct->mlx, all_struct->data->str_counter);
	all_struct->data->str_counter = mlx_put_string(all_struct->mlx, str, 0, 0);
	all_struct->init->prev_mov_counter = all_struct->init->mov_counter;
	free(str);
}
