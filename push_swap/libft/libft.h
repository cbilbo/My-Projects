/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbilbo <cbilbo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 19:03:13 by cbilbo            #+#    #+#             */
/*   Updated: 2021/07/27 10:58:25 by cbilbo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H

# define LIBFT_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE  32
# endif
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdarg.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

int				ft_atoi(const char *string);
void			ft_bzero(void *string, size_t size);
void			*ft_calloc(size_t num, size_t size);
int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isdigit(int c);
int				ft_isprint(int c);
int				ft_isspace(int c);
char			*ft_itoa(int number);
void			ft_lstadd_back(t_list **lst, t_list *new);
void			ft_lstadd_front(t_list **lst, t_list *new);
t_list			**ft_lstaddr(int i, void *a, void *b);
void			ft_lstclear(t_list **lst, void (*del)(void **));
t_list			*ft_lstcpy(t_list *src);
void			ft_lstdelone(t_list *lst, void(*del)(void *));
void			ft_lstiter(t_list *lst, void (*function)(void *));
t_list			*ft_lstlast(t_list *lst);
t_list			*ft_lstmap(t_list *lst, void *(*function)(void *), \
							void (*del)(void **));
t_list			*ft_lstnew(void *content);
int				ft_lstorder(t_list *list);
int				ft_lstrevorder(t_list *list);
int				ft_lstsize(t_list *lst);
void			*ft_memccpy(void *destination, const void *source, \
							int lastchar, size_t count);
void			*ft_memchr(const void *source, int symbol, size_t len);
int				ft_memcmp(const void *string1, const void *string2, \
												size_t len);
void			*ft_memcpy(void *destination, const void *source, size_t len);
void			*ft_memmove(void *destination, const void *source, size_t len);
void			*ft_memset(void *destination, int symbol, size_t len);
int				ft_nbrlen(long nbr);
int				ft_putchar_nbr(int c);
int				ft_putcharl(int symbol, int len);
void			ft_putchar_fd(char symbol, int fd);
void			ft_putendl_fd(char *string, int fd);
void			ft_putnbr_fd(int number, int fd);
int				ft_putstr_nbr(char *s);
int				ft_putstrl(char const *string, int len);
void			ft_putstr_fd(char const *string, int fd);
void			ft_qsort(int *arr, int first, int last);
char			**ft_split(char const *string, char symbol);
char			*ft_strchr(const char *string, int symbol);
char			*ft_strdup(const char *string);
char			*ft_strjoin(char const *string1, char const *string2);
size_t			ft_strlcat(char *destination, const char *source, size_t len);
size_t			ft_strlcpy(char *destination, const char *source, size_t len);
size_t			ft_strlen(const char *string);
size_t			ft_strlen_until(const char *string, const char *smls);
char			*ft_strmapi(char const *string, \
							char (*function)(unsigned int, char));
int				ft_strcmp(const char *string1, const char *string2);
int				ft_strncmp(const char *string1, const char *string2, \
									size_t len);
char			*ft_strnstr(const char *haystack, const char *needle, \
							size_t len);
char			*ft_strrchr(const char *string, int symbol);
char			*ft_strtrim(char const *string, char const *excess);
void			ft_swap(int *a, int *b);
void			ft_swap_d(double *a, double *b);
char			*ft_substr(char const *string, unsigned int start, size_t len);
int				ft_tolower(int c);
int				ft_toupper(int c);
int				get_next_line(int fd, char **line);
void			ft_allocfree(void **string);
int				ft_ter_i(int arg, int first_res, int second_res);
char			*ft_ter_s(int arg, char *first_res, char *second_res);
double			ft_ter_d(int arg, double first_res, double second_res);

#endif
