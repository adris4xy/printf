/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aortega- <aortega-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 15:35:58 by aortega-          #+#    #+#             */
/*   Updated: 2019/12/09 15:46:02 by aortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <errno.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>
# include "./libft/libft.h"

typedef struct s_vprint
{
	int		len;
	char	*str;
	char	c;
	va_list	args;
}				t_vprint;

int		ft_printf(const char *s, ...);
int		ft_specialputchar(char *str);

int		ft_checktype(t_vprint *a);

int		ft_putstrcount(va_list args);

int		ft_putcharcount(va_list args);

int		ft_putnumber(va_list args);

int		ft_hexap(va_list args);
char	*ft_ulltoa_base(unsigned long long nbr, char *base);
int		ft_puthexastr(char *s);

int		ft_hexax(va_list args);
int		ft_hexaxbig(va_list args);
char	*ft_itoa_base(unsigned int nbr, char *base);

int		ft_unsignedcount(va_list args);
char	*ft_utoa(unsigned int n);

int		ft_percentcount(char c);
#endif