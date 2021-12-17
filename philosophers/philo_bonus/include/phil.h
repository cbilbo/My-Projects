/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phil.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbilbo <cbilbo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 16:45:37 by cbilbo            #+#    #+#             */
/*   Updated: 2021/09/13 16:36:35 by cbilbo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHIL_H

# define PHIL_H
# include <string.h>
# include <unistd.h>
# include <stdio.h>
# include <pthread.h>
# include <semaphore.h>
# include <stdlib.h>
# include <sys/time.h>
# include <signal.h>

# define R "\x1b[31m"
# define B "\x1b[34m"
# define G "\x1b[32m"
# define P "\x1b[35m"
# define Y "\x1b[33m"
# define C "\x1b[36m"
# define RESET "\x1b[0m"

typedef struct s_phl	t_phl;
typedef struct s_phil
{
	long long	lam;
	int			id;
	int			meals;
	pthread_t	osoph;
	t_phl		*phl;
}				t_phil;

typedef struct s_phl
{
	long long	time;
	int			nop;
	int			die;
	int			eat;
	int			son;
	int			nom;
	pid_t		*pids;
	sem_t		*forks;
	sem_t		*dead;
	sem_t		*death;
	sem_t		*print;
	sem_t		*taf;
	t_phil		**phil;
}				t_phl;

int			ft_args(char *s, char c, char *e);
t_phl		*free_phl(t_phl *phl, char c);
t_phl		*fill_forks(t_phl *phl);
t_phl		*start_phl(int ac, char **av);
t_phl		*fill_phil(t_phl *phl);

void		*printmess(t_phl *phl, t_phil *phil, char *s, int c);
void		life(t_phl *phl, t_phil *phil);
int			start_processes(t_phl *phl);
void		start_process(t_phl *phl);

void		printerror(char c);
void		sem_switch(t_phl *phl, t_phil *phil, int i);
void		ft_allocfree(void **string);
void		*ft_calloc(size_t num, size_t size);
long long	get_time(void);
void		my_usleep(long long time);

void		*check_memory(t_phl *phl, void *check);
void		*check_exit(void *pid);
void		*pids(void *phs);

#endif
