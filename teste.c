/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teste.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaiago <gsaiago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 10:51:04 by gsaiago           #+#    #+#             */
/*   Updated: 2022/08/22 14:00:53 by gsaiago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_lines(char *map)
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

int	validate_map(t_data *s_data, char *map)
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
	s_data->size_y = count_lines(map);
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
	close(fd);
	free(aux);
	return (0);
}

/*
int	main(void)
{
	char	*map = "./map.ber";
	int		valid;
	t_data	s_data;

	valid = validate_map(&s_data, map);
	printf("A quantidade de colunas do arquivo .ber no path |%s| é > |%d| e o valid é > |%d|\n", map, s_data.size_x, valid);
	printf("A quantidade de linhas do arquivo .ber no path |%s| é > |%d| e o valid é > |%d|\n\n", map, s_data.size_y, valid);
}
*/
