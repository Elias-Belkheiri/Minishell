/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bn.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebelkhei <ebelkhei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 15:27:24 by ebelkhei          #+#    #+#             */
/*   Updated: 2022/10/19 20:01:51 by ebelkhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*ptr;

	if (lst && f)
	{
		ptr = lst;
		while (ptr->next)
		{
			f(ptr->content);
			ptr = ptr->next;
		}
		f(ptr->content);
	}
}
