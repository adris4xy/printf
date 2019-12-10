/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aortega- <aortega-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 16:10:44 by aortega-          #+#    #+#             */
/*   Updated: 2019/12/05 17:04:35 by aortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexap(va_list args)
{
	char 				*str;
	int					i;
	unsigned long long	nb;

	nb = va_arg(args, unsigned long long);
	if (!nb)
		str = ft_strdup("0");
	else
		str = ft_ulltoa_base(nb, "0123456789abcdef");
	i = 0;
	i += ft_puthexastr("0x");
	i += ft_puthexastr(str);
	return (i);
}