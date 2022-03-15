/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chpark <chpark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 15:23:49 by chpark            #+#    #+#             */
/*   Updated: 2021/11/22 15:33:12 by chpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	dl;
	size_t	sl;

	dl = ft_strlen(dest);
	sl = ft_strlen(src);
	if (dl >= size)
		return (size + sl);
	i = 0;
	while (src[i] != '\0' && i < (size - dl - 1))
	{
		dest[dl + i] = src[i];
		i++;
	}
	dest[dl + i] = '\0';
	return (dl + sl);
}
