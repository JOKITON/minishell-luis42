/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alshakhp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 14:09:05 by alshakhp          #+#    #+#             */
/*   Updated: 2025/01/30 14:09:07 by alshakhp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	find_cmd(t_comands *cmds, t_general *general)
{
	int		i;
	char	*mycmd;

	i = 0;
	cmds->str = resplit_str(cmds->str);
	if (!access(cmds->str[0], F_OK))
		execve(cmds->str[0], cmds->str, general->envp);
	while (general->paths[i])
	{
		mycmd = ft_strjoin(general->paths[i], cmds->str[0]);
		if (!access(mycmd, F_OK))
			execve(mycmd, cmds->str, general->envp);
		free(mycmd);
		i++;
	}
	return (cmd_not_found(cmds->str[0]));
}

void	handle_cmd(t_comands *cmds, t_general *general)
{
	int	exit_code;

	exit_code = 0;
	if (cmds->redirections)
		if (check_redirections(cmds))
			exit(1);
	if (cmds->builtin != NULL)
	{
		exit_code = cmds->builtin(general, cmds);
		exit(exit_code);
	}
	else if (cmds->str[0][0] != '\0')
		exit_code = find_cmd(cmds, general);
	exit(exit_code);
}

void	dup_cmd(t_comands *cmds, t_general *general, int end[2], int fd_in)
{
	if (cmds->prev && dup2(fd_in, STDIN_FILENO) < 0)
		ft_error(4, general);
	close(end[0]);
	if (cmds->next && dup2(end[1], STDOUT_FILENO) < 0)
		ft_error(4, general);
	close(end[1]);
	if (cmds->prev)
		close(fd_in);
	handle_cmd(cmds, general);
}

void	single_cmd(t_comands *cmds, t_general *general)
{
	int	pid;
	int	status;

	general->cmds = call_expander(general, general->cmds);
	if (cmds->builtin == mini_cd || cmds->builtin == mini_exit
		|| cmds->builtin == mini_export || cmds->builtin == mini_unset)
	{
		g_global.error_num = cmds->builtin(general, cmds);
		return ;
	}
	send_heredoc(general, cmds);
	pid = fork();
	if (pid < 0)
		ft_error(5, general);
	if (pid == 0)
		handle_cmd(cmds, general);
	waitpid(pid, &status, 0);
	if (WIFEXITED(status))
		g_global.error_num = WEXITSTATUS(status);
}
