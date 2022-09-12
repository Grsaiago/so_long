/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teste.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaiago <gsaiago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 17:15:13 by gsaiago           #+#    #+#             */
/*   Updated: 2022/09/12 17:28:36 by gsaiago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mandatory/so_long.h"

int	main(void)
{
	t_data	s_data;
	char	**map_array;

	s_data = (t_data){0};
	validate_map(&s_data, "./map.ber");
	map_array = create_map_array(&s_data);
}
