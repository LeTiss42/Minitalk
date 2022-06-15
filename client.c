/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathis <mathis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 17:34:50 by mathis            #+#    #+#             */
/*   Updated: 2022/06/15 16:50:49 by mathis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	mt_sendchar(unsigned char x, pid_t pid)
{
	int	i;

	i = 1;
	while (i <= 8)
	{
		if ((x & 1) == 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i++;
		x >>= 1;
		pause();
	}
}

void	mt_sendstr(char *str, pid_t pid)
{
	size_t	i;

	i = 0;
	while (str[i] != 0)
		mt_sendchar((unsigned char)str[i++], pid);
	mt_sendchar('\n', pid);
	mt_sendchar(0, pid);
}

static void	mt_clienthandler(int sig_id)
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

	signal(SIGUSR1, mt_clienthandler);
	signal(SIGUSR2, mt_endstr);
	if (argc != 3)
	{
		mt_putstr_fd("\n>>arguments invalides<<\n", 1);
		mt_putstr_fd("./client [PID du server] [message]\n", 1);
		return (0);
	}
	pid_number = mt_atoi(argv[1]);
	mt_sendstr(argv[2], pid_number);
	return (0);
}
