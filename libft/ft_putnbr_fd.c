/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chpark <chpark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 15:18:53 by chpark            #+#    #+#             */
/*   Updated: 2021/12/14 15:51:05 by chpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int	nb;

	nb = 1;
	if (fd < 0)
		return ;
	if (n < 0 && n / 10 == 0)
	{
		ft_putchar_fd('-', fd);
	}
	if (n < 0)
	{
		nb = -1;
	}
	if (n / 10 != 0)
	{
		ft_putnbr_fd((n / 10), fd);
	}
	ft_putchar_fd((((n % 10) * nb) + '0'), fd);
}
