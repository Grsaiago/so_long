/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_so_long_exit.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaiago <gsaiago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 14:34:20 by gsaiago           #+#    #+#             */
/*   Updated: 2022/09/19 12:44:57 by gsaiago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mandatory/so_long.h"

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

void	exit_func(t_data *s_data, const char *str)
{
	errno = ECANCELED;
	perror(str);
	if (s_data->win_ptr)
		mlx_clear_window (s_data->mlx_ptr, s_data->win_ptr);
	if (s_data->mlx_ptr)
		mlx_clear_window(s_data->mlx_ptr, s_data->win_ptr);
	exit_images(s_data);
	if (s_data->win_ptr)
		mlx_destroy_window(s_data->mlx_ptr, s_data->win_ptr);
	if (s_data->mlx_ptr)
		free(s_data->mlx_ptr);
	if (s_data->map_array)
		free_map_array(s_data->map_array);
	if (s_data->map_sol)
		free_map_array(s_data->map_sol);
	exit(EXIT_FAILURE);
}

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
