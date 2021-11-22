# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: avan-bre <avan-bre@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/25 15:53:32 by avan-bre          #+#    #+#              #
#    Updated: 2021/11/09 16:11:50 by avan-bre         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
#                                 EXECUTABLES                                  #
################################################################################

OS		=	$(shell uname -s)
NAME	=	push_swap
LIBFT	=	libft/libft.a

################################################################################
#                                 COMMANDS                                     #
################################################################################

RM		=	@rm -rf

ifeq ($(OS), Linux)
	CC		=	@clang
else
	CC		=	@gcc
endif

################################################################################
#                                 FLAGS                                        #
################################################################################

CFLAGS	:=	-Wall -Werror -Wextra
LFLAGS	:=	-Llibft -lft

################################################################################
#                                 FILES                                        #
################################################################################

INC		=	
SRCS	=	push_swap.c \
			parser/init_list.c parser/parse_utils.c parser/parser.c \
			parser/pre_sort.c parser/list_utils.c \
			operations/exec_operations.c operations/operations.c \
			algorithms/algo_mini.c algorithms/sort_list.c \
			algorithms/algo_maxi.c algorithms/algo_utils.c
S_DIR	=	sources/
OBJS	=	$(addprefix $(S_DIR), $(SRCS:.c=.o))

################################################################################
#                                 RULES                                        #
################################################################################

all:		$(NAME)

$(NAME):	$(OBJS) $(LIBFT)
	@echo "Compiling sources.."
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(LFLAGS) 
	@echo "Ready!"

$(sources)/%.o: $(sources)/%.c
	@(CC) $(CFLAGS) -I include -c $< -o $@

$(LIBFT):
	@echo "Compiling libft.."
	@make -s -C libft
	@echo "Libft ready!"

clean:
	$(RM) $(OBJS)
	@make $@ -s -C libft
	@echo "Removed objects"

fclean:		clean
	$(RM) $(NAME)
	@make $@ -s -C libft
	@echo "Removed executable files"

re:			clean all

.PHONY:		re, all, clean, fclean