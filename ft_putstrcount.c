/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrcount.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aortega- <aortega-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 12:55:50 by aortega-          #+#    #+#             */
/*   Updated: 2019/12/05 10:49:08 by aortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstrcount(va_list args)
{
	int	i;
	char *str;

	i = 0;
	str = va_arg(args, char *);
	while(str[i])
	{		
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}