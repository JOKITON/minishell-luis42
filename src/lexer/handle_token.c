/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_token.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alshakhp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 13:25:35 by alshakhp          #+#    #+#             */
/*   Updated: 2025/01/30 13:25:36 by alshakhp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_tokens	check_token(int c)
{
	static int	token_arr[3][2] = {
	{'|', PIPE},
	{'>', GREAT},
	{'<', LESS},
	};
	int			i;

	i = 0;
	while (i < 3)
	{
		if (token_arr[i][0] == c)
			return (token_arr[i][1]);
		i++;
	}
	return (0);
}

int	handle_quotes(int i, char *str, char del)
{
	int	j;

	j = 0;
	if (str[i + j] == del)
	{
		j++;
		while (str[i + j] != del && str[i + j])
			j++;
		j++;
	}
	return (j);
}

int	handle_token(char *str, int i, t_lexer **lexer_list)
{
	t_tokens	token;

	token = check_token(str[i]);
	if (token == GREAT && check_token(str[i + 1]) == GREAT)
	{
		if (!add_node(NULL, D_GREAT, lexer_list))
			return (-1);
		return (2);
	}
	else if (token == LESS && check_token(str[i + 1]) == LESS)
	{
		if (!add_node(NULL, D_LESS, lexer_list))
			return (-1);
		return (2);
	}
	else if (token)
	{
		if (!add_node(NULL, token, lexer_list))
			return (-1);
		return (1);
	}	
	return (0);
}
