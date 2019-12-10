# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aortega- <aortega-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/04 11:35:44 by aortega-          #+#    #+#              #
#    Updated: 2019/12/09 14:05:36 by aortega-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror -c

SRCS =	ft_printf.c ft_specialputchar.c ft_putstrcount.c ft_checktype.c ft_putnumber.c ft_hexap.c ft_ulltoabase.c ft_puthexastr.c ft_itoa_base.c ft_hexax.c	ft_hexaxbig.c ft_putcharcount.c ft_unsignedcount.c ft_utoa.c ft_percentcount.c main.c

OBJS = $(SRCS:.c=.o)

$(NAME) : $(OBJS)
		$(MAKE) -C ./libft
		$(CC) $(SRCS) ft_printf.h $(FLAGS)
		ar r printf.a $(OBJS)
		libtool -static -o $(NAME) ./libft/libft.a printf.a
		rm -f printf.a
f:	
	gcc *.c libft/*.c

all : $(NAME)

clean :
		rm -f $(OBJS)
		$(MAKE) clean -C ./Libft
fclean : clean
		rm -f $(NAME)
		$(MAKE) fclean -C ./Libft
re : fclean all