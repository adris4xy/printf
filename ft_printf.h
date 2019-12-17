/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aortega- <aortega-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 15:35:58 by aortega-          #+#    #+#             */
/*   Updated: 2019/12/17 15:08:31 by aortega-         ###   ########.fr       */
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

typedef struct		s_flags
{
	int	minus;
	int	zero;
	int	width;
	int	point;
	int	precision;
}					t_flags;

int					ft_printf(const char *input, ...);
t_flags				ft_init_flags(t_flags flags);
int					ft_is_flag(char c);
t_flags				ft_treat_flags(char input, t_flags flags, va_list args);
t_flags				ft_parser_flags(const char *input, t_flags flags,
					va_list args);
int					ft_parser_conv(char input, t_flags flags, va_list args);
int					ft_adjust(int width, char c);
int					ft_char_conv(t_flags flags, va_list args);
int					ft_str_conv(t_flags flags, va_list args);
int					ft_str_precision(char *str, int len, int precision,
					int mod);
int					ft_int_conv(t_flags flags, va_list args);
int					ft_int_minus(t_flags flags, int len, char *str, int nb);
int					ft_int_precision(t_flags flags, int len, int nb);
int					ft_int_adjust(t_flags flags, int len, int nb);
int					ft_putstrprint_fd(char *str, int fd);
int					ft_pos_conv(t_flags flags, va_list args);
int					ft_pos_minus(t_flags flags, int len, char *str);
char				*ft_ulltoa_base(unsigned long long nbr, char *base);
int					ft_hexa_conv(t_flags flags, va_list args, char *str);
int					ft_hexa_minus(t_flags flags, int len, char *str);
int					ft_hexa_precision(int precision, int len);
int					ft_hexa_adjust(t_flags flags, int len);
int					ft_unsign_conv(t_flags flags, va_list args);
int					ft_unsign_minus(t_flags flags, int len, char *str);
int					ft_unsign_precision(int precision, int len);
int					ft_unsign_adjust(t_flags flags, int len);
int					ft_percent_conv(t_flags flags);
char				*ft_utoa(unsigned int n);
#endif
