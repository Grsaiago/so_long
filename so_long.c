/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaiago <gsaiago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 13:12:03 by gsaiago           #+#    #+#             */
/*   Updated: 2022/08/22 16:05:19 by gsaiago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	initialize_images(t_img *s_img, t_data s_mlx);

int		paint_bg(t_data s_mlx, t_img s_img);

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



int	paint_bg(t_data s_mlx, t_img s_img)
{
	int		pos_x;
	int		pos_y;
	int		i;
	int		fd;
	char	*aux;

	fd = open("./map.ber", O_RDONLY);
	if (fd < 2)
		return (-1);
	pos_y = 1;
	aux = get_next_line(fd);
	while(aux)
	{
		pos_x = 1;
		i = 0;
		while(aux[i] != '\n')
		{
			if (aux[i] == '0')
				mlx_put_image_to_window(s_mlx.mlx_ptr, s_mlx.win_ptr, s_img.img_tile, pos_x, pos_y);
			else if (aux[i] == '1')
				mlx_put_image_to_window(s_mlx.mlx_ptr, s_mlx.win_ptr, s_img.img_wall, pos_x, pos_y);
			else if (aux[i] == 'C')
				mlx_put_image_to_window(s_mlx.mlx_ptr, s_mlx.win_ptr, s_img.img_coin, pos_x, pos_y);
			else if (aux[i] == 'E')
				mlx_put_image_to_window(s_mlx.mlx_ptr, s_mlx.win_ptr, s_img.img_door_closed, pos_x, pos_y);
			else if (aux[i] == 'P')
				mlx_put_image_to_window(s_mlx.mlx_ptr, s_mlx.win_ptr, s_img.img_player, pos_x, pos_y);
			pos_x += s_img.img_width;
			i++;
		}
		pos_y += s_img.img_height;
		aux = get_next_line(fd);
	}
	free(aux);
	return (0);
}
