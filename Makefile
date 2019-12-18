# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aortega- <aortega-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/04 11:35:44 by aortega-          #+#    #+#              #
#    Updated: 2019/12/18 17:02:02 by aortega-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror

SRCS = ft_printf.c flags_utils.c conv_utils.c char_conv.c str_conv.c int_conv.c ft_putstrprint_fd.c pos_conv.c ft_ulltoa_base.c hexa_conv.c percent_conv.c unsign_conv.c ft_utoa.c

OBJS = $(SRCS:.c=.o)

$(NAME) : $(OBJS) 
		cd libft && $(MAKE)
		cp libft/libft.a $(NAME)
		ar -rcs $(NAME) $(OBJS)
f:	
	gcc *.c libft/*.c

all : $(NAME)

clean :
		rm -f $(OBJS)
		$(MAKE) clean -C ./libft
fclean : clean
		rm -f $(NAME)
		rm -f libft.a
		$(MAKE) fclean -C ./libft
re : fclean all

%.o: %.c
	$(CC) $(FLAGS) -I ft_printf.h -c $<  -o $(<:.c=.o)
	