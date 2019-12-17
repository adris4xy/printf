/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_conv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aortega- <aortega-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 16:21:11 by aortega-          #+#    #+#             */
/*   Updated: 2019/12/17 15:05:22 by aortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_char_conv(t_flags flags, va_list args)
{
	if (flags.minus && flags.width > 1)
	{
		ft_putchar_fd(va_arg(args, int), 1);
		ft_adjust(flags.width - 1, ' ');
		return (flags.width);
	}
	else if (!flags.minus && flags.width > 1)
		ft_adjust(flags.width - 1, ' ');
	ft_putchar_fd(va_arg(args, int), 1);
	if (flags.width > 1)
		return (flags.width);
	return (1);
}
