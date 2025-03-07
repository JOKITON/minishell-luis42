/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alshakhp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 12:03:40 by alshakhp          #+#    #+#             */
/*   Updated: 2025/02/17 12:03:41 by alshakhp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char **ft_dupl_array(char **array)
{
    char **dupl;
    size_t i;

    i = 0;
    while(array[i] != NULL)
		i++;
	dupl = ft_calloc(sizeof(char *), i + 1);
    if (!dupl)
        return (NULL);
    i = 0;
    while(array[i] != NULL)
    {
        dupl[i] = ft_strdup(array[i]);
        if(dupl[i] == NULL)
        {
            free_array(dupl);
            return (dupl);
        }
        i++;
    }
    return(dupl);
}

t_comands	*ft_simple_cmdsnew(char **str,
	int num_redirections, t_lexer *redirections)
{
	t_comands	*new_element;

	new_element = (t_comands *)malloc(sizeof(t_comands));
	if (!new_element)
		return (0);
	new_element->str = str;
	new_element->builtin = builtin_arr(str[0]);
	new_element->hd_file_name = NULL;
	new_element->num_redirections = num_redirections;
	new_element->redirections = redirections;
	new_element->next = NULL;
	new_element->prev = NULL;
	return (new_element);
}

void	ft_simple_cmdsadd_back(t_comands **lst, t_comands *new)
{
	t_comands	*tmp;

	tmp = *lst;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
	new->prev = tmp;
}

void	ft_simple_cmds_rm_first(t_comands **lst)
{
	t_comands	*tmp;

	if (!*lst)
		return ;
	tmp = (*lst)->next;
	ft_lexerclear(&(*lst)->redirections);
	free(*lst);
	*lst = tmp;
}

void	ft_simple_cmdsclear(t_comands **lst)
{
	t_comands	*tmp;
	t_lexer			*redirections_tmp;

	if (!*lst)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		redirections_tmp = (*lst)->redirections;
		ft_lexerclear(&redirections_tmp);
		if ((*lst)->str)
			free_array((*lst)->str);
		if ((*lst)->hd_file_name)
			free((*lst)->hd_file_name);
		free(*lst);
		*lst = tmp;
	}
	*lst = NULL;
}

t_comands	*ft_simple_cmdsfirst(t_comands *map)
{
	int	i;

	i = 0;
	if (!map)
		return (NULL);
	while (map->prev != NULL)
	{
		map = map->prev;
		i++;
	}
	return (map);
}
