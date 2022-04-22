/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chpark <chpark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 18:11:22 by chpark            #+#    #+#             */
/*   Updated: 2021/12/14 15:48:57 by chpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**error_free(char **tab)
{
	unsigned int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

int	count_s(const char *s, char c)
{
	size_t	i;
	size_t	count;

	if (!s[0])
		return (0);
	i = 0;
	count = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] == c)
		{
			count++;
			while (s[i] && s[i] == c)
				i++;
			continue ;
		}
		i++;
	}
	if (s[i - 1] != c)
		count++;
	return (count);
}

static int	count_l(const char *s, char c)
{
	size_t	i;
	size_t	l;

	i = 0;
	l = 0;
	while (s[i] != c && s[i] != '\0')
	{
		i++;
		l++;
	}
	return (l);
}

static char	**fill_init(const char *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	count;
	char	**s1;

	i = 0;
	j = 0;
	count = count_s(s, c);
	s1 = (char **)malloc(sizeof(char *) * (count + 1));
	if (!s1)
		return (NULL);
	while (j < count)
	{
		while (s[i] == c)
			i++;
		s1[j] = ft_substr(s, i, count_l((s + i), c));
		if (!s1[j])
			return (error_free(s1));
		i += count_l((s + i), c);
		j++;
	}
	s1[j] = NULL;
	return (s1);
}

char	**ft_split(char const *s, char c)
{
	char	**s1;

	if (!s)
		return (NULL);
	s1 = fill_init(s, c);
	return (s1);
}
