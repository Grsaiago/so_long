/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_so_long_keyhooks.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaiago <gsaiago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 13:49:35 by gsaiago           #+#    #+#             */
/*   Updated: 2022/08/31 14:38:52 by gsaiago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	keyhook_w(t_data *s_data);
//int	keyhook_a(int keycode, int count, t_data *s_data);
//int	keyhook_s(int keycode, int count, t_data *s_data);
//int	keyhook_d(int keycode, int count, t_data *s_data);
//int	keyhook_esc(int keycode, int count, t_data *s_data);

int	keyhook_main_call(int keycode, t_data *s_data)
{
	static int count;
	
	count++;
	printf("(mudar para putnbr em) count == |%d|", count);
	if (keycode == 13)
		keyhook_w(keycode, s_data);
//	else if (keycode == 0)
//		keyhook_a(keycode, s_data);
//	else if (keycode == 1)
//		keyhook_s(keycode, s_data);
//	else if (keycode == 2)
//		keyhook_d(keycode, s_data);
//	else if (keycode == 53)
//		keyhook_esc(keycode, s_data);
//	printf("o keycode do que foi pressionado é > |%d|\nO contador está em > |%d|", keycode, count);
	return (0);
}

int	keyhook_w(t_data *s_data)
{
	write(1, "placeholder pro contador", 24);
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
	paint_bg(s_data);
	return (0);
}
