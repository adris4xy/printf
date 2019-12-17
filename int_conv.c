/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_conv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aortega- <aortega-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 15:15:22 by aortega-          #+#    #+#             */
/*   Updated: 2019/12/17 15:03:46 by aortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_int_adjust(t_flags flags, int len, int nb)
{
	int	rtn;

	rtn = 0;
	if (flags.zero)
	{
		if (nb < 0)
		{
			write(1, "-", 1);
			rtn++;
		}
		rtn += ft_adjust(flags.width - len, '0');
	}
	else if (flags.precision >= len)
	{
		if (nb < 0)
			rtn += ft_adjust(flags.width - flags.precision - 1, ' ');
		else
			rtn += ft_adjust(flags.width - flags.precision, ' ');
	}
	else
		rtn += ft_adjust(flags.width - len, ' ');
	return (rtn);
}

int	ft_int_precision(t_flags flags, int len, int nb)
{
	int	i;
	int rtn;

	i = 0;
	rtn = 0;
	if (nb < 0 && flags.precision < len && !flags.zero)
	{
		write(1, "-", 1);
		return (1);
	}
	if (flags.precision > 0)
	{
		if (nb < 0)
		{
			write(1, "-", 1);
			rtn++;
			i--;
		}
		while (i++ < flags.precision - len)
		{
			write(1, "0", 1);
			rtn++;
		}
	}
	return (rtn);
}

int	ft_int_minus(t_flags flags, int len, char *str, int nb)
{
	int	rtn;

	rtn = 0;
	if (nb < 0)
		str++;
	if (flags.minus)
	{
		rtn += ft_int_precision(flags, len, nb);
		rtn += ft_putstrprint_fd(str, 1);
		rtn += ft_int_adjust(flags, len, nb);
	}
	else if (!flags.minus)
	{
		rtn += ft_int_adjust(flags, len, nb);
		rtn += ft_int_precision(flags, len, nb);
		rtn += ft_putstrprint_fd(str, 1);
	}
	return (rtn);
}

int	ft_int_conv(t_flags flags, va_list args)
{
	int		nb;
	char	*str;
	int		len;
	int		rtn;

	nb = va_arg(args, int);
	str = ft_itoa(nb);
	len = ft_strlen(str);
	rtn = 0;
	if (flags.zero && (flags.minus || flags.precision >= 0))
		flags.zero = 0;
	if (flags.precision == 0 && *str == '0')
	{
		rtn += ft_adjust(flags.width, ' ');
		return (rtn);
	}
	rtn += ft_int_minus(flags, len, str, nb);
	free(str);
	return (rtn);
}
