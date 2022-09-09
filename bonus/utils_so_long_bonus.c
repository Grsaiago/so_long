/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_so_long_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaiago <gsaiago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 16:59:12 by gsaiago           #+#    #+#             */
/*   Updated: 2022/09/09 19:12:33 by gsaiago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	ft_lencount(long n);

char	*ft_itoa(long int n)
{
	long	len;
	char	*itoa;

	len = ft_lencount(n);
	itoa = ft_calloc(len + 2, 1);
	if (!itoa)
		return (NULL);
	len--;
	while (n > 0)
	{
		itoa[len] = (n % 10) + '0';
		n = n / 10;
		len--;
	}
	return (itoa);
}

static int	ft_lencount(long n)
{
	int	len;

	len = 0;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}
