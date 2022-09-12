/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_so_long_map1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaiago <gsaiago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 15:26:04 by gsaiago           #+#    #+#             */
/*   Updated: 2022/09/12 17:28:08 by gsaiago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mandatory/so_long.h"

int	count_components(t_data *s_data, char c)
{
	if (c == 'P')
		s_data->p_count++;
	else if (c == 'C')
		s_data->c_count++;
	else if (c == 'E')
		s_data->e_count++;
	return (0);
}

int	validate_components(t_data *s_data)
{
	int		fd;
	int		i;
	char	*line;

	fd = open(s_data->map_name, O_RDONLY);
	if (fd < 2)
		return (-1);
	line = get_next_line(fd);
	while (line)
	{
		i = -1;
		while (++i < (s_data->size_x))
			count_components(s_data, line[i]);
		free(line);
		line = get_next_line(fd);
	}

	free(line);
	close(fd);
	if (s_data->p_count != 1 ||
		s_data->e_count != 1 || s_data->c_count < 1)
		return (-1);
	return (0);
}

int	validate_map(t_data *s_data, char *map)
{
	if (map_validate_name(s_data, map) < 0)
		return (-1);
	if (map_validate_dimentions(s_data) < 0)
		return (-1);
	if (map_validate_outline(s_data) < 0)
		return (-1);
	if (validate_components(s_data) < 0)
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
