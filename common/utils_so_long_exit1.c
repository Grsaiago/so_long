/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_so_long_exit1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaiago <gsaiago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 13:20:16 by gsaiago           #+#    #+#             */
/*   Updated: 2022/09/14 13:21:20 by gsaiago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mandatory/so_long.h"

void	exit_images(t_data *s_data)
{
	if (s_data->i_tile)
		mlx_destroy_image(s_data->mlx_ptr, s_data->i_tile);
	if (s_data->i_wall)
		mlx_destroy_image(s_data->mlx_ptr, s_data->i_wall);
	if (s_data->i_coin)
		mlx_destroy_image(s_data->mlx_ptr, s_data->i_coin);
	if (s_data->i_door_open)
		mlx_destroy_image(s_data->mlx_ptr, s_data->i_door_open);
	if (s_data->i_door_closed)
		mlx_destroy_image(s_data->mlx_ptr, s_data->i_door_closed);
	if (s_data->i_player)
		mlx_destroy_image(s_data->mlx_ptr, s_data->i_player);
	if (s_data->i_enemy)
		mlx_destroy_image(s_data->mlx_ptr, s_data->i_enemy);
	return ;
}

void	free_map_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
	return ;
}
