/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teste.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaiago <gsaiago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 17:15:13 by gsaiago           #+#    #+#             */
/*   Updated: 2022/09/13 16:33:50 by gsaiago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mandatory/so_long.h"
#include <unistd.h>

void	dfs(t_data *s_data, int x, int y, char **map_sol)
{
	if (map_sol[x][y] == '1')
		return ;
	if (map_sol[x][y] == 'C')
		s_data->c_reach++;
	if (map_sol[x][y] == 'E')
		s_data->e_reach++;
	if (map_sol[x][y] != '1')
		map_sol[x][y] = '1';
	if (map_sol[x][y - 1] != '1')
		dfs(s_data, x, y - 1, map_sol);
	if (map_sol[x][y + 1] != '1')
		dfs(s_data, x, y + 1, map_sol);
	if (map_sol[x - 1][y] != '1')
		dfs(s_data, x - 1, y, map_sol);
	if (map_sol[x + 1][y] != '1')
		dfs(s_data, x + 1, y, map_sol);
	return ;
}

int	main(void)
{
	t_data	s_data;
	char	**map_sol = calloc(5, sizeof(char *));

	map_sol[0] = calloc(10, sizeof(char));
	map_sol[1] = calloc(10, sizeof(char));
	map_sol[2] = calloc(10, sizeof(char));
	map_sol[3] = calloc(10, sizeof(char));
	map_sol[4] = calloc(10, sizeof(char));
	strcpy(map_sol[0], "111111111"); 
	strcpy(map_sol[1], "100000E01"); 
	strcpy(map_sol[2], "1CP0010C1"); 
	strcpy(map_sol[3], "10001C101"); 
	strcpy(map_sol[4], "111111111"); 
	s_data = (t_data){0};
	dfs(&s_data, 2, 2, map_sol);
	printf("c_reach > |%d|\n", s_data.c_reach);
	printf("p_reach > |%d|\n", s_data.e_reach);
}
