/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_config.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alshakhp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 12:01:25 by alshakhp          #+#    #+#             */
/*   Updated: 2025/02/17 12:01:27 by alshakhp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_global g_global;

int setstart_conf(t_general *general)
{  
    general->pid = NULL;
    general->cmds = NULL;
    general->lexer_list = NULL;  //No entiendo, revisar.
    general->heredoc = false;
    general->reset = false;
    g_global.stop_heredoc = 0;
    g_global.in_cmd = 0;
    g_global.error_num = 0;
    g_global.in_heredoc = 0;
    env_pars(general);
    init_signals();
    return(1);
}

int reset_comands (t_general *general)
{
    comands_clear(&general->cmds);
    free(general->args);
    if(general->pid)
    {
        free(general->pid);
    }
    free_array(general->paths);
    setstart_conf(general);
    general->reset = true;
    loop(general);
    return (1);
}

int loop(t_general *general)
{
    char *space;

    general->args = readline(READLINE_MSG);
    space = ft_strtrim(general->args, " ");
    free(general->args);
    general->args = space;
    
    if(!general->args)
    {
        ft_putendl_fd("Exit", STDOUT_FILENO);
        exit(EXIT_SUCCESS);
    }
    if(general->args[0] == '\0')
        return(reset_comands(general));
    add_history(general->args);
    if(!quote_count(general->args))
    {
        return(ft_error(2, general));
    }
    if(!token_reader(general))
    {
        printf("token == 0");
        return(ft_error(1, general));
    }
    parser(general);
    prepare_executor(general);
    reset_comands(general);
    return (1);
}
