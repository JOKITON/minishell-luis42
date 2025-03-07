/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alshakhp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 12:02:52 by alshakhp          #+#    #+#             */
/*   Updated: 2025/02/17 12:02:54 by alshakhp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void handler_sigint(int sig)
{
    if(!g_global.in_heredoc)
    {
        ft_putstr_fd("\n", STDERR_FILENO);
    }
    if(g_global.in_cmd)
    {
        g_global.stop_heredoc = 1;
        rl_replace_line(" ", 0);
        rl_redisplay();
        rl_done = 1;
        return ;
    }
    rl_on_new_line();
    rl_replace_line(" ", 0);
    rl_redisplay();
    (void) sig;
}


int event(void)
{
    return(EXIT_SUCCESS);
}
    
void init_signals(void)
{
    rl_event_hook = event;
    signal(SIGINT, handler_sigint);
    signal(SIGQUIT, SIG_IGN);
}
