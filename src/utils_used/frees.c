/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alshakhp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 12:02:04 by alshakhp          #+#    #+#             */
/*   Updated: 2025/02/17 12:02:06 by alshakhp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void free_array(char **split_array)
{
    int j;

    j = 0;
    while(split_array[j])
    {
        free(split_array[j++]);
    }
    free(split_array);
}

void clear_lexer(t_lexer **last)
{
    t_lexer *temp;
    
    if(!*last)
    {
        return ;
    }
    while(*last)
    {
        temp = (*last)->next;
        if((*last)->str)
            free((*last)->str);
        free(*last);
        *last = temp;
    }
    *last = NULL;
}

void comands_clear(t_comands **last)
{
    t_comands *temp;
    t_lexer *redirection;

    if(!*last)
    {
        return ;
    }
    while (*last)
    {
        temp = (*last)->next;
        redirection = (*last)->redirections;
        clear_lexer(&redirection);
        if((*last)->str)
        {
            free_array((*last)->str);
        }
        if((*last)->hd_file_name)
        {
            free((*last)->hd_file_name);
        }
        free(*last);
        *last = temp;
    }
    *last = NULL;
}

