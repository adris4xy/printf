/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aortega- <aortega-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 12:50:13 by aortega-          #+#    #+#             */
/*   Updated: 2019/12/17 15:29:49 by aortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_special_putchar(char c)
{
	int rtn;

	rtn = 0;
	if (c != '%')
	{
		write(1, &c, 1);
		rtn++;
	}
	return (rtn);
}

int		ft_printf(const char *input, ...)
{
	va_list args;
	t_flags flags;
	int		rtn;
	int		i;

	i = 0;
	rtn = 0;
	va_start(args, input);
	while (input[i])
	{
		rtn += ft_special_putchar(input[i]);
		if (input[i] == '%' && input[i + 1])
		{
			i++;
			flags = ft_init_flags(flags);
			flags = ft_parser_flags(&input[i], flags, args);
			while (ft_is_flag(input[i]))
				i++;
			rtn += ft_parser_conv(input[i], flags, args);
		}
		i++;
	}
	va_end(args);
	return (rtn);
}
