/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstbeflast.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebelkhei <ebelkhei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 16:29:40 by ebelkhei          #+#    #+#             */
/*   Updated: 2023/02/23 13:38:41 by ebelkhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_token	*ft_lstbeflast(t_token *lst)
{
	if (!lst || !lst->next)
		return (NULL);
	while (lst->next->next)
		lst = lst->next;
	return (lst);
}
