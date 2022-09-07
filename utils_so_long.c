/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_so_long.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaiago <gsaiago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 14:34:20 by gsaiago           #+#    #+#             */
/*   Updated: 2022/09/07 19:12:17 by gsaiago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_writenbr(int nbr)
{
	long	n;
	int		nb;

	n = (long)nbr;
	if (n < 10 && n >= 0)
	{
		nb = n + 48;
		write (1, &nb, 1);
		return ;
	}
	else
		ft_writenbr(n / 10);
	ft_writenbr(n % 10);
	return ;
}

void	exit_func(t_data *s_data, const char *str)
{
	errno = ECANCELED;
	perror(str);
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
	if (s_data->win_ptr)
		mlx_destroy_window(s_data->mlx_ptr, s_data->win_ptr);
	if (s_data->mlx_ptr)
		free(s_data->mlx_ptr);
	if (s_data->map_array)
		free_map_array(s_data);
	exit(EXIT_FAILURE);
}
