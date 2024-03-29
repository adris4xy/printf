/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_conv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aortega- <aortega-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 16:47:03 by aortega-          #+#    #+#             */
/*   Updated: 2019/12/17 15:57:17 by aortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_str_precision(char *str, int len, int precision, int mod)
{
	int	i;

	i = 0;
	if (precision != -1 && len <= precision)
		while (str[i])
		{
			if (mod)
				write(1, &str[i], 1);
			i++;
		}
	else if (precision != -1 && len > precision)
		while (i < precision)
		{
			if (mod)
				write(1, &str[i], 1);
			i++;
		}
	else
		while (str[i])
		{
			if (mod)
				write(1, &str[i], 1);
			i++;
		}
	return (i);
}

int		str_adjust(int zero, int width)
{
	int rtn;

	rtn = 0;
	if (zero)
		rtn += ft_adjust(width, '0');
	else
		rtn += ft_adjust(width, ' ');
	return (rtn);
}

char	*str_special(char *str, t_flags flags)
{
	if (!str && flags.precision)
		str = ft_strdup("(null)");
	else if (!str && !flags.precision)
		str = ft_strdup("");
	return (str);
}

int		ft_str_conv(t_flags flags, va_list args)
{
	char	*str;
	int		len;
	int		rtn;
	int		how;

	rtn = 0;
	str = va_arg(args, char *);
	str = str_special(str, flags);
	len = ft_strlen(str);
	how = ft_str_precision(str, len, flags.precision, 0);
	if (flags.minus && flags.width > how)
	{
		rtn += ft_str_precision(str, len, flags.precision, 1);
		rtn += str_adjust(flags.zero, (flags.width - how));
	}
	else if (!flags.minus && flags.width > how)
	{
		rtn += str_adjust(flags.zero, (flags.width - how));
		rtn += ft_str_precision(str, len, flags.precision, 1);
	}
	else
		rtn += ft_str_precision(str, len, flags.precision, 1);
	return (rtn);
}
