/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alshakhp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 12:49:42 by alshakhp          #+#    #+#             */
/*   Updated: 2025/01/30 12:50:59 by alshakhp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int main(int argc, char **argv, char **env)
{
    t_general general;

    if(argc != 1 || argv[1])
    {
        printf("Program does not allow any arguments\n");
        exit(0);
    }
    general.envp = ft_dupl_array(env);
    look_pwd(&general);
    setstart_conf(&general);
    printf("\n%s\n\n", "WELCOME");
    loop(&general);
    return(0);
}
