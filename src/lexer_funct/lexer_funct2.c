/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_funct2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alshakhp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 13:25:06 by alshakhp          #+#    #+#             */
/*   Updated: 2025/02/27 13:25:08 by alshakhp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int quotes_manage(int i, char *s, char c)
{
    int j;

    j = 0;
    if(s[i + j] == c)
    {
        j++;
        while(s[i + j] != c && s[i + j])
        {
            j++;
        }
        j++;
    }
    return(j);
}

int words_reader(int i, char *s, t_lexer **list)
{
    int x;

    x = 0;
    while((size_t)(i + x) < strlen(s) && s[i + x] && !(is_token(s[i + x])))
    {
        x += quotes_manage(i + x, s, 34);
        x += quotes_manage(i + x, s, 39);
        if(space(s[i + x]))
        {
            break ;
        }
        else
        {
            x++;
        }
    }
    if(!node_sum_empty(ft_substr(s, i, x), 0, list))
    {
        return (-1);
    }
    return(x);
}
