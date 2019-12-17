/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent_conv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aortega- <aortega-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 13:59:04 by aortega-          #+#    #+#             */
/*   Updated: 2019/12/17 15:50:45 by aortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_percent_conv(t_flags flags)
{
	int					rtn;

	rtn = 0;
	if (flags.minus)
	{
		ft_putchar_fd('%', 1);
		if (flags.zero)
			rtn += ft_adjust(flags.width - 1, '0');
		else
			rtn += ft_adjust(flags.width - 1, ' ');
	}
	else if (!flags.minus)
	{
		if (flags.zero)
			rtn += ft_adjust(flags.width - 1, '0');
		else
			rtn += ft_adjust(flags.width - 1, ' ');
		ft_putchar_fd('%', 1);
	}
	return (rtn + 1);
}
