# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: timschmi <timschmi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/11 13:00:34 by timschmi          #+#    #+#              #
#    Updated: 2024/03/18 16:53:17 by timschmi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_printf.c ft_putnbr.c ft_putstr.c ft_countarg.c ft_checkset.c ft_putchar.c

OFILES = $(SRCS:.c=.o)

CC = cc

# CFLAGS = -Wall -Wextra -Werror
LDFLAGS= -L./libft -lft -L. -lftprintf

NAME = libftprintf.a

all: $(NAME)

$(NAME): $(OFILES)
	ar rcs $(NAME) $(OFILES)
	make clean

%: %.c
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

clean:
	rm -f $(OFILES)
	rm -f $(SRCS:.c=)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY:  all clean fclean re