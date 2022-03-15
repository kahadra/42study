/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chpark <chpark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 18:51:15 by chpark            #+#    #+#             */
/*   Updated: 2022/03/12 18:57:48 by chpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	sl;

	sl = ft_strlen(src);
	i = 0;
	if (dstsize == 0)
		return (sl);
	while (src[i] != '\0' && i < (dstsize - 1))
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (sl);
}

char	*ft_strdup(const char *str)
{
	int		i;
	int		l;
	char	*s;

	l = ft_strlen(str);
	s = (char *)malloc(sizeof(char) * (l + 1));
	if (!s)
		return (NULL);
	i = 0;
	while (str[i] != '\0')
	{
		s[i] = str[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*s;
	int		l1;
	int		l2;

	if (!s1 || !s2)
		return (NULL);
	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	s = (char *)malloc(sizeof(char) * (l1 + l2 + 1));
	if (!s)
	{
		free(s1);
		free(s2);
		return (NULL);
	}
	ft_strlcpy(s, s1, l1 + 1);
	free(s1);
	ft_strlcpy(s + l1, s2, l2 + 1);
	free(s2);
	return (s);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*s1;

	if (!s)
		return (0);
	i = ft_strlen(s);
	if (i <= start)
		return (ft_strdup(""));
	s1 = (char *)malloc(sizeof(char) * (len + 1));
	if (!s1)
		return (NULL);
	ft_strlcpy(s1, (char *)s + start, len + 1);
	return (s1);
}
