# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    libunit                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yalthaus <yalthaus@42lausanne.ch>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/10 17:31:55 by yalthaus          #+#    #+#              #
#    Updated: 2023/02/10 17:36:51 by yalthaus         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = realtest

SRCS = main.c


SRCS_DIR = src

OBJS = $(SRCS:.c=.o)
OBJS_DIR = obj

DIRS = obj

_SRCS = $(addprefix $(SRCS_DIR)/, $(SRCS))
_OBJS = $(addprefix $(OBJS_DIR)/, $(OBJS))

HEADERS = inc

FRAMEWORK = ./../framework

MAKE = make --no-print-directory
CC = gcc

CFLAGS = -I $(HEADERS) -I $(FRAMEWORK)/inc -Wall -Wextra -Werror
LFLAGS = $(CFLAGS) -L $(FRAMEWORK)

DEBUG_CFLAGS = -g3 -fsanitize=address -fno-omit-frame-pointer

UNAME = $(shell uname -s)

# Color
_COLOR		= \033[32m
_BOLDCOLOR	= \033[32;1m
_RESET		= \033[0m
_CLEAR		= \033[0K\r\c
_OK			= [\033[32mOK\033[0m]
_RM			= [\033[31mRM\033[0m]

all: $(NAME)

fast: CFLAGS += -Ofast
fast: $(NAME)

debug: LFLAGS += $(DEBUG_LFLAGS)
debug: CFLAGS += $(DEBUG_CFLAGS)
debug: fclean $(NAME)

$(NAME): framework $(_OBJS)
	@$(CC) $(_OBJS)  $(LFLAGS) -o $(NAME)
	@echo "$(_OK) $(NAME) \t\tcompiled"

$(OBJS_DIR)/%.o:$(SRCS_DIR)/%.c
	@echo "[..] $(NAME)... compiling $*.c\r\c"
	@mkdir -p $(DIRS)
	@$(CC) -c $(CFLAGS) $< -o $@
	@echo "$(_CLEAR)"

framework:
	@$(MAKE) -C $(FRAMEWORK) all

clean:
	@echo "[..] $(NAME)... removing $*.c\r\c"
	@rm -rf $(OBJS_DIR)
	@$(MAKE) -C $(FRAMEWORK) clean
	@echo "$(_CLEAR)"

fclean:
	@rm -rf $(OBJS_DIR) $(NAME)
	@$(MAKE) -C $(FRAMEWORK) fclean
	@echo "$(_RM) $(NAME) \t\tfull clean"

re: fclean all

.PHONY : all fast debug clean fclean re
