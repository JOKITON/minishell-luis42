/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alshakhp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 14:48:00 by alshakhp          #+#    #+#             */
/*   Updated: 2025/02/03 14:48:02 by alshakhp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	mini_env(t_general *general, t_comands *cmds)
{
	int		i;

	(void) cmds;
	i = 0;
	while (general->envp[i])
	{
		ft_putendl_fd(general->envp[i], STDOUT_FILENO);
		i++;
	}
	return (EXIT_SUCCESS);
}
