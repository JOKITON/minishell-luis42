/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_cd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alshakhp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 12:15:14 by alshakhp          #+#    #+#             */
/*   Updated: 2025/02/03 12:15:16 by alshakhp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*find_path_ret(char *str, t_general *general)
{
	int	i;

	i = 0;
	while (general->envp[i])
	{
		if (!ft_strncmp(general->envp[i], str, ft_strlen(str)))
			return (ft_substr(general->envp[i], ft_strlen(str),
					ft_strlen(general->envp[i]) - ft_strlen(str)));
		i++;
	}
	return (NULL);
}

int	specific_path(t_general *general, char *str)
{
	char	*tmp;
	int		ret;

	tmp = find_path_ret(str, general);
	ret = chdir(tmp);
	free(tmp);
	if (ret != 0)
	{
		str = ft_substr(str, 0, ft_strlen(str) - 1);
		ft_putstr_fd(str, STDERR_FILENO);
		free(str);
		ft_putendl_fd(" not set", STDERR_FILENO);
	}
	return (ret);
}

void	add_path_to_env(t_general *general)
{
	int		i;
	char	*tmp;

	i = 0;
	while (general->envp[i])
	{
		if (!ft_strncmp(general->envp[i], "PWD=", 4))
		{
			tmp = ft_strjoin("PWD=", general->pwd);
			free(general->envp[i]);
			general->envp[i] = tmp;
		}
		else if (!ft_strncmp(general->envp[i], "OLDPWD=", 7) && general->oldpwd)
		{
			tmp = ft_strjoin("OLDPWD=", general->oldpwd);
			free(general->envp[i]);
			general->envp[i] = tmp;
		}
		i++;
	}
}

int	mini_cd(t_general *general, t_comands *cmds)
{
	int		ret;

	if (!cmds->str[1])
		ret = specific_path(general, "HOME=");
	else if (ft_strncmp(cmds->str[1], "..", 1) == 0)
		ret = specific_path(general, "OLDPWD=");
	else
	{
		ret = chdir(cmds->str[1]);
		if (ret != 0)
		{
			ft_putstr_fd("minishell: ", STDERR_FILENO);
			ft_putstr_fd(general->cmds->str[1], STDERR_FILENO);
			perror(" ");
		}
	}
	if (ret != 0)
		return (EXIT_FAILURE);
	change_path(general);
	add_path_to_env(general);
	return (EXIT_SUCCESS);
}
