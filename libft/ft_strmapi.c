/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alshakhp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 10:06:04 by alshakhp          #+#    #+#             */
/*   Updated: 2024/09/17 10:06:06 by alshakhp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	size_t			len;
	char			*res;

	len = 0;
	i = 0;
	if (!s || !f)
		return (NULL);
	while (s[len])
		len++;
	res = (char *)malloc(len + 1);
	if (!res)
		return (NULL);
	while (i < len)
	{
		res[i] = f(i, s[i]);
		i++;
	}
	res[len] = '\0';
	return (res);
}
/*
char example_func(unsigned int i, char c) {
    i = i + 1;
    return c - 32;  // Simple transformation: increment character
}

// Function to print the result
void print_result(const char *result) {
    if (result) {
        printf("\"%s\"\n", result);
    } else {
        printf("NULL\n");
    }
}

int main() {
    const char *str = "hello";
    char *result = ft_strmapi(str, example_func);
    
    printf("Result:\n");
    print_result(result);

    // Free allocated memory
    free(result);

    return 0;
}
*/		
