/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebelkhei <ebelkhei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 15:27:14 by ebelkhei          #+#    #+#             */
/*   Updated: 2023/02/17 12:04:34 by ebelkhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_lstclear(t_token **lst)
{
	t_token	*ptr;
	t_token	*tmp;

	if (!lst)
		return ;
	ptr = *lst;
	while (ptr)
	{
		tmp = ptr->next;
		ft_lstdelone(ptr);
		ptr = tmp;
	}
	*lst = NULL;
}