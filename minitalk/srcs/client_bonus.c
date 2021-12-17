/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbilbo <cbilbo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 18:22:27 by cbilbo            #+#    #+#             */
/*   Updated: 2021/09/23 13:29:33 by cbilbo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk_bonus.h"

int	g_check = 0;

static void	check_kill(int pid, int sig)
{
	if ((kill(pid, sig)) == -1)
	{
		ft_printf("Error: Problem with signal %d\n", sig);
		pause();
	}
}

static void	signul(int sig, siginfo_t *info, void *ucontext)
{
	siginfo_t	*usl;
	void		*usls;

	usl = info;
	usls = ucontext;
	if (sig == SIGUSR1)
		g_check = 1;
	else if (sig == SIGUSR2)
	{
		ft_printf("Finish!\n");
		exit (EXIT_SUCCESS);
	}
	usleep(1);
}

static void	send_char(int mes, int nbr_of_bit, int pid)
{
	if (nbr_of_bit > 0)
		send_char(mes / 2, nbr_of_bit - 1, pid);
	while (g_check == 0)
		usleep(1);
	if (mes % 2)
		check_kill(pid, SIGUSR1);
	else
		check_kill(pid, SIGUSR2);
	g_check = 0;
	usleep(1);
}

static void	transmitter(int pid, unsigned char *message)
{
	int	i;

	i = -1;
	g_check = 1;
	while (message[++i])
		send_char(message[i], 7, pid);
	send_char(message[i], 7, pid);
}

int	main(int ac, char **av)
{
	struct sigaction	sigac;

	if (ac != 3)
	{
		ft_printf("Error: Wrong numbers of arguments\n");
		exit (EXIT_FAILURE);
	}
	sigac.sa_flags = SA_SIGINFO;
	sigac.sa_sigaction = signul;
	if (sigaction(SIGUSR1, &sigac, 0) == -1 || \
		sigaction(SIGUSR2, &sigac, 0) == -1)
	{
		ft_printf("Error: Problems with sigaction\n");
		exit (EXIT_FAILURE);
	}
	transmitter(ft_atoi(av[1]), (unsigned char *)av[2]);
	while (1)
		pause();
	return (0);
}
