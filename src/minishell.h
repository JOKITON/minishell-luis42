/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alshakhp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 13:11:47 by alshakhp          #+#    #+#             */
/*   Updated: 2025/01/30 13:11:49 by alshakhp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <sys/types.h>
# include <stdlib.h>
# include <stddef.h>
# include <sys/wait.h>
# include <unistd.h>
# include <stdbool.h>
# include "../libft/libft.h"
# include <readline/readline.h>
# include <readline/history.h>
# include <fcntl.h>
# include <signal.h>

# define READLINE_MSG	"\033[1;36mminishell\033[34m$ \033[0m"

typedef enum s_tokens
{
	PIPE = 1,
	GREAT,
	D_GREAT,
	LESS,
	D_LESS,
}	t_tokens;

typedef struct s_lexer
{
	char			*str;
	t_tokens		token;
	int				i;
	struct s_lexer	*next;
	struct s_lexer	*prev;
}	t_lexer;

typedef struct s_general
{
	char					*args;
	char					**paths;
	char					**envp;
	struct s_comands		*cmds;
	t_lexer					*lexer_list;
	t_lexer			*redirections;
	int				num_redirections;
	char					*pwd;
	char					*oldpwd;
	int						pipes;
	int						*pid;
	bool					heredoc;
	bool					reset;
}		t_general;

typedef struct s_comands
{
	char					**str;
	int						(*builtin)(t_general *, struct s_comands *);
	int						num_redirections;
	char					*hd_file_name;
	t_lexer					*redirections;
	struct s_comands	*next;
	struct s_comands	*prev;
}	t_comands;

typedef struct s_global
{
	int	error_num;
	int	stop_heredoc;
	int	in_cmd;
	int	in_heredoc;
}	t_global;


extern t_global	g_global;

int main(int argc, char **argv, char **envp);

int	add_node(char *str, t_tokens token, t_lexer **lexer_list);
t_lexer	*ft_lexernew(char *str, int token);
void	ft_lexeradd_back(t_lexer **lst, t_lexer *new);
t_tokens	check_token(int c);
int	handle_quotes(int i, char *str, char del);
int	handle_token(char *str, int i, t_lexer **lexer_list);
void	ft_lexerdelone(t_lexer **lst, int key);
void	parser_error(int error, t_general *general, t_lexer *lexer_list);
int	parser_double_token_error(t_general *general, t_lexer *lexer_list,
	t_tokens token);
int	mini_cd(t_general *general, t_comands *cmds);
int	mini_echo(t_general *general, t_comands *cmds);
int	mini_env(t_general *general, t_comands *cmds);
int	mini_exit(t_general *general, t_comands *cmds);
int	mini_export(t_general *general, t_comands *cmds);
int	mini_pwd(t_general *general, t_comands *cmds);
int	mini_unset(t_general *general, t_comands *cmds);
void	change_path(t_general *general);
t_comands	*ft_simple_cmdsfirst(t_comands *map);
void	ft_simple_cmdsclear(t_comands **lst);
size_t	equal_sign(char *str);
char	*delete_quotes_value(char *str);
char	*delete_quotes(char *str, char c);
int	export_error(char *c);
int	check_valid_identifier(char c);
int	prepare_executor(t_general *general);
int	parser(t_general *general);
void	count_pipes(t_lexer *lexer_list, t_general *general);
t_general	init_parser_tools(t_lexer *lexer_list, t_general *general);
void	rm_redirections(t_general *general);
int	count_args(t_lexer *lexer_list);
t_comands	*ft_simple_cmdsnew(char **str,
int num_redirections, t_lexer *redirections);
void	ft_simple_cmdsadd_back(t_comands **lst, t_comands *new);
int	ft_error(int error, t_general *general);
int	(*builtin_arr(char *str))(t_general *general, t_comands *cmds);
void	ft_lexerclear(t_lexer **lst);
void	single_cmd(t_comands *cmds, t_general *general);
char	**expander(t_general *general, char **str);
char	*expander_str(t_general *general, char *str);
void	dup_cmd(t_comands *cmds, t_general *general, int end[2], int fd_in);
int	send_heredoc(t_general *general, t_comands *cmds);
char	**resplit_str(char **double_arr);
char	*join_split_str(char **split_str, char *new_str);
int	cmd_not_found(char *str);
int	check_redirections(t_comands *cmds);
t_comands	*call_expander(t_general *general, t_comands *cmds);
int	question_mark(char **tmp);
int	after_dol_lenght(char *str, int j);
char	*char_to_str(char c);
size_t	dollar_sign(char *str);
char	*join_heredoc(char *str1, char *str2);
int	check_redirections(t_comands *cmds);
void	handle_cmd(t_comands *cmds, t_general *general);
int	count_quotes(char *line);
int	token_reader(t_general *general);
int token_manage(char *s, t_lexer **list, int j);
int words_reader(int i, char *s, t_lexer **list);
t_tokens is_token(int c);
int space(char x);
int node_sum_empty(char *s, t_tokens tok, t_lexer **list);
int quote_count(char *line);

char **ft_dupl_array(char **array);

void free_array(char **split_array);

int look_pwd(t_general *general);

int setstart_conf(t_general *general);

int env_pars(t_general *general);

char *check_path(char **env);

void init_signals(void);

int event(void);

void handler_sigint(int sig);

void clear_lexer(t_lexer **last);

void comands_clear(t_comands **last);

int reset_comands (t_general *general);

int loop(t_general *general);

char	**quotes_tokenizer(char *input);

char	**quotes_tokenizer_aux(char **tokens, char	*s, int start, int tok);

int	count_tokens(char *s, int i, int tokens);

#endif
