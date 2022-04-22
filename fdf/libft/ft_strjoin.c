/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chpark <chpark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 13:35:22 by chpark            #+#    #+#             */
/*   Updated: 2021/12/14 14:57:23 by chpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s;
	int		l1;
	int		l2;

	if (!s1 && !s2)
		return (NULL);
	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	s = (char *)malloc(sizeof(char) * (l1 + l2 + 1));
	if (!s)
		return (NULL);
	ft_strlcpy(s, s1, l1 + 1);
	ft_strlcat(s, s2, l1 + l2 + 1);
	return (s);
}	
