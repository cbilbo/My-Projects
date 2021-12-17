/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbilbo <cbilbo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 16:46:42 by cbilbo            #+#    #+#             */
/*   Updated: 2021/01/28 18:41:56 by cbilbo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdarg.h>
# include "./libft/libft.h"

enum	e_prf_type
{
	C,
	S,
	P,
	D,
	I,
	U,
	O,
	LX,
	UX,
	PERC,
	ERR
};

typedef struct	s_printf
{
	va_list		arg;
	char		*str;
	int			str_len;
	int			minus;
	int			zero;
	int			width;
	int			accuracy;
	int			type;
	int			length;
	int			num;
	int			base;
	char		upper;
	void		(*output[11])(struct	s_printf *);
}				t_printf;

void			ft_parser(t_printf *prf);
void			start_prf(char *string, t_printf *prf);
void			fill_prf(t_printf *prf);
void			flag_prf(t_printf *prf);
void			width_prf(t_printf *prf);
void			accuracy_prf(t_printf *prf);
void			type_prf(t_printf *prf);
void			output_c(t_printf *prf);
void			output_s(t_printf *prf);
void			output_nbr(t_printf *prf);
void			s_with_acc(char *str, int len, t_printf *prf);
void			s_without_acc(char *str, int len, t_printf *prf);
int				ft_nbrlen_prf(long nbr, t_printf *prf);
void			nbr_is_null(t_printf *prf);
void			nbr_with_accu(long nbr, t_printf *prf, int len);
void			nbr_without_accu(long nbr, t_printf *prf, int len);
void			printadress(t_printf *prf);
void			ft_putnbr_base_prf(long number, t_printf *prf);
void			ft_nbrminus_prf(long *nbr, t_printf *prf);
int				ft_printf(const char *string, ...);
#endif
