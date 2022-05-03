/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chpark <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 17:58:00 by chpark            #+#    #+#             */
/*   Updated: 2022/05/03 17:58:06 by chpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H 

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>

typedef struct s_data
{
	int		i;
	char	x;
	int		client_pid;
}	t_data;

void	send_byte(char byte, int pid);
void	send_message(char *str, int pid);
void	usage(void);
void	handler2(int sig);
void	reset_data(void);
void	handler(int sig, siginfo_t *info, void *ucontext);
int		ft_atoi(const char *str);
void	ft_putstr(char *str);
void	ft_putnbr(int n);
#endif
