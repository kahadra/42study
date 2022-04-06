/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chpark <chpark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 15:55:53 by chpark            #+#    #+#             */
/*   Updated: 2022/04/04 15:56:17 by chpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header/push_swap.h"
#include <stdlib.h>

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

void	ft_editstr(char *s, size_t n)
{
	size_t	i;

	i = ft_strlen(s);
	while (n > 0)
	{
		s[i - n] = '\0';
		n--;
	}
	return ;
}

void	ft_printf_stack_a(t_list *a)
{
	printf("a_arr[0] : %d\n", a->arr[0]);
	printf("a_arr[1] : %d\n", a->arr[1]);
	printf("a_arr[2] : %d\n", a->arr[2]);
//	printf("a_arr[3] : %d\n", a->arr[3]);
//	printf("a_arr[4] : %d\n", a->arr[4]);
//	printf("a_arr[5] : %d\n", a->arr[5]);
//	printf("a_arr[6] : %d\n", a->arr[6]);
//	printf("a_arr[7] : %d\n", a->arr[7]);
//	printf("a_arr[8] : %d\n", a->arr[8]);
	//printf("a_arr[9] : %d\n", a->arr[9]);
}

void	ft_printf_stack_b(t_list *b)
{
	printf("b_arr[0] : %d\n", b->arr[0]);
	printf("b_arr[1] : %d\n", b->arr[1]);
	printf("b_arr[2] : %d\n", b->arr[2]);
//	printf("b_arr[3] : %d\n", b->arr[3]);
//	printf("b_arr[4] : %d\n", b->arr[4]);
//	printf("b_arr[5] : %d\n", b->arr[5]);
//	printf("b_arr[6] : %d\n", b->arr[6]);
//	printf("b_arr[7] : %d\n", b->arr[7]);
//	printf("b_arr[8] : %d\n", b->arr[8]);
	//printf("b_arr[9] : %d\n", b->arr[9]);
}