/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chpark <chpark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 18:58:05 by chpark            #+#    #+#             */
/*   Updated: 2022/03/12 19:01:07 by chpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

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
