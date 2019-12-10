/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aortega- <aortega-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 14:32:08 by aortega-          #+#    #+#             */
/*   Updated: 2019/12/09 14:08:25 by aortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int main()
{
	char	a[] = "hola";
	int		b;
	int		j;
	int		c = -29;
	int		*ptr = &c;
	b = ft_printf("perra %%\n");
	printf("El numero de caracteres es %d\n", b);

	j = printf("perra %%\n");
	printf("El numero de caracteres es %d\n", j);
	return (0);
}