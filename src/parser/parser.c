/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alshakhp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 13:40:50 by alshakhp          #+#    #+#             */
/*   Updated: 2025/01/30 13:40:52 by alshakhp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_comands	*initialize_cmd(t_general *general)
{
	char	**str;
	int		i;
	int		arg_size;
	t_lexer	*tmp;

	i = 0;
	rm_redirections(general);
	arg_size = count_args(general->lexer_list);
	str = ft_calloc(arg_size + 1, sizeof(char *));
	if (!str)
		parser_error(1, general, general->lexer_list);
	tmp = general->lexer_list;
	while (arg_size > 0)
	{
		if (tmp->str)
		{
			str[i++] = ft_strdup(tmp->str);
			ft_lexerdelone(&general->lexer_list, tmp->i);
			tmp = general->lexer_list;
		}
		arg_size--;
	}
	return (ft_simple_cmdsnew(str,
			general->num_redirections, general->redirections));
}


int look_pwd(t_general *general)
{
    int j;

    j = 0;
    while(general->envp[j])
    {
        if(!ft_strncmp(general->envp[j],"OLDPWD=", 7))
        {
            general->oldpwd = ft_substr(general->envp[j], 7, ft_strlen(general->envp[j]) - 7);
        }
        if(!ft_strncmp(general->envp[j], "PWD=", 4))
        {
            general->pwd = ft_substr(general->envp[j], 4, ft_strlen(general->envp[j]) - 4);
			printf("general->pwd %s\n", general->pwd);
        }
        j++;
    }
    return (1);
}

int	handle_pipe_errors(t_general *general, t_tokens token)
{
	if (token == PIPE)
	{
		parser_double_token_error(general, general->lexer_list,
			general->lexer_list->token);
		return (EXIT_FAILURE);
	}
	if (!general->lexer_list)
	{
		parser_error(0, general, general->lexer_list);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	parser(t_general *general)
{
	t_comands	*node;
	t_general	parser_tools;

	general->cmds = NULL;
	count_pipes(general->lexer_list, general);
	if (!general->lexer_list)
		ft_error(1, general);
	if (general->lexer_list->token == PIPE)
		return (parser_double_token_error(general, general->lexer_list,
				general->lexer_list->token));
	while (general->lexer_list)
	{
		if (general->lexer_list && general->lexer_list->token == PIPE)
			ft_lexerdelone(&general->lexer_list, general->lexer_list->i);
		if (handle_pipe_errors(general, general->lexer_list->token))
			return (EXIT_FAILURE);
		parser_tools = init_parser_tools(general->lexer_list, general);
		node = initialize_cmd(&parser_tools);
		if (!node)
			parser_error(0, general, general->lexer_list);
		if (!general->cmds)
			general->cmds = node;
		else
			ft_simple_cmdsadd_back(&general->cmds, node);
		general->lexer_list = parser_tools.lexer_list;
	}
	return (EXIT_SUCCESS);
}

int env_pars(t_general *general)
{
    char *temp;
    char *path;
    int j;

    j = 0;
    path = check_path(general->envp);
    general->paths = ft_split(path, ':');
    free(path);

    while(general->paths[j])
    {
        if(ft_strncmp(&general->paths[j][ft_strlen(general->paths[j]) - 1], "/", 1) != 0)
        {
            temp = ft_strjoin(general->paths[j], "/");
            if (temp == NULL)
            	return(ft_error(1, general));
            free(general->paths[j]);
            general->paths[j] = temp;
        }
        j++;
    }
    return(EXIT_SUCCESS);
}

char *check_path(char **env)
{
    int j;

    j = 0;
    while(env[j])
    {
        if(!ft_strncmp(env[j], "PATH=", 5))
        {
            return(ft_substr(env[j], 5, ft_strlen(env[j]) - 5));
        }
        j++;
    }
    return(ft_strdup("\0"));
}
