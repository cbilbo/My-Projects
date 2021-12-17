/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbilbo <cbilbo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 20:56:02 by cbilbo            #+#    #+#             */
/*   Updated: 2021/07/27 12:28:02 by cbilbo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pushswap.h"

void	change_args(t_ps *ps, int len, int *arr)
{
	int	*temp;
	int	i;
	int	j;

	i = -1;
	temp = (int *)ft_calloc(len, sizeof(int));
	if (!temp)
		ft_errsps(ps, "m");
	while (++i < len)
		temp[i] = arr[i];
	ft_qsort(temp, 0, len - 1);
	i = -1;
	while (++i < len)
	{
		j = -1;
		while (++j < len)
		{
			if (temp[i] == arr[j])
				arr[j] = i;
		}
	}
	ps->stack = arr;
	ft_allocfree((void *)&temp);
}

void	check_double(t_ps *ps, t_list *arr, int nbr)
{
	t_list	*temp;
	int		i;
	int		tmp;

	i = 0;
	temp = arr;
	while (temp->next)
	{
		tmp = *((int *)temp->content);
		if (nbr == tmp)
		{
			ft_lstclear(&arr, ft_allocfree);
			ft_errsps(ps, "d");
		}
		temp = temp->next;
	}
}

t_list	*put_nbr_in_arr(t_ps *ps, char **str, t_list *list)
{
	int		*tmp;
	char	*temp;

	temp = *str;
	tmp = (int *)malloc(sizeof(int));
	if (!tmp)
	{
		ft_lstclear(&list, ft_allocfree);
		ft_errsps(ps, "m");
	}
	tmp[0] = ft_atoi(temp);
	if (check_arg(str, tmp[0]))
	{
		free(tmp);
		ft_lstclear(&list, ft_allocfree);
		ft_errsps(ps, "g");
	}
	ft_lstadd_back(&list, ft_lstnew((void *)tmp));
	check_double(ps, list, tmp[0]);
	return (list);
}

void	readargs(t_ps *ps, int argc, char **argv)
{
	int		i;
	int		*arr;
	char	*temp;
	t_list	*list;

	i = 0;
	list = NULL;
	while (++i < argc)
	{
		temp = argv[i];
		while (temp && *temp != '\0')
		{
			while (*temp == ' ')
				temp++;
			if (!ft_strchr("0123456789-+", *temp) || \
				(ft_strchr("-+", *temp + 1) && !(ft_isdigit(*temp + 1))))
				ft_errsps(ps, "w");
			list = put_nbr_in_arr(ps, &temp, list);
		}
	}
	ps->num = ft_lstsize(list);
	arr = putstack(ps, list);
	ft_lstclear(&list, ft_allocfree);
	change_args(ps, ps->num, arr);
}

t_ps	*start_ps(int argc, char **argv)
{
	t_ps	*ps;

	ps = (t_ps *)ft_calloc(1, sizeof(t_ps));
	if (!ps)
		ft_errsps(ps, "m");
	readargs(ps, argc, argv);
	ps->srt = put_tort(ps);
	ps->srt->len = 69696969;
	ps->lolkek = ft_ter_i(ps->num > 300, 25, 10);
	ps->cheburek = ft_ter_i(ps->num > 300, 70, 45);
	return (ps);
}
