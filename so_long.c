/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaiago <gsaiago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 13:12:03 by gsaiago           #+#    #+#             */
/*   Updated: 2022/08/22 14:26:13 by gsaiago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	initialize_images(t_img *s_img, t_data s_mlx);

void	paint_bg(t_data s_mlx, t_img s_img);

int	main(int argc, char *argv[])
{
	t_img	s_img;
	t_data	s_mlx;
	int		valid;

	if (argc != 2)
		return (write (1, "quantidade incorreta de args.", 29));
	s_mlx.map_name = argv[1];
	s_mlx.mlx_ptr = mlx_init();
	initialize_images(&s_img, s_mlx);
	valid = validate_map(&s_mlx, s_mlx.map_name);
	s_mlx.win_ptr = mlx_new_window(s_mlx.mlx_ptr, s_mlx.size_x * s_img.img_width, s_mlx.size_y * s_img.img_height, "so_long");
	paint_bg(s_mlx, s_img);
	mlx_loop(s_mlx.mlx_ptr);
}

void	initialize_images(t_img *s_img, t_data s_mlx)
{
	s_img->img_height = 91;
	s_img->img_width = 91;
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
	squares_x = s_img.img_width;
	squares_y = s_img.img_height;

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
