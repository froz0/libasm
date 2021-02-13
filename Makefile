# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmatis <tmatis@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/13 14:30:35 by tmatis            #+#    #+#              #
#    Updated: 2021/02/13 17:54:57 by tmatis           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_ASSERT		= assert.c assert_utils.c
OBJS_ASSERT		= $(addprefix assert/, ${SRCS_ASSERT:.c=.o})

SRCS_MAIN		= main.c
OBJS_MAIN		= ${SRCS_MAIN:.c=.o}

SRCS_ASM		= ft_strlen.s ft_strcpy.s
OBJS_ASM		= ${SRCS_ASM:.s=.o}

NAME			= libasm.a

.c.o:
			@echo Compiling: $<
			@clang -Wall -Wextra -Werror -c $< -o ${<:.c=.o}

.s.o:
			@echo Compiling: $<
			@nasm -felf64 -o $@ $?


$(NAME):	${OBJS_ASM}
			@echo Linking library...
			ar -rcs $@ $^

all:		$(NAME)

test:		all ${OBJS_MAIN} ${OBJS_ASSERT}
			clang -Wall -Wextra -Werror -o test ${OBJS_MAIN} ${OBJS_ASSERT} -L. -lasm


clean:
			@echo Cleaning
			@rm -rf ${OBJS_ASSERT} ${OBJS_MAIN} ${OBJS_ASM}

fclean: 	clean
			rm -rf $(NAME) test

re:	fclean all
