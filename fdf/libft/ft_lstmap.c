/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chpark <chpark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 17:36:15 by chpark            #+#    #+#             */
/*   Updated: 2021/12/14 16:02:53 by chpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*next;
	t_list	*now;

	if (lst == NULL || f == NULL || del == NULL)
		return (NULL);
	head = ft_lstnew(f(lst->content));
	if (head == NULL)
		return (NULL);
	now = head;
	lst = lst->next;
	while (lst)
	{
		next = ft_lstnew(f(lst->content));
		if (next == NULL)
		{
			ft_lstclear(&head, del);
			return (NULL);
		}
		now->next = next;
		now = next;
		lst = lst->next;
	}
	return (head);
}
