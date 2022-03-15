/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chpark <chpark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 14:34:33 by chpark            #+#    #+#             */
/*   Updated: 2021/12/14 15:49:33 by chpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;
	unsigned int	j;

	i = ft_strlen(s);
	j = 0;
	if (s != NULL && f != NULL)
	{
		while (j < i)
		{
			(*f)(j, s);
			s++;
			j++;
		}
	}
}
