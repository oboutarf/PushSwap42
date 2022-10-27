# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oboutarf <oboutarf@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/20 16:14:30 by oboutarf          #+#    #+#              #
#    Updated: 2022/10/27 20:03:50 by oboutarf         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 			= push_swap

SRCS 			= src/main.c src/stack_tools1.c					\
				  src/stack_tools2.c src/stack_tools3.c 		\
				  src/algo_count.c src/algo_meca.c 				\
				  src/algo_presort.c src/algo_search.c 			\
				  src/forthree.c src/forfive.c					\
				  cmd/commands_a.c cmd/commands_b.c		 		\

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