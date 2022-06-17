/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_client_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravera <mravera@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 17:34:50 by mathis            #+#    #+#             */
/*   Updated: 2022/06/17 17:48:30 by mravera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minitalk_bonus.h"

void	mt_sendchar(unsigned char x, pid_t pid, int *test)
{
	int	i;

	i = 1;
	while (i <= 8)
	{
		if ((x & 1) == 1)
			*test = kill(pid, SIGUSR1);
		else
			*test = kill(pid, SIGUSR2);
		i++;
		x >>= 1;
		if (*test == -1)
			return ;
		pause();
		usleep(50);
	}
}

void	mt_sendstr(char *str, pid_t pid, int *test)
{
	size_t	i;

	i = 0;
	while (str[i] != 0)
	{
		mt_sendchar((unsigned char)str[i++], pid, test);
		if (*test == -1)
			return ;
	}
	mt_sendchar('\n', pid, test);
	mt_sendchar(0, pid, test);
}

void	mt_clienthandler(int sig_id)
{
	(void) sig_id;
}

void	mt_endstr(int sig_id)
{
	(void) sig_id;
	mt_putstr_fd("\nmessage bien reçu\n", 1);
}

int	main(int argc, char **argv)
{
	pid_t	pid_number;
	int		*test;
	int		val;

	val = 1;
	test = &val;
	signal(SIGUSR1, mt_clienthandler);
	signal(SIGUSR2, mt_endstr);
	if (argc != 3)
	{
		mt_putstr_fd("\n>> arguments invalides <<\n", 1);
		mt_putstr_fd("./client [PID du server] [message]\n", 1);
		return (0);
	}
	if (mt_verifpid(argv[1]) == -1)
	{
		mt_putstr_fd("\n>> Pid invalide <<\n", 1);
		return (0);
	}
	pid_number = mt_atoi(argv[1]);
	mt_sendstr(argv[2], pid_number, test);
	if (*test == -1)
		mt_putstr_fd("\n>> Pid invalide <<\n", 1);
	return (0);
}
