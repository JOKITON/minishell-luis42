/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_unset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alshakhp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 13:49:44 by alshakhp          #+#    #+#             */
/*   Updated: 2025/02/10 13:49:45 by alshakhp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	**whileloop_del_var(char **arr, char **rtn, char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (arr[i] != NULL)
	{
		if (!(ft_strncmp(arr[i], str, equal_sign(arr[i]) - 1) == 0
				&& str[equal_sign(arr[i])] == '\0'
				&& arr[i][ft_strlen(str)] == '='))
		{
			rtn[j] = ft_strdup(arr[i]);
			if (rtn[j] == NULL)
			{
				free_array(rtn);
				return (rtn);
			}
			j++;
		}	
		i++;
	}
	return (rtn);
}

int	unset_error(t_comands *cmds)
{
	int		i;

	i = 0;
	if (!cmds->str[1])
	{
		ft_putendl_fd("minishell: unset: not enough arguments", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	while (cmds->str[1][i])
	{
		if (cmds->str[1][i++] == '/')
		{
			ft_putstr_fd("minishell: unset: `", STDERR_FILENO);
			ft_putstr_fd(cmds->str[1], STDERR_FILENO);
			ft_putendl_fd("': not a valid identifier", STDERR_FILENO);
			return (EXIT_FAILURE);
		}
	}
	if (equal_sign(cmds->str[1]) != 0)
	{
		ft_putendl_fd("minishell: unset: not a valid identifier",
			STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

char	**del_var(char **arr, char *str)
{
	char	**rtn;
	size_t	i;
	
	i = 0;
	while (arr[i] != NULL)
		i++;
	rtn = ft_calloc(sizeof(char *), i + 1);
	if (!rtn)
		return (NULL);
	rtn = whileloop_del_var(arr, rtn, str);
	return (rtn);
}

int	mini_unset(t_general *general, t_comands *cmds)
{
	char	**tmp;

	if (unset_error(cmds) == 1)
		return (EXIT_FAILURE);
	else
	{
		tmp = del_var(general->envp, cmds->str[1]);
		free_array(general->envp);
		general->envp = tmp;
	}
	return (EXIT_SUCCESS);
}
