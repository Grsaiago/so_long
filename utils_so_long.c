/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_so_long.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaiago <gsaiago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 14:34:20 by gsaiago           #+#    #+#             */
/*   Updated: 2022/09/07 16:20:25 by gsaiago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_writenbr(int nbr)
{
	long	n;
	int		nb;

	n = (long)nbr;
	if (n < 10 && n >= 0)
	{
		nb = n + 48;
		write (1, &nb, 1);
		return ;
	}
	else
		ft_writenbr(n / 10);
	ft_writenbr(n % 10);
	return ;
}
