/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alshakhp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 12:07:59 by alshakhp          #+#    #+#             */
/*   Updated: 2024/09/11 12:08:01 by alshakhp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	parse_sign(const char **str)
{
	int	sign;

	sign = 1;
	while (**str == ' ' || (**str >= 9 && **str <= 13))
		(*str)++;
	if (**str == '-' || **str == '+')
	{
		if (**str == '-')
			sign = -1;
		(*str)++;
	}
	return (sign);
}

static int	convert_to_int(const char *str, int sign)
{
	int	result;

	result = 0;
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return (result * sign);
}

int	ft_atoi(const char *nptr)
{
	int	sign;

	sign = parse_sign(&nptr);
	return (convert_to_int(nptr, sign));
}
/*
int	main(void)
{
	char	str[] = " -1234ab567";

	printf("Converted integer: %d\n", ft_atoi(str));
	printf("Converted integer: %d\n", atoi(str));
}
*/
