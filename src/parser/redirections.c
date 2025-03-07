/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alshakhp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 13:53:45 by alshakhp          #+#    #+#             */
/*   Updated: 2025/01/30 13:53:47 by alshakhp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*join_heredoc(char *str1, char *str2)
{
	char	*ret;
	char	*tmp;

	if (!str2)
		return (ft_strdup(str1));
	tmp = ft_strjoin(str1, " ");
	ret = ft_strjoin(tmp, str2);
	free(tmp);
	free(str2);
	return (ret);
}

int	add_new_redirection(t_lexer *tmp, t_general *general)
{
	t_lexer	*node;
	int		index_1;
	int		index_2;

	node = ft_lexernew(ft_strdup(tmp->next->str), tmp->token);
	if (!node)
		parser_error(1, general, general->lexer_list);
	ft_lexeradd_back(&general->redirections, node);
	index_1 = tmp->i;
	index_2 = tmp->next->i;
	ft_lexerdelone(&general->lexer_list, index_1);
	ft_lexerdelone(&general->lexer_list, index_2);
	general->num_redirections++;
	return (0);
}

void	rm_redirections(t_general *general)
{
	t_lexer	*tmp;

	tmp = general->lexer_list;
	while (tmp && tmp->token == 0)
		tmp = tmp->next;
	if (!tmp || tmp->token == PIPE)
		return ;
	if (!tmp->next)
		parser_error(0, general, general->lexer_list);
	if (tmp->next->token)
		parser_double_token_error(general,
			general->lexer_list, tmp->next->token);
	if ((tmp->token >= GREAT
			&& tmp->token <= D_LESS))
		add_new_redirection(tmp, general);
	rm_redirections(general);
}
