/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tobase_n.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chpark <chpark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 17:57:31 by chpark            #+#    #+#             */
/*   Updated: 2022/03/12 18:44:00 by chpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

size_t	put_hex(unsigned long n, char *base)
{
	int				i;
	unsigned int	bl;

	bl = ft_strlen(base);
	i = 0;
	if (n >= bl)
		i += put_hex((n / bl), base);
	i += ft_putchar(base[(n % bl)]);
	return (i);
}

int	ft_putstr(char *s)
{
	if (!(s))
		return (-1);
	write(1, s, ft_strlen(s));
	return (ft_strlen(s));
}

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}
