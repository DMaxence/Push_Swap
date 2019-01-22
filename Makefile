# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maduhoux <maduhoux@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/10 11:58:15 by maduhoux          #+#    #+#              #
#    Updated: 2018/06/25 13:27:55 by maduhoux         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS	=	-Wall -Wextra -Werror
NAME	=	push_swap
NAME2	=	checker
SRCDIR	=	src/
OBJDIR1	=	objPush_swap/
OBJDIR2	=	objChecker/
FILES1	=	push_swap.c \
			checker_order.c \
			s.c \
			p.c \
			r.c \
			rr.c \
			init_and_verif.c \
			list_info.c \
			list_manage.c \
			mediane.c \
			small_sort.c \
			sort.c \
			insert_sort.c \
			print_lst.c \
			free.c
FILES2	=	checker.c \
			checker_order.c \
			list_info.c \
			list_manage.c \
			s.c \
			p.c \
			r.c \
			rr.c \
			init_and_verif.c \
			get_next_line.c \
			checker_lst.c \
			print_lst.c \
			free.c
INCLUDE	=	includes/
# SRC1	=	$(FILES1:%.c=$(SRCDIR)%.c)
OBJ1	=	$(FILES1:%.c=$(OBJDIR1)%.o)
# SRC2	=	$(FILES2:%.c=$(SRCDIR)%.c)
OBJ2	=	$(FILES2:%.c=$(OBJDIR2)%.o)

VPATH	= 	$(shell find $(SRCDIR) -type d)

.PHONY: all clean fclean re

all: init $(NAME) $(NAME2)

init:
	@echo "\033[0;32m          $(NAME)\033[0m"

$(NAME): $(OBJ1) needed
	@echo "\033[4;33mCompiling\033[0;33m $(NAME)\033[0m"
	@gcc $(OBJ1) -o $(NAME) -Llibft -lft ft_printf/libftprintf.a
	@echo "\033[4;32mCompiled\033[0;33m $(NAME)\033[0m"

$(NAME2): $(OBJ2) needed
	@echo "\033[4;33mCompiling\033[0;33m $(NAME2)\033[0m"
	@gcc $(OBJ2) -o $(NAME2) -Llibft -lft ft_printf/libftprintf.a
	@echo "\033[4;32mCompiled\033[0;33m $(NAME2)\033[0m"

$(OBJDIR1)%.o: $(SRCDIR)%.c
	@mkdir -p $(OBJDIR1)
	@gcc -o $@ -c $< $(CFLAGS) -I $(INCLUDE)

$(OBJDIR2)%.o: $(SRCDIR)%.c
	@mkdir -p $(OBJDIR2)
	@gcc -o $@ -c $< $(CFLAGS) -I $(INCLUDE)

needed:
	@echo "\033[4;33mCompiling\033[0;33m Libft\033[0m"
	@make -C libft/
	@echo "\033[4;32mCompiled\033[0;33m Libft\033[0m"
	@echo "\033[4;33mCompiling\033[0;33m ft_printf\033[0m"
	@make -C ft_printf/
	@echo "\033[4;32mCompiled\033[0;33m ft_printf\033[0m"

clean:
	@make clean -C libft/
	@echo "\033[4;32mDeleted\033[0;33m libft/obj\033[0m"
	@make clean -C ft_printf/
	@echo "\033[4;32mDeleted\033[0;33m ft_printf/obj\033[0m"
	@rm -rf $(OBJDIR1)
	@rm -rf $(OBJDIR2)
	@echo "\033[4;32mDeleted\033[0;33m $(OBJDIR1)\033[0m"
	@echo "\033[4;32mDeleted\033[0;33m $(OBJDIR2)\033[0m"

fclean: clean
	@make fclean -C libft/
	@echo "\033[4;32mDeleted\033[0;33m libft/libft.a\033[0m"
	@make fclean -C ft_printf/
	@echo "\033[4;32mDeleted\033[0;33m ft_printf/libftprintf.a\033[0m"
	@rm -rf $(NAME)
	@rm -rf $(NAME2)
	@echo "\033[4;32mDeleted\033[0;33m $(NAME)\033[0m"
	@echo "\033[4;32mDeleted\033[0;33m $(NAME2)\033[0m"

re:
	$(MAKE) fclean
	$(MAKE)
