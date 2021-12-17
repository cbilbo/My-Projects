/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbilbo <cbilbo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 14:52:53 by cbilbo            #+#    #+#             */
/*   Updated: 2021/07/27 11:51:38 by cbilbo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H

# define PUSHSWAP_H
# include "../libft/libft.h"

typedef struct s_ort
{
	t_list	*a;
	t_list	*b;
	int		len;
	char	*put;
}			t_ort;

typedef struct s_ps
{
	int		*stack;
	t_ort	*srt;
	int		num;
	int		lolkek;
	int		cheburek;
}			t_ps;

void	pushswap(t_ps *ps);
t_ort	*checkrot(t_ps *ps, t_ort *srt, char c, int i);
void	allrot(t_ort *srt, t_ps *temp, char c);
void	ft_errsps(t_ps *ps, char *c);

t_ps	*start_ps(int argc, char **argv);
void	readargs(t_ps *ps, int argc, char **argv);
t_list	*put_nbr_in_arr(t_ps *ps, char **str, t_list *arr);
void	check_double(t_ps *ps, t_list *arr, int nbr);
void	change_args(t_ps *ps, int len, int *arr);

t_ort	*tortcpy(t_ort *srt, char c);
t_ort	*check_srt(t_ps *ps, t_ort *srt);
t_ort	*put_tort(t_ps *ps);
t_ort	*clear_tort(t_ps *ps, t_ort *srt);

void	swap_small(t_ps *ps, t_ort *srt, char c, int num);
void	swap_three(t_ps *ps, t_list *head, char c);
void	rotsort(t_ps *ps, t_ort *srt, char c);
void	revrotsort(t_ps *ps, t_ort *srt, char c);

t_ort	*bubsort_ps(t_ps *ps, t_ort *srt, char c);
t_ort	*binradsort(t_ps *ps, t_ort *srt, int bin);

void	countsort(t_ps *ps, t_ort *srt);
void	rcountsort(t_ps *ps, t_ort *srt);
void	rrevcountsort(t_ps *ps, t_ort *srt);
void	revcountsort(t_ps *ps, t_ort *srt);

t_ort	*inssort(t_ps *ps, t_ort *srt, int dia);
void	mvlists(t_ps *ps, t_ort *srt, int ord, int fst);
int		findaerial(t_ps *ps, t_ort *srt, int fst, int lst);
void	pushback(t_ps *ps, t_ort *srt);
void	putinorder(t_ps *ps, t_ort *srt, int num);

int		*pullarr(t_ps *ps, t_ort *srt);
int		findmax(int *arr, int len, int num, int srtsize);
int		findmin(int *arr, int len, int num, int srtsize);
int		ft_lstlstpos(t_list *list, int fst, int lst);
int		ft_lstfstpos(t_list *list, int fst, int lst);

int		sf(t_ps *ps, t_ort *srt, char s);
int		pf(t_ps *ps, t_ort *srt, char s);
void	swap_first_element(t_ort *srt, char s);
int		rot(t_ps *ps, t_ort *srt, char s);
int		revrot(t_ps *ps, t_ort *srt, char s);

t_list	*toplist(t_list *head);
t_list	*rotate(t_list *head);
t_list	*revrotate(t_list *head);

int		*putstack(t_ps *ps, t_list *list);
int		check_arg(char **str, int num);

#endif
