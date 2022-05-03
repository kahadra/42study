/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chpark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 17:57:26 by chpark            #+#    #+#             */
/*   Updated: 2022/05/03 17:57:29 by chpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	send_byte(char byte, int pid)
{
	int	j;

	j = 7;
	while (j >= 0)
	{
		if (byte >> j & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(500);
		j--;
	}
}

void	send_message(char *str, int pid)
{
	int	i;

	i = -1;
	while (str[++i])
		send_byte(str[i], pid);
	send_byte(0, pid);
}

void	usage(void)
{
	ft_putstr("./client [server-pid] [message]\n");
	exit(0);
}

void	handler2(int sig)
{
	ft_putstr("server has received");
}

int	main(int ac, char *av[])
{
	int		server_pid;
	char	*msg;

	signal(SIGUSR2, handler2);
	if (ac != 3)
		usage();
	server_pid = ft_atoi(av[1]);
	msg = av[2];
	send_message(msg, server_pid);
	return (0);
}
