/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alshakhp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 11:23:23 by alshakhp          #+#    #+#             */
/*   Updated: 2025/02/24 11:23:24 by alshakhp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	loop_if_dollar_sign(t_general *general, char *str, char **tmp, int j)
{
	int		k;
	int		ret;
	char	*tmp2;
	char	*tmp3;

	k = 0;
	ret = 0;
	while (general->envp[k])
	{
		if (ft_strncmp(str + j + 1, general->envp[k],
				equal_sign(general->envp[k]) - 1) == 0
			&& after_dol_lenght(str, j) - j == (int)equal_sign(general->envp[k]))
		{
			tmp2 = ft_strdup(general->envp[k] + equal_sign(general->envp[k]));
			tmp3 = ft_strjoin(*tmp, tmp2);
			free(*tmp);
			*tmp = tmp3;
			free(tmp2);
			ret = equal_sign(general->envp[k]);
		}
		k++;
	}
	if (ret == 0)
		ret = after_dol_lenght(str, j) - j;
	return (ret);
}

int	handle_digit_after_dollar(int j, char *str)
{
	int	i;

	i = j;
	if (str[j] == '$')
	{
		if (ft_isdigit(str[j + 1]) == 1)
		{
			j += 2;
		}
	}
	return (j - i);
}

char	*detect_dollar_sign(t_general *general, char *str)
{
	int		j;
	char	*tmp;
	char	*tmp2;
	char	*tmp3;

	j = 0;
	tmp = ft_strdup("\0");
	while (str[j])
	{
		j += handle_digit_after_dollar(j, str);
		if (str[j] == '$' && str[j + 1] == '?')
			j += question_mark(&tmp);
		else if (str[j] == '$' && (str[j + 1] != ' ' && (str[j + 1] != '"'
					|| str[j + 2] != '\0')) && str[j + 1] != '\0')
			j += loop_if_dollar_sign(general, str, &tmp, j);
		else
		{
			tmp2 = char_to_str(str[j++]);
			tmp3 = ft_strjoin(tmp, tmp2);
			free(tmp);
			tmp = tmp3;
			free(tmp2);
		}
	}
	return (tmp);
}

char	**expander(t_general *general, char **str)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = NULL;
	while (str[i] != NULL)
	{
		printf("Str[%d] : %s\n", i, str[i]);
		/* Problem:
		- dollar_sign() is being substracted 2, it can fall down on these cases:
		1. (-2) : The input does not have any dollar sign (0 - 2) -> Invalid Read
		2. (-1) : The input does have a dollar sign at index 0, dollar_sign() returns 1, (1 - 2) -> Invalid Read
		*/
		/* How to fix:
			1. Check single/double commas in an independent function, return boolean 
			2. Decide to ignore or substract these values depending on the boolean
		*/
		printf("Index trying to read inside str : %ld\n", dollar_sign(str[i]) - 2);

		if (str[i][dollar_sign(str[i]) - 2] != '\'' && dollar_sign(str[i]) != 0
			&& str[i][dollar_sign(str[i])] != '\0')
		{
			tmp = detect_dollar_sign(general, str[i]);
			free(str[i]);
			str[i] = tmp;
		}
		if (ft_strncmp(str[0], "export", ft_strlen(str[0]) - 1) != 0)
		{
			str[i] = delete_quotes(str[i], '\"');
			str[i] = delete_quotes(str[i], '\'');
		}
		i++;
	}
	return (str);
}

char	*expander_str(t_general *general, char *str)
{
	char	*tmp;

	tmp = NULL;
	if (str[dollar_sign(str) - 2] != '\'' && dollar_sign(str) != 0
		&& str[dollar_sign(str)] != '\0')
	{
		tmp = detect_dollar_sign(general, str);
		free(str);
		str = tmp;
	}
	str = delete_quotes(str, '\"');
	str = delete_quotes(str, '\'');
	return (str);
}
