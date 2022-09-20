/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaiago <gsaiago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 13:12:03 by gsaiago           #+#    #+#             */
/*   Updated: 2022/09/20 18:39:30 by gsaiago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_data	s_data;

	s_data = (t_data){0};
	if (argc != 2)
		exit_func(&s_data, "Error!\nInvalid arguments 😭");
	validate_map(&s_data, argv[1]);
	s_data.mlx_ptr = mlx_init();
	if (!s_data.mlx_ptr)
		exit_func(&s_data, "Error!\nmlx failed to initialize 😅");
	initialize_images(&s_data);
	s_data.win_ptr = mlx_new_window(s_data.mlx_ptr,
			s_data.size_x * s_data.i_width,
			s_data.size_y * s_data.i_height, "so_long");
	paint_bg(&s_data);
	mlx_key_hook(s_data.win_ptr, &keyhook_main_call, &s_data);
	mlx_hook(s_data.win_ptr, 17, 0, &close_window, &s_data);
	mlx_loop(s_data.mlx_ptr);
}

void	initialize_images(t_data *s_data)
{
	s_data->i_height = 91;
	s_data->i_width = 91;
	s_data->i_tile = mlx_xpm_file_to_image(s_data->mlx_ptr,
			"./assets/tile.xpm", &s_data->i_height, &s_data->i_width);
	s_data->i_wall = mlx_xpm_file_to_image(s_data->mlx_ptr,
			"./assets/wall.xpm", &s_data->i_height, &s_data->i_width);
	s_data->i_coin = mlx_xpm_file_to_image(s_data->mlx_ptr,
			"./assets/coin.xpm", &s_data->i_height, &s_data->i_width);
	s_data->i_door_open = mlx_xpm_file_to_image(s_data->mlx_ptr,
			"./assets/door_open.xpm", &s_data->i_height, &s_data->i_width);
	s_data->i_door_closed = mlx_xpm_file_to_image(s_data->mlx_ptr,
			"./assets/door_closed.xpm", &s_data->i_height, &s_data->i_width);
	s_data->i_player = mlx_xpm_file_to_image(s_data->mlx_ptr,
			"./assets/player.xpm", &s_data->i_height, &s_data->i_width);
	if (!s_data->i_tile || !s_data->i_wall || !s_data->i_coin
		|| !s_data->i_door_open || !s_data->i_door_closed || !s_data->i_player)
		exit_func(s_data, "Error!\nSome image failed to initialize");
	return ;
}

int	paint_bg(t_data *s_data)
{
	int	i;
	int	j;

	i = 0;
	s_data->pos_y = 0;
	mlx_clear_window (s_data->mlx_ptr, s_data->win_ptr);
	while (s_data->map_array[i])
	{
		s_data->pos_x = 0;
		j = 0;
		while (j < s_data->size_x)
		{
			img_put(s_data, s_data->map_array[i][j], i, j);
			s_data->pos_x += s_data->i_width;
			j++;
		}
		s_data->pos_y += s_data->i_height;
		i++;
	}
	return (0);
}

void	img_put(t_data *s_data, char c, int i, int j)
{
	if (c == '0')
		mlx_put_image_to_window(s_data->mlx_ptr, s_data->win_ptr,
			s_data->i_tile, s_data->pos_x, s_data->pos_y);
	else if (c == '1')
		mlx_put_image_to_window(s_data->mlx_ptr, s_data->win_ptr,
			s_data->i_wall, s_data->pos_x, s_data->pos_y);
	else if (c == 'C')
		mlx_put_image_to_window(s_data->mlx_ptr, s_data->win_ptr,
			s_data->i_coin, s_data->pos_x, s_data->pos_y);
	else if (c == 'E' && s_data->c_count == 0)
		mlx_put_image_to_window(s_data->mlx_ptr, s_data->win_ptr,
			s_data->i_door_open, s_data->pos_x, s_data->pos_y);
	else if (c == 'E')
		mlx_put_image_to_window(s_data->mlx_ptr, s_data->win_ptr,
			s_data->i_door_closed, s_data->pos_x, s_data->pos_y);
	else if (c == 'P')
	{
		mlx_put_image_to_window(s_data->mlx_ptr, s_data->win_ptr,
			s_data->i_player, s_data->pos_x, s_data->pos_y);
		s_data->player_x = i;
		s_data->player_y = j;
	}
}
