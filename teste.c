/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teste.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaiago <gsaiago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 16:15:39 by gsaiago           #+#    #+#             */
/*   Updated: 2022/08/22 17:18:00 by gsaiago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_count_lines(char *map)
{
	char	*aux;
	int		valid;
	int		count;
	int		fd;

	count = 0;
	aux = ft_calloc(sizeof(char), 2);
	if (!aux)
		return (-1);
	fd = open(map, O_RDONLY);
	if (fd < 0)
		return (-1);
	while (1)
	{
		valid = read(fd, aux, 1);
		if (valid <= 0)
			break ;
		if (aux[0] == '\n')
			count++;
	}
	free(aux);
	close(fd);
	return (count);
}

int	map_validate_dimentions(t_data *s_data, char *map)
{
	char	*aux;
	int		fd;

	fd = open(map, O_RDONLY);
	if (fd < 0)
		return (-1);
	aux = get_next_line(fd);
	if (!aux)
		return (-1);
	s_data->size_x = ft_strlen(aux) - 1;
	s_data->size_y = map_count_lines(map);
	if (s_data->size_y < 4)
		return (-1);
	while (aux)
	{
		if (s_data->size_x != ((int)ft_strlen(aux) - 1))
		{
			close(fd);
			free(aux);
			return (-1);
		}
		aux = get_next_line(fd);
	}
	free(aux);
	return (close(fd));
}

int	map_validate_lines(char *line, int fd, t_data s_data)
{
	int	i;
	int	flag;

	flag = 1;
	while (line)
	{
		if (line[0] != '1' || line[s_data.size_x - 1] != '1')
			return (-1);
		if (flag == 1 || flag == s_data.size_y)
		{
			i = 0;
			while (i < s_data.size_x)
			{
				if (line[i] != '1')
					return (-1);
				i++;
			}
		}
		line = get_next_line(fd);
		flag++;
	}
	free(line);
	return (0);
}
int	map_validate_components(t_data s_data, char *map)
{
	int		fd;
	char	*line;
	
	fd = open(map, O_RDONLY);
	if (fd < 0)
		return (-1);
	line = get_next_line(fd);
	if (map_validate_lines(line, fd, s_data) < 0)
	{
		close(fd);
		return (-1);
	}
	return(close(fd));
}


int	main(void)
{
	char	*map = "./map.ber";
	int		valid;
	t_data	s_data;


	valid = map_validate_dimentions(&s_data, map);
	printf("A quantidade de colunas do arquivo .ber no path |%s| é > |%d| e o valid é > |%d|\n", map, s_data.size_x, valid);
	printf("A quantidade de linhas do arquivo .ber no path |%s| é > |%d| e o valid é > |%d|\n\n", map, s_data.size_y, valid);
	valid = map_validate_components(s_data, map);
	printf("O retorno de validate_map_components é > |%d|", valid);
}

