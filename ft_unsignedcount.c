/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsignedcount.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aortega- <aortega-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 13:13:32 by aortega-          #+#    #+#             */
/*   Updated: 2019/12/09 13:39:00 by aortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_unsignedcount(va_list args)
{
	char 				*str;
	int					i;

	i = 0;
	str = ft_utoa(va_arg(args, unsigned int));
	i += ft_puthexastr(str);
	return (i);
}