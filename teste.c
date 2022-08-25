/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teste.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaiago <gsaiago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 16:42:35 by gsaiago           #+#    #+#             */
/*   Updated: 2022/08/25 00:50:44 by gsaiago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Dimensions && Content
//count -> validate -> store

#include "so_long.h"

int	map_validate_dimentions(t_data *s_data, int fd)
{
	char	*line;

	line = get_next_line(fd);
	s_data->size_x = ft_strlen(line) - 1;
	while(line)
	{
		if (s_data->size_x != (int)ft_strlen(line) - 1 || s_data->size_x < 5)
		{
			free(line);
			close(fd);
			return (-1);
		}
		s_data->size_y++;
		line = get_next_line(fd);
	}
	if (s_data->size_y < 3)
	{
		free(line);
		close(fd);
		return (-1);
	}
	free(line);
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
			return(-1);
		}
		i++;
	}
	return (flag);
}

int map_validate_borders(t_data *s_data, char *line, int flag, int fd)
{
	if (line[0] != '1' || line[s_data->size_x - 1] != '1')
	{
		close(fd);
		free(line);
		return(-1);
	}
	return (flag);
}

int	map_validate_outline(t_data *s_data, char *map)
{
	int		fd;
	char	*line;
	int		i;

	fd = open(map, O_RDONLY);
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
		line = get_next_line(fd);
		i++;
	}
	free(line);
	return (close(fd));
}

int count_components(char c)
{
	static int	count;

	if (c == 'E')
		count = count | 1;
	else if (c == 'C')
		count = count | (1 << 1);
	else if (c == 'P')
		count = count | (1 << 2);
	return (count);
}

int validate_components(t_data *s_data, char *map)
{
	int		fd;
	int		i;
	char	*line;
	int		flag;

	fd = open(map, O_RDONLY);
	if (fd < 2)
		return (-1);
	flag = 0;
	line = get_next_line(fd);
	while (line)
	{
		i = -1;
		while (++i < (s_data->size_x))
			flag = count_components(line[i]);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	return (flag);
}

int	validate_map(t_data *s_data, char *map)
{
	int	fd;

	fd = open(map, O_RDONLY);
	if (fd < 2)
		return (-1);
	if (map_validate_dimentions(s_data, fd) < 0)
		return (-1);
	if (map_validate_outline(s_data, map) < 0)
		return (-1);
	if (validate_components(s_data, map) < 7)
	   return (-1);	
	return (0);
}

int	main(void)
{
	char	*map = "./map.ber";
	int		valid;
	t_data	s_data;


	valid = validate_map(&s_data, map);
	printf("A quantidade de colunas do arquivo .ber no path |%s| é > |%d|\n", map, s_data.size_x);
	printf("A quantidade de linhas do arquivo .ber no path |%s| é > |%d|\n", map, s_data.size_y);
	printf("O retorno da função é > |%d|\n", valid);
	printf("O retorno de map_validate é > |%d|\n", valid);
}

