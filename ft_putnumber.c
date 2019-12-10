/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnumber.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aortega- <aortega-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 10:54:47 by aortega-          #+#    #+#             */
/*   Updated: 2019/12/05 11:37:59 by aortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnumber(va_list args)
{
	int		i;
	char	*str;

	i = 0;
	str = ft_itoa((int)va_arg(args, int));
	while(str[i])
	{		
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}