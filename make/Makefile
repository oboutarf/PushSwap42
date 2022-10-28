# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oboutarf <oboutarf@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/20 16:14:30 by oboutarf          #+#    #+#              #
#    Updated: 2022/10/28 19:13:14 by oboutarf         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 			= push_swap

SRCS 			= ../cmd/*.c ../algo_tools/*.c ../tools/*.c ../main/main.c

OPTIONS			= -c -I.

OBJS			= *.o

CC	 			= gcc

RM				= rm -f

CFLAGS			= -Wall -Wextra -Werror

NORM        	= norminette *.c

BI_PURPLE		= '\033[1;95m'

BI_CYAN			= '\033[1;96m'

NC				= '\033[0m'


all: 			$(NAME)

$(NAME):		$(OBJS)
				$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

$(OBJS): 		$(SRCS)
				echo "$(BI_PURPLE)COMPILING....$(NC)\n"
				$(CC) $(CFLAGS) -g3 $(OPTIONS) $(SRCS)
				echo "$(BI_CYAN)DONE COMPILING!$(NC)\n\n$(BI_PURPLE)ENJOY!$(NC)\n"

clean:
				echo "$(BI_PURPLE)REMOVING OBJECTS....$(NC)\n"
				$(RM) $(OBJS)
				echo "$(BI_CYAN)OBJECTS REMOVED!$(NC)\n"

fclean:			clean
				echo "$(BI_PURPLE)REMOVINGS OBJECTS && NAME....$(NC)\n"
				$(RM) $(NAME)
				echo "$(BI_CYAN)OBJECTS && NAME REMOVED!$(NC)\n"

re:				fclean $(NAME)

norm:			$(NORM)
