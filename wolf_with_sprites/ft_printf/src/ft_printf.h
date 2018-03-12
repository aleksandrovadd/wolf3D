/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daleksan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 18:39:42 by daleksan          #+#    #+#             */
/*   Updated: 2017/10/29 00:28:55 by daleksan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "../../libft/libft.h"

typedef struct	s_plist
{
	int			plus;
	int			minus;
	int			hesh;
	int			space;
	int			zero;
	int			width;
	int			dot;
	int			precision;
	char		decim;
	char		percent;
	int			length;
	char		type;
	char		character;
}				t_plist;

t_plist			spec_init(t_plist *spec);
int				ft_printf(const char *format, ...);
int				parse_specif(char *format, int *i, t_plist *spec, va_list ap);
int				flags_check(char *str, int *i, t_plist *spec);
int				width_check(char *str, int *i, t_plist *spec, va_list ap);
int				precis_check(char *str, int *i, t_plist *spec, va_list ap);
void			type_def(t_plist *spec, va_list ap, int *len);
void			type_def_2(t_plist *spec, va_list ap, int *len);
void			ft_for_c(t_plist *spec, va_list ap, int *len);
void			ft_for_c_big(t_plist *spec, va_list ap, int *len);
void			ft_for_s(t_plist *spec, va_list ap, int *len);
void			ft_for_s_big(t_plist *spec, va_list ap, int *len);
void			ft_for_x(t_plist *spec, va_list ap, int *len);
void			ft_for_x_big(t_plist *spec, va_list ap, int *len);
void			ft_for_u(t_plist *spec, va_list ap, int *len);
void			ft_for_o(t_plist *spec, va_list ap, int *len);
void			ft_for_perc(t_plist *spec, int *len);
void			ft_for_d(t_plist *spec, va_list ap, int *len);
void			ft_for_p(t_plist *spec, va_list ap, int *len);
void			ft_modify_x(t_plist *spec, char *str);
int				ft_pchar(int i, char c);
int				ft_pstr(char *str, int len);
void			ft_width_d(t_plist *spec, int *len, char *str);
void			ft_width_d_2(int ln, t_plist *spec, int *len, char *str);
void			ft_width_x(t_plist *spec, int *len, char *str, char b);
void			ft_width_x_2(t_plist *spec, int *len, char *str, char b);
void			ft_width_s(t_plist *spec, int *len, char *str);
size_t			unsigned_length(t_plist *spec, size_t o, va_list ap);
intmax_t		signed_length(t_plist *spec, intmax_t d, va_list ap);
size_t			ft_strlen_s(wchar_t *str);
char			*ft_itoa_base(uintmax_t value, unsigned int base, int m);
char			*ft_itoa(intmax_t number);

#endif
