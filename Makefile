# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gyasuhir <gyasuhir@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/19 11:50:51 by gyasuhir          #+#    #+#              #
#    Updated: 2024/12/01 13:53:34 by gyasuhir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = get_next_line.c get_next_line_utils.c main.c

VALGRIND_LOG        = valgrind.log

INCLUDES    = -I get_next_line.h

BONUS_SRCS = get_next_line_bonus.c get_next_line_utils_bonus.c

OBJECTS = $(SRCS:%.c=%.o)

BONUS_OBJS = $(BONUS_SRCS:%.c=%.o)

NAME = get_next_line

all: $(NAME)

$(NAME): $(OBJECTS)

%.o: %.c
    @cc -Wall -Wextra -Werror -g -c $< -o $@ $(INCLUDES)
    @ar rcs $(NAME) $@

bonus: all $(BONUS_OBJS)

clean:
    rm -f $(OBJECTS) $(BONUS_OBJS)

fclean: clean
    rm -f $(NAME)

re: fclean all

valgrind:
    @valgrind --leak-check=full \
    --show-reachable=yes \
    --show-leak-kinds=all -s \
    --track-origins=yes \
    --log-file=$(VALGRIND_LOG) \
    ./$(NAME)
    @cat $(VALGRIND_LOG)

.PHONY: all bonus clean fclean re