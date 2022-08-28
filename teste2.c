/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teste2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaiago <gsaiago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 13:32:19 by gsaiago           #+#    #+#             */
/*   Updated: 2022/08/28 19:24:17 by gsaiago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char **ft_create_map_array(char *map, t_data *s_data)
{
	int		i;
	int		fd;
	char	**array;
	
	
	array = ft_calloc(s_data->size_y + 1, sizeof(char *));
	if (!array)
			return(NULL);
	fd = open(map, O_RDONLY);
	if (fd < 2)
			return(NULL);
	i = 0;
	while(i < s_data->size_y - 1)
	{
		array[i] = get_next_line(fd);
		i++;
	}
	close(fd);
	return (array);
}

int	main(void)
{
	t_data s_data;
	char	**array;
	char	*map = "./map.ber";

	s_data.size_y = 4;
	array = ft_create_map_array(map, &s_data);
	return (0);
}
