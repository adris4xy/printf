/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsign_conv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aortega- <aortega-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 14:04:22 by aortega-          #+#    #+#             */
/*   Updated: 2019/12/17 14:45:19 by aortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_unsign_adjust(t_flags flags, int len)
{
	int	rtn;

	rtn = 0;
	if (flags.zero && !flags.minus && flags.precision < 0)
		rtn += ft_adjust(flags.width - len, '0');
	else if (flags.precision >= len)
		rtn += ft_adjust(flags.width - flags.precision, ' ');
	else
		rtn += ft_adjust(flags.width - len, ' ');
	return (rtn);
}

int	ft_unsign_precision(int precision, int len)
{
	int	i;

	i = 0;
	if (precision)
		while (i < precision - len)
		{
			write(1, "0", 1);
			i++;
		}
	return (i);
}

int	ft_unsign_minus(t_flags flags, int len, char *str)
{
	int	rtn;

	rtn = 0;
	if (flags.minus)
	{
		rtn += ft_unsign_precision(flags.precision, len);
		rtn += ft_putstrprint_fd(str, 1);
		rtn += ft_unsign_adjust(flags, len);
	}
	else if (!flags.minus)
	{
		rtn += ft_unsign_adjust(flags, len);
		rtn += ft_unsign_precision(flags.precision, len);
		rtn += ft_putstrprint_fd(str, 1);
	}
	return (rtn);
}

int	ft_unsign_conv(t_flags flags, va_list args)
{
	char	*str;
	int		len;
	int		rtn;

	str = ft_utoa(va_arg(args, unsigned int));
	len = ft_strlen(str);
	rtn = 0;
	if (flags.precision == 0 && *str == '0')
	{
		rtn += ft_adjust(flags.width, ' ');
		return (rtn);
	}
	rtn += ft_unsign_minus(flags, len, str);
	free(str);
	return (rtn);
}
