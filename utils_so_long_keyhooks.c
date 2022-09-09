/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_so_long_keyhooks.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaiago <gsaiago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 13:49:35 by gsaiago           #+#    #+#             */
/*   Updated: 2022/09/09 13:09:26 by gsaiago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	keyhook_main_call(int keycode, t_data *s_data)
{
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
			exit_func(s_data, "You've passed the test🎇");
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
	s_data->k_count++;
	ft_writenbr(s_data->k_count);
	paint_bg(s_data);
	write(1, "\n", 1);
	return (0);
}

int	keyhook_a(t_data *s_data)
{
	if (s_data->map_array[s_data->player_x][s_data->player_y - 1] == '1')
		return (0);
	if (s_data->map_array[s_data->player_x][s_data->player_y - 1] == 'E')
	{
		if (s_data->c_count == 0)
			exit_func(s_data, "You've passed the test🎇");
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
	s_data->k_count++;
	ft_writenbr(s_data->k_count);
	paint_bg(s_data);
	write(1, "\n", 1);
	return (0);
}

int	keyhook_s(t_data *s_data)
{
	if (s_data->map_array[s_data->player_x + 1][s_data->player_y] == '1')
		return (0);
	if (s_data->map_array[s_data->player_x + 1][s_data->player_y] == 'E')
	{
		if (s_data->c_count == 0)
			exit_func(s_data, "You've passed the test🎇");
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
	s_data->k_count++;
	ft_writenbr(s_data->k_count);
	paint_bg(s_data);
	write(1, "\n", 1);
	return (0);
}

int	keyhook_d(t_data *s_data)
{
	if (s_data->map_array[s_data->player_x][s_data->player_y + 1] == '1')
		return (0);
	if (s_data->map_array[s_data->player_x][s_data->player_y + 1] == 'E')
	{
		if (s_data->c_count == 0)
			exit_func(s_data, "You've passed the test🎇");
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
	s_data->k_count++;
	ft_writenbr(s_data->k_count);
	paint_bg(s_data);
	write(1, "\n", 1);
	return (0);
}

int	keyhook_esc(t_data *s_data)
{
	exit_func(s_data, "You pressed ESC");
	return (0);
}

int	close_window(t_data *s_data)
{
	exit_func(s_data, "You closed the window 😎");
	return (0);
}
