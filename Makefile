# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aortega- <aortega-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/04 11:35:44 by aortega-          #+#    #+#              #
#    Updated: 2019/12/17 16:03:15 by aortega-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror -c

SRCS = ft_printf.c flags_utils.c conv_utils.c char_conv.c str_conv.c int_conv.c ft_putstrprint_fd.c pos_conv.c ft_ulltoa_base.c hexa_conv.c percent_conv.c unsign_conv.c ft_utoa.c

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