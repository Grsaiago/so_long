/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_so_long_map1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaiago <gsaiago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 15:26:04 by gsaiago           #+#    #+#             */
/*   Updated: 2022/09/23 12:14:47 by gsaiago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	count_components(t_data *s_data, char *line, int p_x)
{
	int	y;

	y = 0;
	while (line[y] && y < s_data->size_x)
	{
		if (!(line[y] == 'P' || line[y] == 'C' || line[y] == 'E'
				|| line[y] == '1' || line[y] == '0' || line[y] == 'X'))
		{
			free(line);
			exit_func(s_data, "Error!\nInvalid components");
		}
		if (line[y] == 'P')
		{
			s_data->p_count++;
			s_data->player_x = p_x;
			s_data->player_y = y;
		}
		else if (line[y] == 'C')
			s_data->c_count++;
		else if (line[y] == 'E')
			s_data->e_count++;
		y++;
	}
	free(line);
	return ;
}

void	validate_components(t_data *s_data)
{
	int		fd;
	char	*line;
	int		x;

	fd = open(s_data->map_name, O_RDONLY);
	if (fd < 2)
		exit_func(s_data, "Error!\nInvalid fd");
	x = 0;
	line = get_next_line(fd);
	while (line)
	{
		count_components(s_data, line, x);
		line = get_next_line(fd);
		x++;
	}
	if (line)
		free(line);
	close(fd);
	if (s_data->p_count != 1
		|| s_data->e_count != 1 || s_data->c_count < 1)
		exit_func(s_data, "Error!\nInvalid components");
	return ;
}

void	dfs(t_data *s_data, int x, int y, char **map_sol)
{
	if (map_sol[x][y] == '1' || map_sol[x][y] == 'X')
		return ;
	if (map_sol[x][y - 1] == 'E' || map_sol[x][y + 1] == 'E' ||
			map_sol[x - 1][y] == 'E' ||
			map_sol[x + 1][y] == 'E' || map_sol[x][y] == 'E' )
		s_data->e_reach++;
	if (map_sol[x][y] != '1')
		map_sol[x][y] = '1';
	if (map_sol[x][y - 1] != '1' && map_sol[x][y - 1] != 'X'
			&& map_sol[x][y - 1] != 'E')
		dfs(s_data, x, y - 1, map_sol);
	if (map_sol[x][y + 1] != '1' && map_sol[x][y + 1] != 'X' &&
			map_sol[x][y + 1] != 'E')
		dfs(s_data, x, y + 1, map_sol);
	if (map_sol[x - 1][y] != '1' && map_sol[x - 1][y] != 'X' &&
			map_sol[x - 1][y] != 'E')
		dfs(s_data, x - 1, y, map_sol);
	if (map_sol[x + 1][y] != '1' && map_sol[x + 1][y] != 'X' &&
			map_sol[x + 1][y] != 'E')
		dfs(s_data, x + 1, y, map_sol);
	return ;
}

