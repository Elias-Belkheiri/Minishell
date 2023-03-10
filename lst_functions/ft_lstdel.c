/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebelkhei <ebelkhei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 14:54:49 by ebelkhei          #+#    #+#             */
/*   Updated: 2023/03/02 18:38:46 by ebelkhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_lstdel(t_token *bef, t_token **current, t_token **tokens)
{
	t_token	*tmp;

	if (!bef)
	{
		*tokens = (*current)->next;
		ft_lstdelone(*current);
		(*current) = NULL;
	}
	else
	{
		tmp = (*current)->next;
		ft_lstdelone(*current);
		bef->next = tmp;
		*current = tmp;
	}
}
