/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alshakhp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 10:28:50 by alshakhp          #+#    #+#             */
/*   Updated: 2024/10/04 10:28:53 by alshakhp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (new)
	{
		new->next = *lst;
		*lst = new;
	}
	*lst = new;
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

void print_list(t_list *head)
{
    t_list *temp = head;
    while (temp != NULL)
    {
        printf("Node content: %s\n", (char *)temp->content);
        temp = temp->next;
    }
}

int main()
{
    // Create an initial list
    t_list *head = NULL;
    
    // Add first node to the list
    char *content1 = "Node 1";
    t_list *node1 = ft_lstnew((void *)content1);
    ft_lstadd_front(&head, node1);  // Add node1 to the list

    // Add second node to the list
    char *content2 = "Node 2";
    t_list *node2 = ft_lstnew((void *)content2);
    ft_lstadd_front(&head, node2);  // Add node2 to the list

    // Add third node to the list
    char *content3 = "Node 3";
    t_list *node3 = ft_lstnew((void *)content3);
    ft_lstadd_front(&head, node3);  // Add node3 to the list

    // Print the list to verify
    print_list(head);

    // Free the memory
    free(node1);
    free(node2);
    free(node3);

    return 0;
}
*/
