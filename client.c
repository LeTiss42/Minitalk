/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathis <mathis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 17:34:50 by mathis            #+#    #+#             */
/*   Updated: 2022/06/13 18:14:28 by mathis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	mt_atoi(const char *nptr)
{
	int				i;
	int				sign;
	unsigned int	res;

	sign = 1;
	i = 0;
	res = 0;
	while ((9 <= nptr[i] && nptr[i] <= 13) || (nptr[i] == ' '))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = sign * -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
		res = (res * 10) + (nptr[i++] - 48);
	return (sign * res);
}

void	mt_sendchar(unsigned char x, pid_t pid)
{
	int	i;

	printf("33333\n");
	i = 1;
	while (i <= 8)
	{
		if ((x & 1) == 1)
		{
			kill(pid, SIGUSR1);
			printf("1");
		}
		else
		{
			kill(pid, SIGUSR2);
			printf("0");
		}
		i++;
		x >>= 1;
		usleep(200);
	}
	printf("\n");
}

void	mt_sendstr(char *str, pid_t pid)
{
	size_t	i;

	printf("22222\n");
	i = 0;
	while (str[i] != 0)
		mt_sendchar((unsigned char)str[i++], pid);
}

int	main(int argc, char **argv)
{
	pid_t	pid_number;

	if (argc != 3)
		return (printf("\nutilisation :\n./client [PID du serveur] [message]\n"));
	pid_number = mt_atoi(argv[1]);
	kill(pid_number, SIGINT);
	printf("11111\n");
	mt_sendstr(argv[2], pid_number);
	return (0);
}
