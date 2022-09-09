/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_so_long_map1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaiago <gsaiago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 15:26:04 by gsaiago           #+#    #+#             */
/*   Updated: 2022/09/09 15:26:18 by gsaiago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
