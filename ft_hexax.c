/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexax.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aortega- <aortega-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 17:32:28 by aortega-          #+#    #+#             */
/*   Updated: 2019/12/09 11:40:50 by aortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexax(va_list args)
{
	char 				*str;
	int					i;
	unsigned long long	nb;

	nb = va_arg(args, unsigned long long);
	if (!nb)
		str = ft_strdup("0");
	else
		str = ft_itoa_base(nb, "0123456789abcdef");
	i = 0;
	i += ft_puthexastr(str);
	return (i);
}