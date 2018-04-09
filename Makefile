# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fherbine <fherbine@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/13 16:28:57 by fherbine          #+#    #+#              #
#    Updated: 2018/04/09 16:11:49 by fherbine         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 21sh
INCLUDES = includes
SRC_PATH = sources
OBJ_PATH = $(SRC_PATH)/debug
SRC_NAME = main.c max_free.c minishell.c cmd_utils.c cmd_list.c \
		   ms_out_errors.c parser.c prmpt.c ftsh_debug.c bi_env.c bi_exit.c \
		   utils.c sh_errors.c more_cmd.c shvar_utils.c bi_echo.c \
		   bi_unsetenv.c bi_setenv.c init_env.c bi_cd.c bi_history.c auxiliary.c
OBJ_NAME = $(SRC_NAME:.c=.o)
SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))
LPATH = libft
LFLAGS = -L$(LPATH) -lft
IFLAGS = -I$(INCLUDES)
CFLAGS = -Wall -Wextra
CC = gcc

all: $(NAME)

$(OBJ_PATH):
	@clear
	@figlet -c -f roman "21sh" | lolcat
	@mkdir $@
	@echo "\t\t\t>>> \033[1mCOMPILING 21-SH\033[0m <<<\n"
	@echo ">>> Making 21sh : \033[0;33;40m[\c"

$(NAME): $(OBJ_PATH) $(OBJ)
	@echo "]\033[0m --> \033[1;32;40m[Done]\033[0m\n"
	@echo ">>> Making Libft : \033[0;33;40m[\c"
	@make -C $(LPATH)
	@echo "\n"
	@$(CC) -o $@ $(OBJ) $(LFLAGS)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@echo "=\c"
	@$(CC) $(CFLAGS) $(IFLAGS) -c $? -o $@

clean:
	@rm -rf $(OBJ_PATH)
	@make -C $(LPATH) fclean

fclean: clean
	@echo "\033[0;31;40mCLEANING ALL"
	@rm -rf $(NAME)
	@echo "Done.\033[0m"

re: fclean all

.PHONY: all clean fclean re
