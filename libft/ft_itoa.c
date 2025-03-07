/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alshakhp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 12:36:35 by alshakhp          #+#    #+#             */
/*   Updated: 2024/09/16 12:36:38 by alshakhp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*is_positive(char *str, int n, int i)
{
	while (n > 0)
	{
		str[i--] = (n % 10) + '0';
		n = n / 10;
	}
	return (str);
}

static size_t	get_num_len(int n)
{
	size_t	len;

	len = 0;
	if (n < 0)
	{
		if (n == -2147483648)
			return (11);
		len = 1;
		n = -n;
	}
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 10;
		len ++;
	}
	return (len);
}

static char	*spec_case(void)
{
	char	*str;

	str = ft_strdup("-2147483648");
	return (str);
}

char	*ft_itoa(int n)
{
	size_t	len;
	char	*str;
	int		i;

	if (n == -2147483648)
		return (spec_case());
	len = get_num_len(n);
	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	i = len - 1;
	if (n < 0)
	{
		n = -n;
		str[0] = '-';
	}
	if (n == 0)
		str[0] = '0';
	else
	{
		return (is_positive(str, n, i));
	}
	return (str);
}
