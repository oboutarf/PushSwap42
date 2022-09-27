# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oboutarf <oboutarf@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/20 16:14:30 by oboutarf          #+#    #+#              #
#    Updated: 2022/09/27 12:17:38 by oboutarf         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 			= push_swap

SRCS 			= src/main.c src/stack_tools1.c src/commands.c \
				src/stack_tools2.c src/stack_tools3.c 		\
				src/algo.c 								\

OPTIONS			= -c -I.

OBJS			= *.o

CC	 			= gcc

RM				= rm -f

CFLAGS			= -Wall -Wextra -Werror

NORM        	= norminette *.c


all: 			$(NAME)

$(NAME):		$(OBJS)
				$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

$(OBJS): 		$(SRCS)
				$(CC) $(CFLAGS) -g3 $(OPTIONS) $(SRCS)

clean:			
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

norm:			$(NORM)