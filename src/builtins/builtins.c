/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alshakhp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 11:46:09 by alshakhp          #+#    #+#             */
/*   Updated: 2025/02/03 11:46:11 by alshakhp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	(*builtin_arr(char *str))(t_general *general, t_comands *cmds)
{
	static void	*builtins[7][2] = {
	{"echo", mini_echo},
	{"cd", mini_cd},
	{"pwd", mini_pwd},
	{"export", mini_export},
	{"unset", mini_unset},
	{"env", mini_env},
	{"exit", mini_exit}
	};
	int			i;

	i = 0;
	while (i < 7)
	{
		if (str)
		{
			if (!ft_strncmp(builtins[i][0], str, ft_strlen((builtins[i][0]))))
				return (builtins[i][1]);
		}
		i++;
	}
	return (NULL);
}
