NAME = minishell

CC = gcc

CFLAGS	= -Wall -Werror -Wextra -g

HEADER = src/minishell.h

SRCS =		src/main.c \
		src/lexer_funct/lexer_funct.c \
		src/lexer_funct/lexer_funct1.c \
		src/lexer_funct/lexer_funct2.c \
		src/lexer_funct/lexer_utils.c \
		src/lexer_funct/lexer_utils1.c \
		src/parser/redirections.c \
		src/parser/parser.c \
		src/parser/parser_utils.c \
		src/builtins/builtins.c \
		src/builtins/mini_cd.c \
		src/builtins/mini_echo.c \
		src/builtins/mini_env.c \
		src/builtins/mini_exit.c \
		src/builtins/mini_export.c \
		src/builtins/mini_pwd.c \
		src/builtins/mini_unset.c \
		src/builtins/utils_builtins.c \
		src/utils_used/basic_config.c \
		src/utils_used/signals.c \
		src/utils_used/frees.c \
		src/utils_used/utils.c \
		src/utils_used/count_quotes.c \
		src/errors/error.c \
		src/errors/ft_error.c \
		src/executor/executor.c \
		src/executor/handle_cmd.c \
		src/executor/check_redir.c \
		src/executor/heredoc.c \
		src/executor/executor_utils.c \
		src/expander/expander.c \
		src/expander/expander_utils.c \
		src/expander/expander_utils2.c

OBJS = $(SRCS:.c=.o)

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME) -lreadline

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

clean:
	rm -rf $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
		rm -rf $(NAME)
		$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all
