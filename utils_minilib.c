/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_minilib.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaiago <gsaiago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 11:00:02 by gsaiago           #+#    #+#             */
/*   Updated: 2022/08/18 16:29:10 by gsaiago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>

int	trgb(int t, int r, int g, int b);

int	trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}
