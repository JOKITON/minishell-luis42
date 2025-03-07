/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alshakhp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 10:27:13 by alshakhp          #+#    #+#             */
/*   Updated: 2024/10/04 10:27:17 by alshakhp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*#include <stdio.h>
*/

t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}
/*
int main()
{
    // Test content
    char *content = "Hello, world!";
    
    // Create a new node using ft_lstnew
    t_list *node = ft_lstnew((void *)content);
    
    // Test if node was created successfully
    if (node == NULL)
    {
        printf("Failed to allocate memory for new node.\n");
        return 1;
    }
    
    // Print the content of the node
    printf("Node content: %s\n", (char *)node->content);

    // Check if the next pointer is NULL
    if (node->next == NULL)
        printf("Next pointer is NULL as expected.\n");

    // Free allocated memory
    free(node);

    return 0;
}
*/
