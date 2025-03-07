/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alshakhp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 10:36:32 by alshakhp          #+#    #+#             */
/*   Updated: 2024/10/04 10:36:34 by alshakhp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*#include <stdio.h>*/

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
/*
t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}

int main(void)
{
    t_list *node1 = ft_lstnew("1");
    t_list *node2 = ft_lstnew("5");
    t_list *node3 = ft_lstnew("7");

    node1->next = node2;
    node2->next = node3;

    t_list *last_node = ft_lstlast(node1);
    if (last_node)
        printf("Last node content: %s\n", (char *)last_node->content);  
    
    return 0;
}
*/
