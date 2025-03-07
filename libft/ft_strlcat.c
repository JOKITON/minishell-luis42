/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alshakhp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 12:39:37 by alshakhp          #+#    #+#             */
/*   Updated: 2024/09/10 12:39:45 by alshakhp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const	char *src, size_t dstsize)
{
	size_t	dest_l;
	size_t	src_l;
	size_t	i;

	dest_l = 0;
	src_l = 0;
	i = 0;
	while (src[src_l] != '\0')
	{
		src_l++;
	}
	while (dest[dest_l] != '\0')
	{
		dest_l++;
	}
	if (dest_l >= dstsize)
		return (dstsize + src_l);
	while (i < (dstsize - dest_l) - 1 && src[i] != '\0')
	{
		dest[dest_l + i] = src[i];
		i++;
	}
	dest[dest_l + i] = '\0';
	return (dest_l + src_l);
}
/*
// Function to print buffer contents
void print_buffer(const char *buffer) {
    printf("Buffer: '%s'\n", buffer);
}

int main() {
    char dest[30] = "Hello, ";
    char src[] = "world!";

    // Test custom strlcat
    size_t len = ft_strlcat(dest, src, sizeof(dest));
    printf("Custom strlcat:\n");
    print_buffer(dest);
    printf("Length of concatenation result: %zu\n", len);


    // Test with small buffer (truncate case)
    strcpy(dest, "Hello");
    len = ft_strlcat(dest, src, 10);  // Buffer size is small to force truncation
    printf("Custom strlcat with small buffer:\n");
    print_buffer(dest);
    printf("Length of concatenation result: %zu\n", len);

    // Test with exactly enough space
    strcpy(dest, "Hi");
    len = ft_strlcat(dest, "there!", 10);  // Exactly enough space for "there!"
    printf("Custom strlcat with exact buffer size:\n");
    print_buffer(dest);
    printf("Length of concatenation result: %zu\n", len);

    // Test with zero size
    strcpy(dest, "Hello");
    len = ft_strlcat(dest, src, 0);  // Zero size, should not modify destination
    printf("Custom strlcat with zero size:\n");
    print_buffer(dest);
    printf("Length of concatenation result: %zu\n", len);

    return 0;
}
*/
