/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teste.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaiago <gsaiago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 13:12:03 by gsaiago           #+#    #+#             */
/*   Updated: 2022/08/17 17:05:44 by gsaiago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>

int	trgb(int t, int r, int g, int b);
void paint_bg(void *mlx_ptr, void *mlx_win, int size_x, int size_y, int color);

int	main(void)
{
	void	*mlx_ptr;
	void	*mlx_win;
	int		size_x;
	int		size_y;

	size_x = 1000;
	size_y = 500;
	mlx_ptr = mlx_init();
	mlx_win = mlx_new_window(mlx_ptr, size_x, size_y, "so_long");
	paint_bg(mlx_ptr, mlx_win, size_x, size_y, trgb(0, 100, 193, 206));
	mlx_loop(mlx_ptr);
}

int	trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	paint_bg(void *mlx_ptr, void *mlx_win, int size_x, int size_y, int color)
{
	int		pos_x;
	int		pos_y;

	pos_x = 1;
	pos_y = 1;
	while (pos_y < size_y - 1)
	{
		while (pos_x < size_x - 1)
		{
			mlx_pixel_put(mlx_ptr, mlx_win, pos_x, pos_y, color);
			pos_x++;
		}
		pos_x = 1;
		pos_y++;
	}
}
