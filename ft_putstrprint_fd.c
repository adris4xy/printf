/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrprint_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aortega- <aortega-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 15:44:22 by aortega-          #+#    #+#             */
/*   Updated: 2019/12/16 17:11:34 by aortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstrprint_fd(char *str, int fd)
{
	int i;

	i = 0;
	if (!str)
		return (i);
	while (str[i])
		write(fd, &str[i++], 1);
	return (i);
}
