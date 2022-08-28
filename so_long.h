/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaiago <gsaiago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 17:16:03 by gsaiago           #+#    #+#             */
/*   Updated: 2022/08/28 18:53:24 by gsaiago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
// #include <mlx.h>
#include <stdlib.h>

#ifndef SO_LONG_H
# define SO_LONG_H

// ---SO_LONG STRUCTS--- //
typedef struct s_images
{
	void	*img_tile;
	void	*img_wall;
	void	*img_coin;
	void	*img_door_open;
	void	*img_door_closed;
	void	*img_player;
	void	*img_enemy;
	int		img_height;
	int		img_width;
} t_img;

typedef struct	s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		size_x;
	int		size_y;
	char	*map_name;
} t_data;

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

int	map_count_lines(char *map);
int	map_validate_dimentions(t_data *s_data, int fd);
int	map_validate_lines(char *line, int fd, t_data s_data);
int	map_validate_components(t_data s_data, char *map);

#endif
