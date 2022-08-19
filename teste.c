/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teste.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaiago <gsaiago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 13:12:03 by gsaiago           #+#    #+#             */
/*   Updated: 2022/08/19 17:41:51 by gsaiago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	initialize_images(t_img *s_img, t_data s_mlx, int height, int width);

void	paint_bg(t_data s_mlx, t_img s_img);

int	trgb(int t, int r, int g, int b);

int	main(int argc, char *argv[])
{
	t_img	s_img;
	t_data	s_mlx;
	int		size_x;
	int		size_y;
	int		height;
	int		width;
	int		fd;

	if (argc != 2)
		return (write (1, "quantidade incorreta de args.", 29));
	fd = open(argv[1], O_RDONLY); 

	height = 91;
	width = 91;
	size_x = 455;
	size_y = 455;
	s_mlx.mlx_ptr = mlx_init();
	s_mlx.win_ptr = mlx_new_window(s_mlx.mlx_ptr, size_x, size_y, "so_long");
	initialize_images(&s_img, s_mlx, 91, 91);
	paint_bg(s_mlx, s_img);
	mlx_loop(s_mlx.mlx_ptr);
}

void	initialize_images(t_img *s_img, t_data s_mlx, int height, int width)
{
	s_img->img_height = height;
	s_img->img_width = width;
	s_img->img_tile = mlx_xpm_file_to_image(s_mlx.mlx_ptr, "./assets/tile.xpm", &s_img->img_height, &s_img->img_width);
	s_img->img_wall = mlx_xpm_file_to_image(s_mlx.mlx_ptr, "./assets/wall.xpm", &s_img->img_height, &s_img->img_width);
	s_img->img_coin = mlx_xpm_file_to_image(s_mlx.mlx_ptr, "./assets/coin.xpm", &s_img->img_height, &s_img->img_width);
	s_img->img_door_open = mlx_xpm_file_to_image(s_mlx.mlx_ptr, "./assets/door_open.xpm", &s_img->img_height, &s_img->img_width); 
	s_img->img_door_closed = mlx_xpm_file_to_image(s_mlx.mlx_ptr, "./assets/door_closed.xpm", &s_img->img_height, &s_img->img_width); 
	s_img->img_player = mlx_xpm_file_to_image(s_mlx.mlx_ptr, "./assets/player.xpm", &s_img->img_height, &s_img->img_width); 
	s_img->img_enemy = mlx_xpm_file_to_image(s_mlx.mlx_ptr, "./assets/enemy.xpm", &s_img->img_height, &s_img->img_width); 

}
void	paint_bg(t_data s_mlx, t_img s_img)
{
	int	squares_x;
	int	squares_y;
	int	pos_x;
	int	pos_y;
	int	i;
	int j;

	j = 0;
	pos_x = 1;
	pos_y = 1;
	squares_x = 6;
	squares_y = 6;

	while (j < (squares_y - 1))
	{
		pos_x = 1;
		i = 0;
		while (i < (squares_x - 1))
		{
			mlx_put_image_to_window(s_mlx.mlx_ptr, s_mlx.win_ptr, s_img.img_door_open, pos_x, pos_y);
			pos_x += s_img.img_width;
			i++;
		}
		pos_y += s_img.img_height;
		j++;
	}
	return ;
}
