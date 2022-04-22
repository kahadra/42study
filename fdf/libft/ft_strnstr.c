/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chpark <chpark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 16:06:29 by chpark            #+#    #+#             */
/*   Updated: 2021/11/22 16:17:03 by chpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	nl;
	size_t	hl;
	size_t	size;

	if (*needle == '\0')
		return ((char *)haystack);
	nl = ft_strlen(needle);
	hl = ft_strlen(haystack);
	if (hl < nl || len < nl)
		return (0);
	if (hl > len)
		size = len;
	else
		size = hl;
	while (size-- >= nl)
	{
		if (ft_memcmp(haystack, needle, nl) == 0)
			return ((char *)haystack);
		haystack++;
	}
	return (0);
}
