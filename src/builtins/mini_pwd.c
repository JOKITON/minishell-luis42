/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_pwd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alshakhp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 13:41:34 by alshakhp          #+#    #+#             */
/*   Updated: 2025/02/10 13:41:37 by alshakhp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	mini_pwd(t_general *general, t_comands *cmds)
{
	(void) cmds;
	printf("%s\n", general->pwd);
	ft_putendl_fd(general->pwd, STDOUT_FILENO);
	return (EXIT_SUCCESS);
}
