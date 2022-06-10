
#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void	sig_handler(int signum)
{
	printf("\nInside handler function\n");
}

int	main(void)
{
	int	i;
	int	pid_t;

	i = 0;
	signal(SIGINT, sig_handler);
	while (i < 10)
	{
		pid_t = getpid();
		printf("%d : Inside main function\npid = %d\n", i, pid_t);
		sleep(1);
		i++;
	}
	return (0);
}
