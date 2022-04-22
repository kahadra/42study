/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chpark <chpark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 12:35:34 by chpark            #+#    #+#             */
/*   Updated: 2021/11/23 12:44:50 by chpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *b, int c, size_t n)
{
	unsigned char	*a;
	unsigned char	check;
	size_t			i;

	i = 0;
	a = (unsigned char *)b;
	check = c;
	while (i < n)
	{
		if (a[i] == check)
			return ((void *)(a + i));
		i++;
	}
	return (0);
}
