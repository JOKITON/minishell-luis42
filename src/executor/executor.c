/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alshakhp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 14:11:01 by alshakhp          #+#    #+#             */
/*   Updated: 2025/01/30 14:11:03 by alshakhp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_comands	*call_expander(t_general *general, t_comands *cmds)
{
	t_lexer	*start;

	cmds->str = expander(general, cmds->str);
	start = cmds->redirections;
	while (cmds->redirections)
	{
		if (cmds->redirections->token != D_LESS)
			cmds->redirections->str
				= expander_str(general, cmds->redirections->str);
		cmds->redirections = cmds->redirections->next;
	}
	cmds->redirections = start;
	return (cmds);
}

int	ft_fork(t_general *general, int end[2], int fd_in, t_comands *cmds)
{
	static int	i = 0;

	if (general->reset == true)
	{
		i = 0;
		general->reset = false;
	}
	general->pid[i] = fork();
	if (general->pid[i] < 0)
		ft_error(5, general);
	if (general->pid[i] == 0)
		dup_cmd(cmds, general, end, fd_in);
	i++;
	return (EXIT_SUCCESS);
}

int	pipe_wait(int *pid, int amount)
{
	int	i;
	int	status;

	i = 0;
	while (i < amount)
	{
		waitpid(pid[i], &status, 0);
		i++;
	}
	waitpid(pid[i], &status, 0);
	if (WIFEXITED(status))
		g_global.error_num = WEXITSTATUS(status);
	return (EXIT_SUCCESS);
}

int	check_fd_heredoc(t_general *general, int end[2], t_comands *cmds)
{
	int	fd_in;

	if (general->heredoc)
	{
		close(end[0]);
		fd_in = open(cmds->hd_file_name, O_RDONLY);
	}
	else
		fd_in = end[0];
	return (fd_in);
}


int	executor(t_general *general)
{
	int		end[2];
	int		fd_in;

	fd_in = STDIN_FILENO;
	while (general->cmds)
	{
		general->cmds = call_expander(general, general->cmds);
		if (general->cmds->next)
			pipe(end);
		send_heredoc(general, general->cmds);
		ft_fork(general, end, fd_in, general->cmds);
		close(end[1]);
		if (general->cmds->prev)
			close(fd_in);
		fd_in = check_fd_heredoc(general, end, general->cmds);
		if (general->cmds->next)
			general->cmds = general->cmds->next;
		else
			break ;
	}
	pipe_wait(general->pid, general->pipes);
	general->cmds = ft_simple_cmdsfirst(general->cmds);
	return (0);
}

int	prepare_executor(t_general *general)
{
	signal(SIGQUIT, SIG_IGN);
	g_global.in_cmd = 1;
	if (general->pipes == 0)
		single_cmd(general->cmds, general);
	else
	{
		general->pid = ft_calloc(sizeof(int), general->pipes + 2);
		if (!general->pid)
			return (ft_error(1, general));
		executor(general);
	}
	g_global.in_cmd = 0;
	return (EXIT_SUCCESS);
}
