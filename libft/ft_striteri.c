/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alshakhp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 10:29:55 by alshakhp          #+#    #+#             */
/*   Updated: 2024/09/17 10:29:56 by alshakhp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	if (!s || !f)
		return ;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
/*
// Example function to be used with ft_striteri
void example_func(unsigned int i, char *c) {
    i = i;
    *c = *c - 32;  // Increment character value
}
// Function to print the result
void print_result(const char *s) {
    if (s) {
        printf("\"%s\"\n", s);
    } else {
        printf("NULL\n");
    }
}

int main() {
    char str[] = "hello";
    ft_striteri(str, example_func);
    
    printf("Result:\n");
    print_result(str);

    return 0;
}
*/
