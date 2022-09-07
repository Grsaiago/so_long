/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_so_long_keyhooks.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaiago <gsaiago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 13:49:35 by gsaiago           #+#    #+#             */
/*   Updated: 2022/09/07 16:50:37 by gsaiago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	keyhook_main_call(int keycode, t_data *s_data)
{
	if (keycode == 13 || keycode == 0 || keycode == 1
		|| keycode == 2 || keycode == 53)
		s_data->k_count++;
	if (keycode == 13)
		keyhook_w(s_data);
	else if (keycode == 0)
		keyhook_a(s_data);
	else if (keycode == 1)
		keyhook_s(s_data);
	else if (keycode == 2)
		keyhook_d(s_data);
	if (keycode == 53)
		keyhook_esc(s_data);
	return (0);
}

int	keyhook_w(t_data *s_data)
{
	if (s_data->map_array[s_data->player_x - 1][s_data->player_y] == '1')
		return (0);
	if (s_data->map_array[s_data->player_x - 1][s_data->player_y] == 'E')
	{
		if (s_data->c_count == 0)
			exit(1);
		else
			return (0);
	}
	if (s_data->map_array[s_data->player_x - 1][s_data->player_y] == '0'
		|| s_data->map_array[s_data->player_x - 1][s_data->player_y] == 'C')
	{
		if (s_data->map_array[s_data->player_x - 1][s_data->player_y] == 'C')
			s_data->c_count--;
		s_data->map_array[s_data->player_x - 1][s_data->player_y] = 'P';
		s_data->map_array[s_data->player_x][s_data->player_y] = '0';
	}
	ft_writenbr(s_data->k_count);
	paint_bg(s_data);
	write(1, &s_data->k_count, 1);
	write(1, "\n", 1);
	return (1);
}

int	keyhook_a(t_data *s_data)
{
	if (s_data->map_array[s_data->player_x][s_data->player_y - 1] == '1')
		return (0);
	if (s_data->map_array[s_data->player_x][s_data->player_y - 1] == 'E')
	{
		if (s_data->c_count == 0)
			exit(1);
		else
			return (0);
	}
	if (s_data->map_array[s_data->player_x][s_data->player_y - 1] == '0'
		|| s_data->map_array[s_data->player_x][s_data->player_y - 1] == 'C')
	{
		if (s_data->map_array[s_data->player_x][s_data->player_y - 1] == 'C')
			s_data->c_count--;
		s_data->map_array[s_data->player_x][s_data->player_y - 1] = 'P';
		s_data->map_array[s_data->player_x][s_data->player_y] = '0';
	}
	ft_writenbr(s_data->k_count);
	paint_bg(s_data);
	write(1, &s_data->k_count, 1);
	write(1, "\n", 1);
	return (1);
}

int	keyhook_s(t_data *s_data)
{
	if (s_data->map_array[s_data->player_x + 1][s_data->player_y] == '1')
		return (0);
	if (s_data->map_array[s_data->player_x + 1][s_data->player_y] == 'E')
	{
		if (s_data->c_count == 0)
			exit(1);
		else
			return (0);
	}
	if (s_data->map_array[s_data->player_x + 1][s_data->player_y] == '0'
		|| s_data->map_array[s_data->player_x + 1][s_data->player_y] == 'C')
	{
		if (s_data->map_array[s_data->player_x + 1][s_data->player_y] == 'C')
			s_data->c_count--;
		s_data->map_array[s_data->player_x + 1][s_data->player_y] = 'P';
		s_data->map_array[s_data->player_x][s_data->player_y] = '0';
	}
	ft_writenbr(s_data->k_count);
	paint_bg(s_data);
	write(1, &s_data->k_count, 1);
	write(1, "\n", 1);
	return (1);
}

int	keyhook_d(t_data *s_data)
{
	if (s_data->map_array[s_data->player_x][s_data->player_y + 1] == '1')
		return (0);
	if (s_data->map_array[s_data->player_x][s_data->player_y + 1] == 'E')
	{
		if (s_data->c_count == 0)
			exit(1);
		else
			return (0);
	}
	if (s_data->map_array[s_data->player_x][s_data->player_y + 1] == '0'
		|| s_data->map_array[s_data->player_x][s_data->player_y + 1] == 'C')
	{
		if (s_data->map_array[s_data->player_x][s_data->player_y + 1] == 'C')
			s_data->c_count--;
		s_data->map_array[s_data->player_x][s_data->player_y + 1] = 'P';
		s_data->map_array[s_data->player_x][s_data->player_y] = '0';
	}
	ft_writenbr(s_data->k_count);
	paint_bg(s_data);
	write(1, &s_data->k_count, 1);
	write(1, "\n", 1);
	return (1);
}

int	keyhook_esc(t_data *s_data)
{
	free_struct(s_data);
	destroy_mlx(s_data);
	write (1, "you've successfuly exited the program 😁", 42);
	exit(1);
}
