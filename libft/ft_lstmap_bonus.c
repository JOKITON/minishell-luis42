/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alshakhp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 10:37:55 by alshakhp          #+#    #+#             */
/*   Updated: 2024/10/04 10:37:57 by alshakhp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

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

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*next;
	t_list	*current;
	
	if (!lst || !del)
		return;
	current = *lst;
	while (current)
	{
		next = current->next;
		del(current->content);
		free(current);
		current = next;
	}
	*lst = NULL;
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;
	
	if (!new)
		return;
	if (!*lst)
	{
		*lst = new;
		return;
	}
	last = *lst;
	while (last->next)
		last = last->next;
	last->next = new;
}

t_list	*ft_lstnew(void *content);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst, void (*del)(void *));
*/
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*current;
	t_list	*new_lst_cur;

	new_list = NULL;
	if (!lst || !f)
		return (NULL);
	current = lst;
	while (current)
	{
		new_lst_cur = ft_lstnew(f(current->content));
		if (!new_lst_cur)
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_lst_cur);
		current = current->next;
	}
	return (new_list);
}
