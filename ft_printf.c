/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aortega- <aortega-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 17:19:28 by aortega-          #+#    #+#             */
/*   Updated: 2019/12/09 15:26:25 by aortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *s, ...)
{
	t_vprint	a;

	a.len = 0;
	a.str = (char *)s;
	va_start(a.args, s);
	while (*a.str)
	{
		if (*a.str == '%' && (*a.str + 1))
		{
			++a.str;
			a.len += ft_checktype(&a);
		}
		else
			a.len += ft_specialputchar(a.str);
		++a.str;
	}
	va_end(a.args);
	return (a.len);
}