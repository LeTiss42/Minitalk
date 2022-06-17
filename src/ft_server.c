/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_server.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravera <mravera@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 14:31:25 by mathis            #+#    #+#             */
/*   Updated: 2022/06/17 17:48:09 by mravera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minitalk.h"

void	mt_servhandler(int signum, siginfo_t *info, void *ucontext)
{
	static unsigned char	res;
	static int				i;

	(void)ucontext;
	res >>= 1;
	i++;
	if (signum == SIGUSR1)
		res |= 128;
	if (i == 8)
	{
		if (res == 0)
			kill(info->si_pid, SIGUSR2);
		write(1, &res, 1);
		res = 0;
		i = 0;
	}
	usleep(50);
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	act;

	act.sa_flags = SA_SIGINFO;
	act.sa_sigaction = mt_servhandler;
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	mt_putstr_fd("server is up with pid = ", 1);
	mt_putnbr_fd(getpid(), 1);
	write(1, "\n", 1);
	while (1)
		pause();
	return (0);
}
