/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_funct1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alshakhp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 13:24:27 by alshakhp          #+#    #+#             */
/*   Updated: 2025/02/27 13:24:29 by alshakhp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_lexer *lex_new(char *s, int tok)
{
    t_lexer *new;
    static int i;

    i = 0;
    new = (t_lexer *)malloc(sizeof(t_lexer));
    if(!new)
    {
        return(0);
    }
    new->str = s;
    new->token = tok;
    new->i = i++;
    new->next = NULL;
    new->prev = NULL;
    return(new);
}

void add_back(t_lexer **last, t_lexer *new)
{
    t_lexer *temp;
    temp = *last;
    if(*last == NULL)
    {
        *last = new;
        return ;
    } 
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = new;
    new->prev = temp;
}

int node_sum_empty(char *s, t_tokens tok, t_lexer **list)
{
    t_lexer *nodo;

    nodo = lex_new(s, tok);
    if (!nodo)
    {
        return (0);
    }
    add_back(list, nodo);
    return(1);
}

int token_manage(char *s, t_lexer **list, int j)
{
    t_tokens token;
    
    token = is_token(s[j]);
    if(token == GREAT && is_token(s[j + 1] == GREAT))
    {
        if(!node_sum_empty(NULL, D_GREAT, list))
        {
            return(-1);
        }
        return(2);
    }
    else if(token == LESS && is_token(s[j + 1] == LESS))
    {
        if(!node_sum_empty(NULL, D_LESS, list))
        {
            return(-1);
        }
        return(2);
    }
    else if(token)
    {
        if(!node_sum_empty(NULL, token, list))
        {
            return(-1);
        }
        return(1);
    }
    return(0);
}
