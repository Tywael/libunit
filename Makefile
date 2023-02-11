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

NAME = libunit

SRCS = main.c


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
_CLEAR		= \033[0K
_OK			= [\033[32mOK\033[0m]
_RM			= [\033[31mRM\033[0m]

all: $(NAME)

fast: CFLAGS += -Ofast
fast: $(NAME)

debug: LFLAGS += $(DEBUG_LFLAGS)
debug: CFLAGS += $(DEBUG_CFLAGS)
debug: fclean $(NAME)

color:
	@echo
	@echo use printf
	@echo
	@printf "_COLOR $(_COLOR) COLOR _RESET $(_RESET) NO_COLOR\n"
	@printf "_BOLDCOLOR $(_BOLDCOLOR) _RESET $(_RESET) NO_COLOR\n"
	@printf "_RESET $(_RESET)\n"
	@printf "_CLEAR $(_CLEAR)\n"
	@printf "_OK $(_OK)\n"
	@printf "_RM $(_RM)\n"
	@echo
	@echo use echo
	@echo
	@echo "_COLOR $(_COLOR)"
	@echo "_BOLDCOLOR $(_BOLDCOLOR)"
	@echo "_RESET $(_RESET)"
	@echo "_CLEAR $(_CLEAR)"
	@echo "_OK $(_OK)"
	@echo "_RM $(_RM)"

$(NAME): $(LIBFT_DIR)/$(LIBFT) $(_OBJS)
	@$(CC) $(_OBJS) $(LIBFT_DIR)/$(LIBFT) $(LFLAGS) -o $(NAME)
	@printf "$(_OK) $(NAME) \t\tcompiled\n"

$(OBJS_DIR)/%.o:$(SRCS_DIR)/%.c
	@printf "[..] $(NAME)... compiling $*.c\n"
	@mkdir -p $(DIRS)
	@$(CC) -c $(CFLAGS) $< -o $@

$(LIBFT_DIR)/$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR) all
	@$(MAKE) -C $(LIBFT_DIR) bonus

clean:
	@printf "[..] $(NAME)... removing $*.c\n"
	@rm -rf $(OBJS_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean:
	@rm -rf $(OBJS_DIR) $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@printf "$(_RM) $(NAME) \t\tfull clean\n"

re: fclean all

.PHONY : all fast debug clean fclean re
