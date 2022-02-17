NAME = minishell

USER_N = ${USER}

SRCS = $(wildcard srcs/*c) $(wildcard srcs/parser/*.c) $(wildcard srcs/execute_part/*.c) $(wildcard srcs/commands/*.c)

OBJS = $(patsubst %.c,%.o,$(SRCS))

HEADER = include/minishell.h
LIB = libft/libft.a

INC_DIR = include
LIB_DIR = libft

CC = gcc
CFLAGS = -Wall -Werror -Wextra
RM = rm -rf

all: brew libft $(NAME)

$(NAME): message $(OBJS) $(HEADER)
	@$(CC) $(CFLAGS) $(OBJS) $(LIB) -lreadline -L /Users/$(USER_N)/.brew/opt/readline/lib -I /Users/$(USER_N)/.brew/opt/readline/include -o $(NAME)
	@echo '√'
	@echo Minishell was created!

%.o: %.c $(HEADER)
	@echo -n '#'
	@$(CC) $(CFLAGS) -c $< -o $@

libft:
	@$(MAKE) -s -C $(LIB_DIR)

clean:
	@$(MAKE) clean -s -C $(LIB_DIR)
	@echo Objectives deleted
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(LIB) $(NAME)
	@echo 'Minishell deleted('

brewfclean: fclean
	rm -rf ~/.brew

re: fclean all

message:
	@echo -n 'Create minishell '

brew:
	@if ! [ -d ~/.brew ]; then\
		curl -fsSL https://rawgit.com/kube/42homebrew/master/install.sh | zsh;\
		brew update;\
		brew install readline;\
	fi

.PHONY: all clean fclean re libft message brew brewfclean
