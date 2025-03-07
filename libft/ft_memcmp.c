/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alshakhp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 10:17:12 by alshakhp          #+#    #+#             */
/*   Updated: 2024/09/11 10:17:15 by alshakhp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
#include <string.h>
#include <stdio.h>*/

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	i;
	const char		*p1 = s1;
	const char		*p2 = s2;

	i = 0;
	while (i < n)
	{
		if (p1[i] != p2[i])
			return (p1[i] - p2[i]);
		i++;
	}
	return (0);
}
/*
int	main(void)
{
	char	s1[] = "atoms\0\0\0\0";
	char	s2[] = "atoms\0abc";

	printf("%d\n", ft_memcmp(s1, s2, 8));
	printf("%d\n", memcmp(s1, s2, 8));
}
*/
