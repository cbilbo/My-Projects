/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libasm.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbilbo <cbilbo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 14:55:08 by cbilbo            #+#    #+#             */
/*   Updated: 2021/07/23 17:12:26 by cbilbo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBASM_H

# define LIBASM_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdarg.h>
# include <errno.h>

typedef struct		s_list
{
	void			*content;
	struct s_list	*next;
} 					t_list;

size_t	ft_strlen(const char *s);
char	*ft_strcpy(char *dst, const char *src);
int     ft_strcmp(const char *s1, const char *s2);
ssize_t ft_write(int fildes, const void *buf, size_t nbyte);
ssize_t	ft_read(int fildes, void *buf, size_t nbyte);
char	*ft_strdup(const char *str);
int		ft_list_size_bonus(t_list *lst);
void	ft_list_push_front_bonus(t_list **begin_list, void *data);
void	ft_list_remove_if_bonus(t_list **begin_list, void *data_ref, int (*cmp)(), void (*free_fct)(void *));
void	ft_list_sort_bonus(t_list **begin_list, int (*cmp)());
int		ft_atoi_base_bonus(char *str, char *base);
#endif