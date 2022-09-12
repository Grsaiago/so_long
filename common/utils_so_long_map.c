/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_so_long_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaiago <gsaiago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 16:42:35 by gsaiago           #+#    #+#             */
/*   Updated: 2022/09/12 16:47:47 by gsaiago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Dimensions && Content
//count -> validate -> store

#include "../mandatory/so_long.h"

int	map_validate_name(t_data *s_data, char *map)
{
	int	len;

	len = ft_strlen(map);
	if (map[len - 1] != 'r' || map[len - 2] != 'e'
		|| map[len - 3] != 'b' || map[len - 4] != '.')
		return (-1);
	s_data->map_name = map;
	return (0);
}

int	map_validate_dimentions(t_data *s_data)
{
	char	*line;
	int		fd;

	fd = open(s_data->map_name, O_RDONLY);
	line = get_next_line(fd);
	s_data->size_x = ft_strlen(line) - 1;
	while (line)
	{
		if (s_data->size_x != (int)ft_strlen(line) - 1 || s_data->size_x < 5)
		{
			free(line);
			close(fd);
			return (-1);
		}
		s_data->size_y++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	if (s_data->size_y < 3)
	{
		close(fd);
		return (-1);
	}
	return (close(fd));
}

int	map_validate_floor_ceiling(t_data *s_data, char *line, int flag, int fd)
{
	int	i;

	i = 0;
	while (i < s_data->size_x)
	{
		if (line[i] != '1')
		{
			close(fd);
			free(line);
			return (-1);
		}
		i++;
	}
	return (flag);
}

int	map_validate_borders(t_data *s_data, char *line, int flag, int fd)
{
	if (line[0] != '1' || line[s_data->size_x - 1] != '1')
	{
		close(fd);
		free(line);
		return (-1);
	}
	return (flag);
}

int	map_validate_outline(t_data *s_data)
{
	int		fd;
	char	*line;
	int		i;

	fd = open(s_data->map_name, O_RDONLY);
	if (fd < 2)
		return (-1);
	line = get_next_line(fd);
	i = 0;
	while (i < s_data->size_y)
	{
		if (i == 0 || i == (s_data->size_y - 1))
			i = map_validate_floor_ceiling(s_data, line, i, fd);
		else
			i = map_validate_borders(s_data, line, i, fd);
		if (i < 0)
			return (-1);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	free(line);
	return (close(fd));
}
