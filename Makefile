# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ozasahin <ozasahin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/13 16:43:33 by ozasahin          #+#    #+#              #
#    Updated: 2024/02/13 17:15:39 by ozasahin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a

SRCS	=	\
			err/ft_norm_err.c\
			err/ft_print_err.c\
			\
			file/ft_putchar_fd.c\
			file/ft_putendl_fd.c\
			file/ft_putnbr_fd.c\
			file/ft_putstr_fd.c\
			\
			free/ft_free2d.c\
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

# Controls
CC		=	gcc
CFLAGS  =	-Wall -Wextra -Werror
RM  	=	rm -f

OBJS	=	$(addprefix obj/,$(SRCS:.c=.o))

all:	${NAME}

${NAME}:	${OBJS}
			@ar rc ${NAME} ${OBJS}

obj/%.o: src/%.c | obj
		@mkdir -p $(@D)
		@$(CC) $(CFLAGS) -c $< -o $@

obj:
		@mkdir -p obj

clean:
		@${RM} -r obj

fclean:	clean
		@${RM} ${NAME}

re:		fclean all

.PHONY:	all clean fclean re
