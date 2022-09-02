/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaiago <gsaiago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 17:16:03 by gsaiago           #+#    #+#             */
/*   Updated: 2022/09/02 14:41:03 by gsaiago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <mlx.h>
#include <stdlib.h>

#ifndef SO_LONG_H
# define SO_LONG_H

// ---SO_LONG STRUCTS--- //

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		size_x;
	int		size_y;
	int		pos_x;
	int		pos_y;
	int		player_x;
	int		player_y;
	int		c_count;
	char	*map_name;
	char	**map_array;
// parte de imagens do struct:
	void	*i_tile;
	void	*i_wall;
	void	*i_coin;
	void	*i_door_open;
	void	*i_door_closed;
	void	*i_player;
	int		i_height;
	int		i_width;
	int		k_count;
}	t_data;

// ---GNL FUNCTIONS--- //

char	*ft_gnl(int valid, int fd, char *sptr);
char	*get_next_line(int fd);
char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *c);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strjoin_gnl(char *s1, char *s2);
char	*ft_staticptr(char *buffer);
char	*ft_returnptr(char *buffer);
char	*ft_strchr(const char *s, int c);

// ---SO_LONG FUNCTIONS--- //
int     initialize_images(t_data *s_data);
// map validations functions //
int		map_validate_name(t_data *s_data, char *map);
int		map_validate_dimentions(t_data *s_data);
int		map_validate_floor_ceiling(t_data *s_data, char *line, int flag, int fd);
int		map_validate_borders(t_data *s_data, char *line, int flag, int fd);
int		map_validate_outline(t_data *s_data);
int		count_components(t_data *s_data, char c);
int		map_validate_components(t_data s_data);
int		validate_map(t_data *s_data, char *map);
char 	**create_map_array(t_data *s_data);
// screen refresh functions //
void    img_put(t_data *s_data, char c, int i, int j);
int 	paint_bg(t_data *s_data);
// keyhook functions //
int		keyhook_main_call(int keycode, t_data *s_data);
int		keyhook_w(t_data *s_data);
int		keyhook_a(t_data *s_data);
int		keyhook_s(t_data *s_data);
int		keyhook_d(t_data *s_data);
int		keyhook_esc(t_data *s_data);
// error/free functions //
void	free_struct(t_data *s_data);
void	destroy_mlx(t_data *s_data);
void	ft_writenbr(int nbr);
#endif
