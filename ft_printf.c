/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aortega- <aortega-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 12:50:13 by aortega-          #+#    #+#             */
/*   Updated: 2019/12/18 15:08:55 by aortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_special_putchar(char c) //Sirve para que vaya contando el numero de caracteres que tiene el input
{								   //sin contar con nada que tenga que ver con el %. 
	int rtn;

	rtn = 0;
	if (c != '%')
	{
		write(1, &c, 1);
		rtn++;
	}
	return (rtn);
}

int		ft_printf(const char *input, ...)
{
	va_list args;
	t_flags flags;
	int		rtn;
	int		i;

	i = 0;
	rtn = 0;
	va_start(args, input);
	while (input[i])
	{
		rtn += ft_special_putchar(input[i]);
		if (input[i] == '%' && input[i + 1])
		{
			i++;							//Avanza una posicion en el input, pero sin contar para el contador rtn.
			flags = ft_init_flags(flags);   //Iguala la estructura "flags", inicializando los flags de la libreria.
			flags = ft_parser_flags(&input[i], flags, args); //Al pasar por aqui, analiza que flag es y que debe hacer.
			while (ft_is_flag(input[i])) //Esto solo sirve para seguir avanzando el input sin aumentar el contador
				i++;					 //"rtn" mientras es un flag.
			rtn += ft_parser_conv(input[i], flags, args); //Analiza que conversor es y que debe hacer,
		}												  //sumandole al contador los caracteres de ese argumento.
		i++;
	}
	va_end(args);
	return (rtn);
}
