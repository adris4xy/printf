/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aortega- <aortega-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 16:09:20 by aortega-          #+#    #+#             */
/*   Updated: 2019/12/17 14:58:35 by aortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_parser_conv(char input, t_flags flags, va_list args)
{
	int		rtn;
	int		nb;

	rtn = 0;
	nb = 0;
	if (input == 'c')
		rtn = ft_char_conv(flags, args);
	else if (input == 's')
		rtn = ft_str_conv(flags, args);
	else if (input == 'p')
		rtn = ft_pos_conv(flags, args);
	else if (input == 'd' || input == 'i')
		rtn = ft_int_conv(flags, args);
	else if (input == 'u')
		rtn = ft_unsign_conv(flags, args);
	else if (input == 'x')
		rtn = ft_hexa_conv(flags, args, "0123456789abcdef");
	else if (input == 'X')
		rtn = ft_hexa_conv(flags, args, "0123456789ABCDEF");
	else if (input == '%')
		rtn = ft_percent_conv(flags);
	return (rtn);
}

int		ft_adjust(int width, char c)
{
	int i;

	i = 0;
	while (i < width)
	{
		ft_putchar_fd(c, 1);
		i++;
	}
	return (i);
}
