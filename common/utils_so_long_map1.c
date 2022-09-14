/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_so_long_map1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaiago <gsaiago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 15:26:04 by gsaiago           #+#    #+#             */
/*   Updated: 2022/09/14 11:46:10 by gsaiago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mandatory/so_long.h"

int	count_components(t_data *s_data, char c, int  p_x, int p_y)
{
	if (c == 'P')
	{
		s_data->p_count++;
		s_data->player_x = p_x;
		s_data->player_y = p_y;
	}
	else if (c == 'C')
		s_data->c_count++;
	else if (c == 'E')
		s_data->e_count++;
	return (0);
}

int	validate_components(t_data *s_data)
{
	int		fd;
	int		y;
	char	*line;
	int		x;

	fd = open(s_data->map_name, O_RDONLY);
	if (fd < 2)
		return (-1);
	x = 0;
	line = get_next_line(fd);
	while (line)
	{
		y = -1;
		while (++y < (s_data->size_x))
			count_components(s_data, line[y], x, y);
		x++;
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

void	dfs(t_data *s_data, int x, int y, char **map_sol)
{
	if (map_sol[x][y] == '1' || map_sol[x][y] == 'X')
		return ;
	if (map_sol[x][y] == 'C')
		s_data->c_reach++;
	if (map_sol[x][y] == 'E')
		s_data->e_reach++;
	if (map_sol[x][y] != '1')
		map_sol[x][y] = '1';
	if (map_sol[x][y - 1] != '1' && map_sol[x][y - 1] != 'X')
		dfs(s_data, x, y - 1, map_sol);
	if (map_sol[x][y + 1] != '1' && map_sol[x][y + 1] != 'X')
		dfs(s_data, x, y + 1, map_sol);
	if (map_sol[x - 1][y] != '1' && map_sol[x - 1][y] != 'X')
		dfs(s_data, x - 1, y, map_sol);
	if (map_sol[x + 1][y] != '1' && map_sol[x + 1][y] != 'X')
		dfs(s_data, x + 1, y, map_sol);
	return ;
}

void	validate_map(t_data *s_data, char *map)
{
	if (map_validate_name(s_data, map) < 0)
		exit_func(s_data, "Error!\nInvalid map name");
	if (map_validate_dimentions(s_data) < 0)
		exit_func(s_data, "Error!\nInvalid map dimention");
	if (map_validate_outline(s_data) < 0)
		exit_func(s_data, "Error!\nthe map must be surrounded by 1");
	if (validate_components(s_data) < 0)
		exit_func(s_data, "Error!\nthe map must have, at least one of each: Coin (C), Exit (E), and Player (P)");
	s_data->map_array = create_map_array(s_data);
	dfs(s_data, s_data->player_x, s_data->player_y, s_data->map_array);
	if (s_data->c_reach != s_data->c_count 
		|| s_data->e_reach != s_data->e_count)
		exit_func(s_data, "There is no valid path on the map");
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
