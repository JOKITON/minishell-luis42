/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alshakhp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 10:43:10 by alshakhp          #+#    #+#             */
/*   Updated: 2024/09/17 10:43:12 by alshakhp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
/*
int main() {
    // Output character 'A' to standard output (file descriptor 1)
    ft_putchar_fd('A', 1);

    // Output character 'B' to standard error (file descriptor 2)
    ft_putchar_fd('B', 2);
    return 0;
}
*/
