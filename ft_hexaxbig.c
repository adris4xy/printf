/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexaxbig.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aortega- <aortega-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 11:47:24 by aortega-          #+#    #+#             */
/*   Updated: 2019/12/09 11:51:30 by aortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexaxbig(va_list args)
{
	char 				*str;
	int					i;
	unsigned long long	nb;

	nb = va_arg(args, unsigned long long);
	if (!nb)
		str = ft_strdup("0");
	else
		str = ft_itoa_base(nb, "0123456789ABCDEF");
	i = 0;
	i += ft_puthexastr(str);
	return (i);
}