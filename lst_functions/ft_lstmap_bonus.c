/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebelkhei <ebelkhei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 15:27:34 by ebelkhei          #+#    #+#             */
/*   Updated: 2022/10/27 15:52:49 by ebelkhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*ft_cpy(t_list *lst, t_list *head, void *(*f)(void *))
{
	t_list	*nw_lst;
	t_list	*ptr;

	ptr = lst;
	while (ptr)
	{
		if (!head)
		{
			head = ft_lstnew(f(ptr->content));
			if (!head)
				return (NULL);
			nw_lst = head;
		}
		else
		{
			nw_lst->next = ft_lstnew(f(ptr->content));
			if (!nw_lst->next)
				return (NULL);
			nw_lst = nw_lst->next;
		}
		ptr = ptr->next;
	}
	return (head);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;

	head = NULL;
	if (lst && f && del)
	{
		head = ft_cpy(lst, head, f);
		if (!head)
			ft_lstclear(&head, del);
		return (head);
	}
	return (NULL);
}
