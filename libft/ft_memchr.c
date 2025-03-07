/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alshakhp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 10:45:48 by alshakhp          #+#    #+#             */
/*   Updated: 2024/09/11 10:45:50 by alshakhp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
#include <string.h>
#include <stdio.h>*/

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*p1 = s;
	unsigned char		p2;
	unsigned char		i;

	p2 = c;
	i = 0;
	while (i < n)
	{
		if (p1[i] == p2)
			return ((void *)(p1 + i));
		i++;
	}
	return (0);
}
/*
// Function to print result of strchr
void print_result(const char *s, char c) 
{
    char *result = ft_memchr(s, c, 15);
    if (result) {
        printf("Found '%c' at position: %ld\n", c, result - s);
    } else {
        printf("Character '%c' not found.\n", c);
    }
}

int main() 
{
    const char *str = "Hello, \0world!";

    // Test custom strchr
    printf("Testing custom strchr:\n");
    print_result(str, 'd');  // Test finding a character that exists
    print_result(str, 'z');  // Test finding a character that does not exist

    // Test standard strchr if available
    printf("\nTesting standard strchr:\n");
    char *result;
    
    result = memchr(str, 'd', 15);
    if (result) {
        printf("Found 'd' at position: %ld\n", result - str);
    } else {
        printf("Character 'd' not found.\n");
    }
    
    result = memchr(str, 'z', 15);
    if (result) {
        printf("Found 'z' at position: %ld\n", result - str);
    } else {
        printf("Character 'z' not found.\n");
    }
    return 0;
}
*/
