/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alshakhp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 10:19:59 by alshakhp          #+#    #+#             */
/*   Updated: 2024/09/10 10:20:02 by alshakhp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
#include <stdio.h>
#include <string.h>*/

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	val;

	str = s;
	val = c;
	while (n--)
		*str++ = val;
	return (s);
}
/*
int main() 
{
    char buffer[20];

    ft_memset(buffer, 'A', sizeof(buffer));

    for (size_t i = 0; i < sizeof(buffer); ++i) 
    {
        printf("%c", buffer[i]);
    }
    printf("\n");
     memset(buffer, 'A', sizeof(buffer));

    for (size_t i = 0; i < sizeof(buffer); ++i) 
    {
        printf("%c", buffer[i]);
    }
    printf("\n");
    
}
*/
