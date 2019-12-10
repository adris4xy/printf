/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checktype.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aortega- <aortega-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 15:15:43 by aortega-          #+#    #+#             */
/*   Updated: 2019/12/09 15:46:05 by aortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_checktype(t_vprint *a)
{
	int			i;
	
	i = 0;
	if (*a->str == 's')
		i = ft_putstrcount(a->args);
	else if (*a->str == 'c')
		i = ft_putcharcount(a->args);
	else if (*a->str == 'd' || *a->str == 'i')
		i = ft_putnumber(a->args);
	else if (*a->str == 'p')
		i = ft_hexap(a->args);
	else if (*a->str == 'x')
		i = ft_hexax(a->args);
	else if (*a->str == 'X')
		i = ft_hexaxbig(a->args);
	else if (*a->str == 'u')
		i = ft_unsignedcount(a->args);
	else if (*a->str == '%')
		i = ft_percentcount(a->c);
	return (i);	
	
}