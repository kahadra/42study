/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_form.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chpark <chpark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 16:08:38 by chpark            #+#    #+#             */
/*   Updated: 2022/03/12 16:19:07 by chpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "ft_printf.h"

size_t	int_form(int n)
{
	size_t	sl;
	char	*arg;

	arg = ft_itoa(n);
	sl = ft_putstr(arg);
	free(arg);
	return (sl);
}

size_t	unsignedint_form(unsigned int n)
{
	size_t	sl;
	char	*arg;

	arg = ft_uitoa(n);
	sl = ft_putstr(arg);
	free(arg);
	return (sl);
}

size_t	hexa_form(unsigned long n, char *form)
{
	size_t	sl;
	if (*form == 'x')
		sl = put_hex(n, "0123456789abcdef");
	else
		sl = put_hex(n, "0123456789ABCDEF");
	return (sl);
}

size_t	pointer_form(long long n)
{
	int	sl;

	sl = 2;
	ft_putchar('0');
	ft_putchar('x');
	sl += put_hex(n, "0123456789abcdef");
	return (sl);
}
