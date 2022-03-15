/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chpark <chpark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 13:51:58 by chpark            #+#    #+#             */
/*   Updated: 2021/12/03 14:03:23 by chpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_head(const char *s1, const char *set)
{
	int	i;
	int	l;

	l = ft_strlen(s1);
	i = 0;
	while (i < l)
	{
		if (ft_strchr(set, s1[i]) == 0)
			break ;
		i++;
	}
	return (i);
}

int	ft_tail(const char *s1, const char *set)
{
	int	i;
	int	l;

	l = ft_strlen(s1);
	i = 0;
	while (i < l)
	{
		if (ft_strchr(set, s1[l - i - 1]) == 0)
			break ;
		i++;
	}
	return (l - i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*s;
	int		h;
	int		t;

	if (!s1)
		return (0);
	if (!set)
		return (ft_strdup(s1));
	h = ft_head(s1, set);
	t = ft_tail(s1, set);
	if (h >= t)
		return (ft_strdup(""));
	s = (char *)malloc(sizeof(char) * ft_strlen(s1) + 1);
	if (!s)
		return (NULL);
	ft_strlcpy(s, s1 + h, t - h + 1);
	return (s);
}
