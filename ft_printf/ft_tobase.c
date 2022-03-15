/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tobase_n.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chpark <chpark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 17:57:31 by chpark            #+#    #+#             */
/*   Updated: 2022/03/12 18:44:00 by chpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "ft_printf.h"

static int	ft_check_error(char *base)
{
	int	i;
	int	j;

	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	i = 0;
	j = i;
	while (base[j] != '\0')
	{
		j++;
		if (base[i] == base[j])
			return (0);
	}
	while (base[i] != '\0')
	{
		if (base[i] < 48 || base[i] >= 123 || (base[i] >= 91 && base[i] <= 96))
			return (0);
		else
			i++;
	}
	return (1);
}

char	*ft_tobase(long long nbr, char *base)
{
	int		bl;
	char	*str;
	char	*temp;

	bl = ft_strlen(base);
	str = ft_strdup("");
	if (ft_check_error(base))
	{
		if ((nbr / bl) < bl && (nbr / bl) != 0)
		{
			temp = ft_substr(base, nbr / bl, 1);
			str = ft_strjoin(str, temp);
		}
		else if (nbr / bl >= bl)
			ft_tobase(nbr / bl, base);
		temp = ft_substr(base, nbr % bl, 1);
		str = ft_strjoin(str, temp);
	}
	else
	{
		free(str);
		return (NULL);
	}
	return (str);
}
