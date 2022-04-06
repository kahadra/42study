/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chpark <chpark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 14:59:51 by chpark            #+#    #+#             */
/*   Updated: 2022/03/12 15:44:14 by chpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"

static int	find_form(char *form, va_list ap)
{
	int	sl;

	if (*form == 'c')
		sl = char_form(va_arg(ap, int));
	else if (*form == 's')
		sl = str_form(va_arg(ap, char *));
	else if (*form == 'i' || *form == 'd')
		sl = int_form(va_arg(ap, int));
	else if (*form == 'p')
		sl = pointer_form((long long)va_arg(ap, void *));
	else if (*form == 'u')
		sl = unsignedint_form(va_arg(ap, unsigned int));
	else if (*form == 'x' || *form == 'X')
		sl = hexa_form(va_arg(ap, unsigned int), (char *)form);
	else if (*form == '%')
		sl = char_form(*form);
	else
		sl = -1;
	return (sl);
}	

int	ft_printf(const char *str, ...)
{
	int		sl;
	int		rn;
	va_list	ap;

	rn = 0;
	va_start(ap, str);
	while (*str != '\0')
	{
		if (*str != '%')
		{
			rn += ft_putchar(*str);
			str++;
		}
		else
		{
			sl = find_form((char *)++str, ap);
			if (sl >= 0)
			{
				rn += sl;
				str = str + 1;
			}
		}
	}
	va_end(ap);
	return (rn);
}
