/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_export.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alshakhp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 12:46:39 by alshakhp          #+#    #+#             */
/*   Updated: 2025/02/10 12:46:41 by alshakhp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	variable_exist(t_general *general, char *str)
{
	int	i;

	i = 0;
	if (str[equal_sign(str)] == '\"')
		delete_quotes(str, '\"');
	if (str[equal_sign(str)] == '\'')
		delete_quotes(str, '\'');
	while (general->envp[i])
	{
		if (ft_strncmp(general->envp[i],
				str, equal_sign(general->envp[i])) == 0)
		{
			free(general->envp[i]);
			general->envp[i] = ft_strdup(str);
			return (1);
		}
		i++;
	}
	return (0);
}


int	check_parameter(char *str)
{
	int	i;

	i = 0;
	if (ft_isdigit(str[0]))
		return (export_error(str));
	if (equal_sign(str) == 0)
		return (EXIT_FAILURE);
	if (str[0] == '=')
		return (export_error(str));
	while (str[i] != '=')
	{
		if (check_valid_identifier(str[i]))
			return (export_error(str));
		i++;
	}
	return (EXIT_SUCCESS);
}

char	**whileloop_add_var(char **arr, char **rtn, char *str)
{
	int	i;

	i = 0;
	while (arr[i] != NULL)
	{
		if (arr[i + 1] == NULL)
		{
			rtn[i] = ft_strdup(str);
			rtn[i + 1] = ft_strdup(arr[i]);
		}
		else
			rtn[i] = ft_strdup(arr[i]);
		if (rtn[i] == NULL)
		{
			free_array(rtn);
			return (rtn);
		}
		i++;
	}
	return (rtn);
}

char	**add_var(char **arr, char *str)
{
	char	**rtn;
	size_t	i;

	i = 0;
	if (str[equal_sign(str)] == '\"')
		delete_quotes(str, '\"');
	if (str[equal_sign(str)] == '\'')
		delete_quotes(str, '\'');
	while (arr[i] != NULL)
		i++;
	rtn = ft_calloc(sizeof(char *), i + 2);
	if (!rtn)
		return (NULL);
	i = 0;
	whileloop_add_var(arr, rtn, str);
	return (rtn);
}

int	mini_export(t_general *general, t_comands *cmds)
{
	char	**tmp;
	int		i;

	i = 1;
	if (!cmds->str[1] || cmds->str[1][0] == '\0')
		mini_env(general, cmds);
	else
	{
		while (cmds->str[i])
		{
			if (check_parameter(cmds->str[i]) == 0
				&& variable_exist(general, cmds->str[i]) == 0)
			{
				if (cmds->str[i])
				{
					tmp = add_var(general->envp, cmds->str[i]);
					free_array(general->envp);
					general->envp = tmp;
				}
			}
			i++;
		}
	}
	return (EXIT_SUCCESS);
}
