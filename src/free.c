/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomont <lomont@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 02:34:19 by lomont            #+#    #+#             */
/*   Updated: 2025/02/26 02:44:11 by lomont           ###   ########.fr       */
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

void	free_all(void *param)
{
	t_struct	*all_struct;

	all_struct = param;
	free_mlx(all_struct);
	free_struct(all_struct);
	exit(EXIT_SUCCESS);
}

// void free_parsing(t_init *init_data)
// {
// 	if (init_data->fd > -1)
// 		close(init_data->fd);
// 	free_map(init_data->tab);
// 	free_map(init_data->flood_tab);
// 	free(init_data->map_name);
// 	free(init_data);
// }

void	free_struct(t_struct *all_struct)
{
	free_map(all_struct->init->tab);
	free_map(all_struct->init->flood_tab);
	free(all_struct->init->map_name);
	free(all_struct->init);
	free(all_struct->data);
	free_list(all_struct->first_node);
	free(all_struct);
}

void	free_mlx(t_struct *all_struct)
{
	mlx_close_window(all_struct->mlx);
	mlx_delete_image(all_struct->mlx, all_struct->data->img_floor);
	mlx_delete_image(all_struct->mlx, all_struct->data->img_c4);
	mlx_delete_image(all_struct->mlx, all_struct->data->img_exit);
	mlx_delete_image(all_struct->mlx, all_struct->data->img_player);
	//mlx_delete_image(all_struct->mlx, all_struct->data->img_player_right);
	mlx_delete_image(all_struct->mlx, all_struct->data->img_wall);
	mlx_delete_image(all_struct->mlx, all_struct->data->str_counter);
	mlx_delete_texture(all_struct->data->c4);
	mlx_delete_texture(all_struct->data->exit);
	//mlx_delete_texture(all_struct->data->player_right);
	mlx_delete_texture(all_struct->data->player);
	mlx_delete_texture(all_struct->data->wall);
	mlx_delete_texture(all_struct->data->floor);
	mlx_terminate(all_struct->mlx);
}
