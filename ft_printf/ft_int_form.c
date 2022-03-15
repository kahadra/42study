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

size_t	unsignedint_form(unsigned int n, char *form)
{
	size_t	sl;
	char	*arg;

	if (*form == 'u')
		arg = ft_itoa(n);
	else if (*form == 'x')
		arg = ft_tobase(n, "0123456789abcdef");
	else if (*form == 'X')
		arg = ft_tobase(n, "0123456789ABCDEF");
	else
		return (0);
	sl = ft_putstr(arg);
	free(arg);
	return (sl);
}

size_t	pointer_form(long long n)
{
	size_t	sl;
	char	*addr;

	addr = ft_tobase(n, "0123456789abcdef");
	addr = ft_strjoin(ft_strdup("0x"), addr);
	sl = ft_putstr(addr);
	free(addr);
	return (sl);
}
