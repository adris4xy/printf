/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aortega- <aortega-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 14:52:18 by aortega-          #+#    #+#             */
/*   Updated: 2019/12/17 15:02:24 by aortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags		ft_init_flags(t_flags flags)
{
	flags.minus = 0;
	flags.zero = 0;
	flags.width = 0;
	flags.point = 0;
	flags.precision = -1;
	return (flags);
}

int			ft_is_flag(char c)
{
	if (c == '-' || c == '.' || c == '*' || ft_isdigit(c))
		return (1);
	return (0);
}

t_flags		ft_asterisk_flag(t_flags flags, va_list args)
{
	if (flags.point)
		flags.precision = va_arg(args, int);
	else if (flags.width < 1)
	{
		flags.width = va_arg(args, int);
		if (flags.width < 0)
		{
			flags.width *= -1;
			flags.minus = 1;
		}
	}
	return (flags);
}

t_flags		ft_treat_flags(char input, t_flags flags, va_list args)
{
	if (input == '-')
		flags.minus = 1;
	else if (input == '0' && flags.width < 1 && !flags.point)
		flags.zero = 1;
	else if (ft_isdigit(input) && !flags.point)
		flags.width = (flags.width * 10) + (input - '0');
	else if (input == '.')
	{
		flags.point = 1;
		flags.precision = 0;
	}
	else if (ft_isdigit(input) && flags.point)
		flags.precision = (flags.precision * 10) + (input - '0');
	else if (input == '*')
		flags = ft_asterisk_flag(flags, args);
	return (flags);
}

t_flags		ft_parser_flags(const char *input, t_flags flags, va_list args)
{
	int		i;

	i = 0;
	while (input[i] && ft_is_flag(input[i]))
	{
		flags = ft_treat_flags(input[i], flags, args);
		i++;
	}
	return (flags);
}
