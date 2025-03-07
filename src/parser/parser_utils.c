/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alshakhp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 13:42:22 by alshakhp          #+#    #+#             */
/*   Updated: 2025/01/30 13:42:25 by alshakhp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_general	init_parser_tools(t_lexer *lexer_list, t_general *general)
{

	general->lexer_list = lexer_list;
	general->redirections = NULL;
	general->num_redirections = 0;
	return (*general);
}

void	count_pipes(t_lexer *lexer_list, t_general *general)
{
	t_lexer	*tmp;

	tmp = lexer_list;
	general->pipes = 0;
	while (tmp)
	{
		if (tmp->token == PIPE)
			general->pipes++;
		tmp = tmp->next;
	}
}

int	count_args(t_lexer *lexer_list)
{
	t_lexer	*tmp;
	int		i;

	i = 0;
	tmp = lexer_list;
	while (tmp && tmp->token != PIPE)
	{
		if (tmp->i >= 0)
			i++;
		tmp = tmp->next;
	}
	return (i);
}

t_lexer	*find_next_cmd(t_lexer *lexer_lst)
{
	while (lexer_lst && lexer_lst->token != PIPE)
		lexer_lst = lexer_lst->next;
	return (lexer_lst);
}
