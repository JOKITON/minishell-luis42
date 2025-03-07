/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alshakhp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 11:04:49 by alshakhp          #+#    #+#             */
/*   Updated: 2024/09/10 11:05:03 by alshakhp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
#include <stdio.h>
#include <string.h>*/

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const unsigned char	*s;
	unsigned char		*d;

	s = src;
	d = dest;
	if (d < s)
	{
		while (n--)
		{
			*d++ = *s++;
		}
	}
	else
	{
		d += n;
		s += n;
		while (n--)
		{
			*(--d) = *(--s);
		}
	}
	return (dest);
}
/*
// Function to print buffer contents
void print_buffer(const char *buffer, size_t size) {
    for (size_t i = 0; i < size; ++i) {
        printf("%c", buffer[i] ? buffer[i] : '.');
    }
    printf("\n");
}

int	main() 
{
    char buffer[30] = "Overlap Test Example!";
    
    // Print buffer before memmove
    printf("Buffer before memmove:\n");
    print_buffer(buffer, sizeof(buffer));
    
    // Test custom memmove: move a portion of the buffer to an overlapping region
    ft_memmove(buffer + 5, buffer, 15);
    printf("Buffer after custom memmove (overlapping):\n");
    print_buffer(buffer, sizeof(buffer));
    
    // Reset buffer
    strcpy(buffer, "Overlap Test Example!");
    

    memmove(buffer + 5, buffer, 15);
    printf("Buffer after standard memmove (overlapping):\n");
    print_buffer(buffer, sizeof(buffer));

    // Test non-overlapping case
    strcpy(buffer, "Non-Overlap Test!");
    ft_memmove(buffer + 5, buffer, strlen(buffer) + 1);
    printf("Buffer after custom memmove (non-overlapping):\n");
    print_buffer(buffer, sizeof(buffer));
    
    // Reset buffer
    strcpy(buffer, "Non-Overlap Test!");

    memmove(buffer + 5, buffer, strlen(buffer) + 1);
    printf("Buffer after standard memmove (non-overlapping):\n");
    print_buffer(buffer, sizeof(buffer));

    return 0;
}
*/
