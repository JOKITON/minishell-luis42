/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alshakhp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 10:31:05 by alshakhp          #+#    #+#             */
/*   Updated: 2024/10/04 10:31:09 by alshakhp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*#include <stdio.h>

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
*/
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!new || !*lst)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	last = *lst;
	while (last->next)
		last = last->next;
	last->next = new;
}
/*
void	ft_lstprint(t_list *lst)
{
	while (lst)
	{
		printf("%s -> ", (char *)lst->content); 
		lst = lst->next;
	}
	printf("NULL\n");
}
int	main(void)
{
	t_list	*list = NULL;
	t_list	*new_elem;

	// Add first element to the empty list
	new_elem = ft_lstnew("First");
	ft_lstadd_back(&list, new_elem);

	// Add second element to the list
	new_elem = ft_lstnew("Second");
	ft_lstadd_back(&list, new_elem);

	// Add third element to the list
	new_elem = ft_lstnew("Third");
	ft_lstadd_back(&list, new_elem);

	// Print the list
	ft_lstprint(list);

	// Free the list if necessary (not shown here for brevity)

	return (0);
}
*/
