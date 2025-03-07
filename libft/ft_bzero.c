/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alshakhp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 10:44:12 by alshakhp          #+#    #+#             */
/*   Updated: 2024/09/10 10:44:16 by alshakhp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*str;

	str = s;
	while (n--)
		*str++ = 0;
}
/*
void print_buffer(const char *buffer, size_t size) {
    for (size_t i = 0; i < size; ++i) {
        printf("%c", buffer[i] ? buffer[i] : '.');
    }
    printf("\n");
}

int main() {
    char buffer[20];

    // Fill the buffer with some data
    for (size_t i = 0; i < sizeof(buffer); ++i) {
        buffer[i] = 'A' + (i % 26);  // Fill with characters A-Z repeatedly
    }

    // Print buffer before bzero
    printf("Before bzero:\n");
    print_buffer(buffer, sizeof(buffer));

    // Apply bzero
    bzero(buffer, sizeof(buffer));

    // Print buffer after bzero
    printf("After bzero:\n");
    print_buffer(buffer, sizeof(buffer));
    for (size_t i = 0; i < sizeof(buffer); ++i) {
        buffer[i] = 'A' + (i % 26);  // Fill with characters A-Z repeatedly
    }
    // Print buffer before bzero
    printf("Before bzero:\n");
    print_buffer(buffer, sizeof(buffer));

    // Optionally, use the standard bzero if available for comparison
    bzero(buffer, sizeof(buffer));  // Standard bzero function
    printf("After standard bzero:\n");
    print_buffer(buffer, sizeof(buffer));

    return 0;
}
*/
