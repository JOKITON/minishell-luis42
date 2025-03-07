/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alshakhp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 09:53:26 by alshakhp          #+#    #+#             */
/*   Updated: 2024/09/10 09:53:39 by alshakhp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c >= '0') && (c <= '9'))
	{
		return (8);
	}
	if ((c >= 'a') && (c <= 'z'))
	{
		return (8);
	}
	if ((c >= 'A') && (c <= 'Z'))
	{
		return (8);
	}
	return (0);
}
