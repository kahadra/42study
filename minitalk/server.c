/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chpark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 17:59:05 by chpark            #+#    #+#             */
/*   Updated: 2022/05/03 17:59:09 by chpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_data	*data(void)
{
	static t_data	g_data;

	return (&g_data);
}

void	reset_data(void)
{
	data()->i = 0;
	data()->x = 0;
	data()->client_pid = 0;
}

void	handler(int sig, siginfo_t *info, void *ucontext)
{
	(void)ucontext;
	if (sig == SIGUSR1)
		sig = 0;
	else
		sig = 1;
	if (data()->client_pid != info->si_pid)
		reset_data();
	data()->x = data()->x << 1 | sig;
	data()->i++;
	if (data()->i == 8)
	{
		write(1, &data()->x, 1);
		reset_data();
	}
	data()->client_pid = info->si_pid;
}

int	main(void)
{
	struct sigaction	sa;

	reset_data();
	ft_putstr("pid : ");
	ft_putnbr(getpid());
	ft_putstr("\n");
	sa.sa_sigaction = &handler;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaddset(&sa.sa_mask, SIGUSR2);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		sleep(1);
}
