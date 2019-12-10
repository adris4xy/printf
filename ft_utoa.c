/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aortega- <aortega-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 13:22:08 by aortega-          #+#    #+#             */
/*   Updated: 2019/12/09 13:36:58 by aortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		num_length(long n)
{
	int	i;

	i = 1;
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static char		*fill_string(char *str, int l, long nbr)
{
	str[--l] = '\0';
	while (nbr / 10 >= 1)
	{
		str[--l] = (nbr % 10) + '0';
		nbr /= 10;
	}
	str[0] = (nbr % 10) + '0';
	return (str);
}

char			*ft_utoa(unsigned int n)
{
	char	*str;
	int		l;
	long	nbr;

	nbr = n;
	l = num_length(nbr);
	if (n == 0)
		return (str = ft_strdup("0"));
	if (!(str = malloc(sizeof(char) * l)))
		return (0);
	str = fill_string(str, l, nbr);
	return (str);
}
