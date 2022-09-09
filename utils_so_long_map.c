/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_so_long_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaiago <gsaiago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 16:42:35 by gsaiago           #+#    #+#             */
/*   Updated: 2022/09/09 13:12:14 by gsaiago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Dimensions && Content
//count -> validate -> store

#include "so_long.h"

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

int	count_components(t_data *s_data, char c)
{
	static int	count;

	if (c == 'P')
		count++;
	else if (c == 'C')
	{
		count = count | (1 << 1);
		s_data->c_count++;
	}
	else if (c == 'E')
		count = count | (1 << 2);
	return (count);
}

int	validate_components(t_data *s_data)
{
	int		fd;
	int		i;
	char	*line;
	int		flag;

	fd = open(s_data->map_name, O_RDONLY);
	if (fd < 2)
		return (-1);
	flag = 0;
	line = get_next_line(fd);
	while (line)
	{
		i = -1;
		while (++i < (s_data->size_x))
			flag = count_components(s_data, line[i]);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	return (flag);
}

int	validate_map(t_data *s_data, char *map)
{
	if (map_validate_name(s_data, map) < 0)
		return (-1);
	if (map_validate_dimentions(s_data) < 0)
		return (-1);
	if (map_validate_outline(s_data) < 0)
		return (-1);
	if (validate_components(s_data) != 7)
		return (-1);
	return (0);
}

char	**create_map_array(t_data *s_data)
{
	int		i;
	int		fd;
	char	**array;

	array = ft_calloc(s_data->size_y + 1, sizeof(char *));
	if (!array)
		return (NULL);
	fd = open(s_data->map_name, O_RDONLY);
	if (fd < 2)
		return (NULL);
	i = 0;
	while (i < s_data->size_y)
	{
		array[i] = get_next_line(fd);
		i++;
	}
	close(fd);
	return (array);
}
