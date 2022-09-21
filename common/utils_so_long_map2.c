/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_so_long_map2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaiago <gsaiago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 10:40:16 by gsaiago           #+#    #+#             */
/*   Updated: 2022/09/21 10:49:41 by gsaiago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mandatory/so_long.h"

void	validate_map_path(t_data *s_data)
{
	int	i;
	int	j;

	i = 0;
	while (i < s_data->size_y)
	{
		j = 0;
		while (j < s_data->size_x)
		{
			if (s_data->map_array[i][j] == 'C')
				exit_func(s_data, "Error!\nThere is no valid path");
			j++;
		}
		i++;
	}
	return ;
}

void	validate_map(t_data *s_data, char *map)
{
	map_validate_name(s_data, map);
	map_validate_dimentions(s_data);
	map_validate_outline(s_data);
	validate_components(s_data);
	s_data->map_array = create_map_array(s_data);
	dfs(s_data, s_data->player_x, s_data->player_y, s_data->map_array);
	validate_map_path(s_data);
	free_map_array(s_data->map_array);
	s_data->map_array = create_map_array(s_data);
	return ;
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
	while (i <= s_data->size_y)
	{
		array[i] = get_next_line(fd);
		i++;
	}
	close(fd);
	return (array);
}
