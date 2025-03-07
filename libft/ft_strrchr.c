/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alshakhp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 13:55:54 by alshakhp          #+#    #+#             */
/*   Updated: 2024/09/10 13:55:58 by alshakhp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*last = 0;

	while (*s != '\0')
	{
		if (*s == (char)c)
		{
			last = s;
		}
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return ((char *)last);
	return (0);
}
/*
// Function to print result of strchr
void print_result(const char *s, char c) 
{
    char *result = ft_strrchr(s, c);
    if (result) {
        printf("Found '%c' at position: %ld\n", c, result - s);
    } else {
        printf("Character '%c' not found.\n", c);
    }
}

int main() 
{
    const char *str = "Hello, worlo!";

    // Test custom strchr
    printf("Testing custom strchr:\n");
    print_result(str, 'o');  // Test finding a character that exists
    print_result(str, ',');  // Test finding a character that exists
    print_result(str, 'z');  // Test finding a character that does not exist
    print_result(str, '\0'); // Test finding the null terminator

    // Test standard strchr if available
    printf("\nTesting standard strchr:\n");
    char *result;
    
    result = strrchr(str, 'o');
    if (result) {
        printf("Found 'o' at position: %ld\n", result - str);
    } else {
        printf("Character 'o' not found.\n");
    }
    
    result = strrchr(str, ',');
    if (result) {
        printf("Found ',' at position: %ld\n", result - str);
    } else {
        printf("Character ',' not found.\n");
    }

    result = strrchr(str, 'z');
    if (result) {
        printf("Found 'z' at position: %ld\n", result - str);
    } else {
        printf("Character 'z' not found.\n");
    }
    
    result = strrchr(str, '\0');
    if (result) {
        printf("Found '\\0' at position: %ld\n", result - str);
    } else {
        printf("Null terminator not found.\n");
    }

    return 0;
}
*/
