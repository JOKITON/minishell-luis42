/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alshakhp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 12:31:50 by alshakhp          #+#    #+#             */
/*   Updated: 2025/02/10 12:31:51 by alshakhp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void free_tools(t_general *general)
{
    if (general->paths)
        free_array(general->paths);
    if (general->envp)
        free_array(general->envp);
    if (general->args)
        free(general->args);
    ft_simple_cmdsclear(&general->cmds);
    if (general->pwd)
        free(general->pwd);
    if (general->oldpwd)
        free(general->oldpwd);
    if (general->pipes && general->pid)
        free(general->pid);
}

int	is_str_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

void	determine_exit_code(char **str)
{
	int	exit_code;

	if (!str[1])
		exit_code = 0;
	else if (is_str_digit(str[1]))
		exit_code = ft_atoi(str[1]);
	else
	{
		ft_putstr_fd("minishell: exit: ", STDERR_FILENO);
		ft_putstr_fd(str[1], STDERR_FILENO);
		ft_putstr_fd(": numeric argument required\n", STDERR_FILENO);
		exit_code = 255;
	}
	free_array(str);
	exit(exit_code);
}


int	mini_exit(t_general *general, t_comands *cmds)
{
	char	**str;

	printf("exit\n");
	if (cmds->str[1] && cmds->str[2])
	{
		ft_putstr_fd("minishell: exit: too many arguments\n", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	str = ft_dupl_array(cmds->str);
	free_tools(general);
	determine_exit_code(str);
	return (EXIT_SUCCESS);
}
