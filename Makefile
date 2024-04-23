# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fgomes-f <fgomes-f@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/03 14:07:02 by fgomes-f          #+#    #+#              #
#    Updated: 2023/11/03 14:14:09 by fgomes-f         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC = calculate_cost.c good_input.c index_target_and_position.c main.c moving.c p_functions.c push_swap.c r_functions.c rr_functions.c s_functions.c stack_utils.c

OBJS = ${SRC:.c=.o}

CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror
INCLUDE = -I libftplus

all: ${NAME}

${NAME}: ${OBJS}
		make -C ./libftplus
		${CC} ${CFLAGS} ${OBJS} -L ./libftplus -lft -o ${NAME} ${INCLUDE}
		
%.o : %.c
		${CC} ${CFLAGS} ${INCLUDE} -c $< -o ${<:.c=.o}

clean:
		make -C libftplus clean
		${RM} ${OBJS}

fclean: clean
		make -C libftplus fclean
		${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
