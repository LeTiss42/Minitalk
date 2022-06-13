/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathis <mathis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 14:31:25 by mathis            #+#    #+#             */
/*   Updated: 2022/06/10 17:57:55 by mathis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void	sig_handler(int signum)
{
	printf("\nmessage du sig_handler\n");
}

int	main(void)
{
	int	i;
	int	pid_t;

	i = 0;
	signal(SIGINT, sig_handler);
	pid_t = getpid();
	printf("### server initialized ###\nPID = %d\nwaiting for message from client...\n", pid_t);
	sleep(5);
	while (i <= 10)
	{
		printf("waiting for message from client...\n");
		sleep(5);
		i++;
	}
	return (0);
}
