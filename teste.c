/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teste.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaiago <gsaiago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 13:12:03 by gsaiago           #+#    #+#             */
/*   Updated: 2022/08/18 16:28:46 by gsaiago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>

typedef struct	s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
}	t_data;

int	trgb(int t, int r, int g, int b);

int	main(void)
{
	t_data	s_mlx;
	int		size_x;
	int		size_y;

	size_x = 1000;
	size_y = 500;
	s_mlx.mlx_ptr = mlx_init();
	s_mlx.win_ptr = mlx_new_window(s_mlx.mlx_ptr, size_x, size_y, "so_long");
	mlx_loop(s_mlx.mlx_ptr);
}