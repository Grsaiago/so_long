/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teste2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaiago <gsaiago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 13:32:19 by gsaiago           #+#    #+#             */
/*   Updated: 2022/08/29 10:56:26 by gsaiago          ###   ########.fr       */
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
	int		i = -1;

	s_data.map_name = "./map.ber";
	s_data.size_y = 3;
	array = create_map_array(&s_data);
	while (array[++i])
		free (array[i]);
	free (array);
	return (0);
}
