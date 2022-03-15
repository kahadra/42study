/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_form.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chpark <chpark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 15:46:04 by chpark            #+#    #+#             */
/*   Updated: 2022/03/12 15:51:42 by chpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

size_t	char_form(int c)
{
	size_t	sl;

	sl = ft_putchar((char)c);
	return (sl);
}

size_t	str_form(char *str)
{
	size_t	sl;

	if (str == NULL)
		str = "(null)";
	sl = ft_putstr((char *)str);
	return (sl);
}
