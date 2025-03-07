/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_redir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alshakhp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 14:30:23 by alshakhp          #+#    #+#             */
/*   Updated: 2025/01/30 14:30:27 by alshakhp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	check_append_outfile(t_lexer *redirections)
{
	int	fd;

	if (redirections->token == D_GREAT)
		fd = open(redirections->str,
				O_CREAT | O_RDWR | O_APPEND, 0644);
	else
		fd = open(redirections->str,
				O_CREAT | O_RDWR | O_TRUNC, 0644);
	return (fd);
}

int	handle_infile(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("minishell: infile: No such file or directory\n",
			STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	if (fd > 0 && dup2(fd, STDIN_FILENO) < 0)
	{
		ft_putstr_fd("minishell: pipe error\n", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	if (fd > 0)
		close(fd);
	return (EXIT_SUCCESS);
}

int	handle_outfile(t_lexer *redirection)
{
	int	fd;

	fd = check_append_outfile(redirection);
	if (fd < 0)
	{
		ft_putstr_fd("minishell: outfile: Error\n", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	if (fd > 0 && dup2(fd, STDOUT_FILENO) < 0)
	{
		ft_putstr_fd("minishell: pipe error\n", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	if (fd > 0)
		close(fd);
	return (EXIT_SUCCESS);
}

int	check_redirections(t_comands *cmds)
{
	t_lexer	*start;

	start = cmds->redirections;
	while (cmds->redirections)
	{
		if (cmds->redirections->token == LESS)
		{
			if (handle_infile(cmds->redirections->str))
				return (EXIT_FAILURE);
		}
		else if (cmds->redirections->token == GREAT
			|| cmds->redirections->token == D_GREAT)
		{
			if (handle_outfile(cmds->redirections))
				return (EXIT_FAILURE);
		}
		else if (cmds->redirections->token == D_LESS)
		{
			if (handle_infile(cmds->hd_file_name))
				return (EXIT_FAILURE);
		}
		cmds->redirections = cmds->redirections->next;
	}
	cmds->redirections = start;
	return (EXIT_SUCCESS);
}
