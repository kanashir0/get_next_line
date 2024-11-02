# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gyasuhir <gyasuhir@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/19 11:50:51 by gyasuhir          #+#    #+#              #
#    Updated: 2024/11/02 13:30:25 by gyasuhir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = get_next_line.c get_next_line_utils.c

BONUS_SRCS = get_next_line_bonus.c get_next_line_utils_bonus.c

OBJECTS = $(SRCS:%.c=%.o)

BONUS_OBJS = $(BONUS_SRCS:%.c=%.o)

NAME = run.exe

all: $(NAME)

$(NAME): $(OBJECTS)

%.o: %.c
	@cc -Wall -Wextra -Werror -c $< $(NAME:%.a=%.h)
	@ar rcs $(NAME) $@

bonus: all $(BONUS_OBJS)

clean:
	rm -f $(OBJECTS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
