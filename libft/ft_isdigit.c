/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alshakhp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 12:56:43 by alshakhp          #+#    #+#             */
/*   Updated: 2024/09/09 12:57:20 by alshakhp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>
#include <ctype.h>*/

#include "libft.h"

int	ft_isdigit(int c)
{
	if ((c >= '0') && (c <= '9'))
	{
		return (2048);
	}
	return (0);
}
/*
int main()
{
	int	c = 65;
	printf("%d", ft_isdigit(c));
	printf("%d", isdigit(c));
}
*/
