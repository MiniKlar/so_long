/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomont <lomont@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 02:34:19 by lomont            #+#    #+#             */
/*   Updated: 2025/02/15 02:12:12 by lomont           ###   ########.fr       */
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
	free_mlx(all_struct);
	free_struct(all_struct);
	exit(EXIT_SUCCESS);
}

void free_parsing(t_init *init_data)
{
	free_map(init_data->tab);
	free_map(init_data->flood_tab);
	free(init_data->map_name);
	free(init_data);
}
void free_struct(t_struct *all_struct)
{
	mlx_delete_texture(all_struct->struct_data->C4);
	mlx_delete_texture(all_struct->struct_data->exit);
	mlx_delete_texture(all_struct->struct_data->player);
	mlx_delete_texture(all_struct->struct_data->wall);
	mlx_delete_texture(all_struct->struct_data->floor);
	free(all_struct->struct_data);
	free(all_struct);
}
void free_mlx(t_struct *all_struct)
{
	printf("ESCAPE\n\n\n");
	mlx_close_window(all_struct->mlx);
	mlx_delete_image(all_struct->mlx, all_struct->struct_data->img_floor);
	mlx_delete_image(all_struct->mlx, all_struct->struct_data->img_C4);
	mlx_delete_image(all_struct->mlx, all_struct->struct_data->img_exit);
	mlx_delete_image(all_struct->mlx, all_struct->struct_data->img_player);
	mlx_delete_image(all_struct->mlx, all_struct->struct_data->img_wall);
	mlx_terminate(all_struct->mlx);
}
