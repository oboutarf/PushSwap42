# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oboutarf <oboutarf@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/20 16:14:30 by oboutarf          #+#    #+#              #
#    Updated: 2022/09/21 14:32:32 by oboutarf         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 			= push_swap

SRCS 			= src/main.c src/stack_tools.c

OPTIONS			= -c -I.

OBJS			= *.o

CC	 			= gcc

RM				= rm -f

CFLAGS			= -Wall -Wextra -Werror

NORM        	= norminette


all: 			$(NAME)

$(NAME):		$(OBJS)
				ar rcs $(NAME) $(OBJS)

$(OBJS): 		$(SRCS)
				$(CC) $(CFLAGS) $(OPTIONS) $(SRCS)

clean:			
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

norm:			$(NORM)