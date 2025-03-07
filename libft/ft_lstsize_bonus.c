/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alshakhp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 10:29:59 by alshakhp          #+#    #+#             */
/*   Updated: 2024/10/04 10:30:01 by alshakhp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
*/

int	ft_lstsize(t_list *lst)
{
	int	num;

	num = 0;
	while (lst != NULL)
	{
		num++;
		lst = lst->next;
	}
	return (num);
}
/*
t_list *ft_lstnew(void *content)
{
    t_list *new_node;

    new_node = (t_list *)malloc(sizeof(t_list));
    if (!new_node)
        return (NULL);
    new_node->content = content;
    new_node->next = NULL;
    return (new_node);
}

// Test ft_lstsize function
int main()
{
    // Create an empty list
    t_list *head = NULL;

    // Test with an empty list
    printf("Size of empty list: %d\n", ft_lstsize(head));

    // Add some nodes
    head = ft_lstnew("Node 1");
    head->next = ft_lstnew("Node 2");
    head->next->next = ft_lstnew("Node 3");

    // Test with 3 nodes
    printf("Size of list with 3 nodes: %d\n", ft_lstsize(head));

    // Free memory
    free(head->next->next);
    free(head->next);
    free(head);

    return 0;
}
*/
