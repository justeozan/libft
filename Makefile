# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ozasahin <ozasahin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/13 16:43:33 by ozasahin          #+#    #+#              #
#    Updated: 2024/05/16 13:53:08 by ozasahin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a

SRCS	=	\
			2d/dup_2d.c\
			2d/free_2d.c\
			2d/free_matrix.c\
			2d/len_2d.c\
			2d/putstr_2d.c\
			\
			err/ft_print_err.c\
			\
			file/ft_putchar_fd.c\
			file/ft_putendl_fd.c\
			file/ft_putnbr_fd.c\
			file/ft_putstr_fd.c\
			\
			gc/gc_add.c\
			gc/gc_calloc.c\
			gc/gc_clear.c\
			gc/gc_del_one.c\
			gc/gc_itoa.c\
			gc/gc_lstmap.c\
			gc/gc_lstnew.c\
			gc/gc_malloc.c\
			gc/gc_split.c\
			gc/gc_strcut.c\
			gc/gc_strdup.c\
			gc/gc_strjoin.c\
			gc/gc_strmapi.c\
			gc/gc_strndup.c\
			gc/gc_strtrim.c\
			gc/gc_substr.c\
			\
			gnl/get_next_line_utils.c\
			gnl/get_next_line.c\
			\
			is/ft_isalnum.c\
			is/ft_isalpha.c\
			is/ft_isascii.c\
			is/ft_isdigit.c\
			is/ft_isprint.c\
			\
			lst/ft_lstadd_back.c\
			lst/ft_lstadd_front.c\
			lst/ft_lstclear.c\
			lst/ft_lstdelone.c\
			lst/ft_lstiter.c\
			lst/ft_lstlast.c\
			lst/ft_lstmap.c\
			lst/ft_lstnew.c\
			lst/ft_lstsize.c\
			\
			mem/ft_memset.c\
			mem/ft_bzero.c\
			mem/ft_calloc.c\
			mem/ft_memchr.c\
			mem/ft_memcmp.c\
			mem/ft_memcpy.c\
			mem/ft_memmove.c\
			\
			nbr/ft_atoi.c\
			nbr/ft_itoa.c\
			\
			printf/ft_printf.c\
			printf/ft_printf_utils.c\
			\
			str/ft_split.c\
			str/ft_strrchr.c\
			str/ft_strdup.c\
			str/ft_striteri.c\
			str/ft_strjoin.c\
			str/ft_strlcat.c\
			str/ft_strlcpy.c\
			str/ft_strlen.c\
			str/ft_strmapi.c\
			str/ft_strncmp.c\
			str/ft_strnstr.c\
			str/ft_strrchr.c\
			str/ft_strtrim.c\
			str/ft_substr.c\
			str/ft_tolower.c\
			str/ft_toupper.c\
			\

SRCS_DIR	=	$(addprefix src/, $(SRCS))
OBJS		=	$(addprefix obj/, $(SRCS:.c=.o))

# Controls
CC			=	cc -g3
CFLAGS		=	-Wall -Wextra -Werror
INCLUDES	=	-Iinclude -Ilibft
LINKS		=	-Llibft -lft -L/usr/lib
RM			=	rm -rf

# Colors
COLOR_RESET			=	\033[0m
COLOR_RED			=	\033[0;31m
COLOR_GREEN			=	\033[0;32m
COLOR_PURPLE		=	\033[0;95m
COLOR_BLUE			=	\033[0;34m

# Messages
CLEAR_MESSAGE		=	\033[0K\r\c
MESSAGE_OK			=	[\033[32mOK\033[0m]
MESSAGE_COMPILE		=	$(COLOR_BLUE)Compiling :$(COLOR_RESET)
MESSAGE_DONE		=	$(MESSAGE_OK) libft compiled.
MESSAGE_CLEAN		=	$(COLOR_PURPLE)Cleaning up...$(COLOR_RESET)
MESSAGE_CLEAN_DONE	=	$(COLOR_PURPLE)Cleanup completed.$(COLOR_RESET)

all:		${NAME}

${NAME}:	${OBJS}
	@ar rc ${NAME} ${OBJS}
	@echo "$(MESSAGE_DONE)"

# i can add "| obj"
obj/%.o:	src/%.c
	@echo "[...] libft... $(MESSAGE_COMPILE) $*.c\r\c"
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(CLEAR_MESSAGE)"

# obj:
# 	@mkdir -p obj

clean:
	@echo "$(MESSAGE_CLEAN)\c"
	@${RM} obj
	@echo "$(MESSAGE_CLEAN_DONE)"

fclean:		clean
	@${RM} ${NAME}

re:			fclean all

norm :
	norminette | grep -v OK

.PHONY:	all clean fclean re
