/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathis <mathis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 14:31:25 by mathis            #+#    #+#             */
/*   Updated: 2022/06/13 17:19:58 by mathis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	mt_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	while (*s)
		write(fd, &(*(s++)), 1);
}

void	mt_putnbr_fd(int n, int fd)
{
	char	a;

	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
	}
	if (n >= 10)
		mt_putnbr_fd(n / 10, fd);
	a = n % 10 + '0';
	write(fd, &a, 1);
	return ;
}

void	mt_handler(int signum)
{
	static unsigned char	res;
	static int				i;

	mt_putstr_fd("\n|||||||||||||||\n", 1);
	i = 1;
	if (signum == SIGUSR1)
	{
		res |= 128;
		printf("1\n");
	}
	else
		printf("0\n");
	if (i < 8)
	{
		res >>= 1;
		i++;
	}
	if (i == 8)
	{
		write(1, &res, 1);
		res = 0;
		i = 0;
	}
	usleep(200);
}

int	main(void)
{
	//struct sigaction	act;

	//act.sa_flags = SA_SIGINFO;
	//act.sa_sigaction = mt_handler;
	//sigaction(SIGUSR1, &act, NULL);
	//sigaction(SIGUSR2, &act, NULL);
	signal(SIGUSR1, mt_handler);
	signal(SIGUSR2, mt_handler);
	mt_putstr_fd("server is up with pid = ", 1);
	mt_putnbr_fd(getpid(), 1);
	write(1, "\n", 1);
	while (1)
		pause();
	return (0);
}
