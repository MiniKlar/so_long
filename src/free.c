/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomont <lomont@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 02:34:19 by lomont            #+#    #+#             */
/*   Updated: 2025/02/14 04:06:15 by lomont           ###   ########.fr       */
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
void free_all(void *param)
{
	t_struct *all_struct = param;
	free_parsing(all_struct->struct_init);
	free_mlx(all_struct->mlx);
	free_struct(all_struct);
	exit(EXIT_SUCCESS);
}

void free_parsing(t_init *init_data)
{
	free_map(init_data->tab);
	free(init_data->map_name);
	free(init_data);
}
void free_struct(t_struct *all_struct)
{
	free(all_struct->struct_data);
	//free(all_struct->mlx);
	free(all_struct);
}
void free_mlx(mlx_t *mlx)
{
	printf("LOL\n\n\n");
	mlx_close_window(mlx);
	mlx_terminate(mlx);
}
