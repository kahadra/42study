/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chpark <chpark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 11:50:59 by chpark            #+#    #+#             */
/*   Updated: 2021/12/08 13:59:02 by chpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	absol_n(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

int	nbr_len(int n)
{
	int	len;

	if (n <= 0)
		len = 1;
	else
		len = 0;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int		len;
	int		count;
	char	*s;

	len = nbr_len(n);
	if (n < 0)
		count = -1;
	else
		count = 1;
	s = (char *)malloc(sizeof(char) * (len + 1));
	if (!s)
		return (NULL);
	s[len] = '\0';
	len--;
	while (len >= 0)
	{
		s[len] = '0' + absol_n(n % 10);
		n = absol_n(n / 10);
		len--;
	}
	if (count == -1)
		s[0] = '-';
	return (s);
}
