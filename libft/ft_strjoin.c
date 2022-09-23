/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaiago <gsaiago@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 12:22:48 by gsaiago           #+#    #+#             */
/*   Updated: 2022/06/15 21:12:33 by gsaiago          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	int		count;
	char	*str;

	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	count = 0;
	str = ft_calloc((i + j + 1), 1);
	if (str == NULL)
		return (NULL);
	while (count < i)
	{
		str[count] = s1[count];
		count++;
	}
	while (--j >= 0)
		str[count + j] = s2[j];
	return (str);
}

/*
int	main (void)
{
	const char	str1[] = "Essa string aqui ta incompleta";
	const char	str2[] = "a não ser que seja com essa";

	printf("s1 > %s\n", str1); 
	printf("s2 > %s\n", str2); 
	printf("join > %s\n", ft_strjoin(str1, str2)); 
}
*/
