/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chpark <chpark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 16:19:57 by chpark            #+#    #+#             */
/*   Updated: 2021/11/22 16:21:54 by chpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*a1;
	unsigned char	*a2;

	i = 0;
	a1 = (unsigned char *)s1;
	a2 = (unsigned char *)s2;
	if (a1 == NULL || a2 == NULL)
		return (0);
	if ((a1 == 0 && a2 == 0) || n == 0)
		return (0);
	else if (a1 == 0 || a2 == 0)
	{
		if (a1 == 0)
			return (-1);
		else
			return (1);
	}
	while (i < (n - 1) && (a1[i] != '\0' && a2[i] != '\0'))
	{
		if (a1[i] != a2[i])
			break ;
		i++;
	}
	return (a1[i] - a2[i]);
}
