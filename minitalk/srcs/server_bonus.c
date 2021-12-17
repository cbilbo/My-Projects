/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbilbo <cbilbo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 18:23:34 by cbilbo            #+#    #+#             */
/*   Updated: 2021/09/23 13:24:04 by cbilbo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk_bonus.h"

static void	check_kill(pid_t pid, int sig)
{
	usleep(1);
	if ((kill(pid, sig)) == -1)
	{
		ft_printf("Error: Problem with signal %d\n", sig);
		exit (EXIT_FAILURE);
	}
}

static void	receiver(int sig, siginfo_t *info, void *ucontext)
{
	static unsigned char	mes[100000] = "\0";
	static int				i = 0;
	static int				bit = 0;
	int						stop;

	ucontext = NULL;
	stop = 0;
	if (bit++)
		mes[i] = mes[i] << 1;
	mes[i] += ft_ter_i(sig == SIGUSR1, 1, 0);
	if (bit == 8)
	{
		bit = 0;
		if (mes[i++] == 0 && ++stop)
		{
			check_kill(info->si_pid, SIGUSR2);
			ft_printf("%s\nServer's pid is %d\n", mes, (int)getpid());
			ft_memset(mes, '\0', 100000);
			i = 0;
		}
	}
	if (!stop)
		check_kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sigac;

	ft_printf("Server is started!\nServer's pid is %d\n", (int)getpid());
	sigac.sa_flags = SA_SIGINFO;
	sigac.sa_sigaction = receiver;
	if (sigaction(SIGUSR1, &sigac, 0) == -1 || \
		sigaction(SIGUSR2, &sigac, 0) == -1)
	{
		ft_printf("Error: Problem with sigaction\n");
		exit (EXIT_FAILURE);
	}
	while (1)
		pause();
	return (0);
}
