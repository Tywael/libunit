# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yalthaus <yalthaus@42lausanne.ch>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/10 17:31:55 by yalthaus          #+#    #+#              #
#    Updated: 2023/02/12 04:01:57 by user42           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libunit.a

SRCS += load_test.c
SRCS += launch_tests.c
SRCS += utils_s_unit_test.c
SRCS += signal.c


SRCS_DIR = src

OBJS = $(SRCS:.c=.o)
OBJS_DIR = obj

DIRS = obj

_SRCS = $(addprefix $(SRCS_DIR)/, $(SRCS))
_OBJS = $(addprefix $(OBJS_DIR)/, $(OBJS))

HEADERS = inc

LIBFT = libft.a
LIBFT_DIR = libft

MAKE = make --no-print-directory
CC = gcc

CFLAGS = -I $(HEADERS) -I $(LIBFT_DIR)/inc -Wall -Wextra -Werror
LFLAGS = $(CFLAGS)

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

$(NAME): $(LIBFT_DIR)/$(LIBFT) $(_OBJS)
	@ar rcs $(NAME) $(_OBJS)
	@echo "$(_OK) $(NAME) \t\tcompiled"

$(OBJS_DIR)/%.o:$(SRCS_DIR)/%.c
	@echo "[..] $(NAME)... compiling $*.c\r\c"
	@mkdir -p $(DIRS)
	@$(CC) -c $(CFLAGS) $< -o $@
	@echo "$(_CLEAR)"

$(LIBFT_DIR)/$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR) all
	@$(MAKE) -C $(LIBFT_DIR) bonus

clean:
	@echo "[..] $(NAME)... removing $*.c\r\c"
	@rm -rf $(OBJS_DIR)
	@echo "$(_CLEAR)"

fclean:
	@rm -rf $(OBJS_DIR) $(NAME)
	@echo "$(_RM) $(NAME) \t\tfull clean"

re: fclean all

.PHONY : all fast debug clean fclean re
