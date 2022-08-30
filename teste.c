/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teste.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaiago <gsaiago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 13:32:19 by gsaiago           #+#    #+#             */
/*   Updated: 2022/08/30 14:23:01 by gsaiago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char **create_map_array(t_data *s_data)
{
	int		i;
	int		fd;
	char	**array;
	
	
	array = ft_calloc(s_data->size_y + 1, sizeof(char *));
	if (!array)
			return(NULL);
	fd = open(s_data->map_name, O_RDONLY);
	if (fd < 2)
			return(NULL);
	i = 0;
	while(i < s_data->size_y)
	{
		array[i] = get_next_line(fd);
		i++;
	}
	close(fd);
	return (array);
}
