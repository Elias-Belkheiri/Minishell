/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebelkhei <ebelkhei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 15:27:03 by ebelkhei          #+#    #+#             */
/*   Updated: 2023/02/26 19:13:25 by ebelkhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_lstadd_back(t_token **lst, t_token *new)
{
	t_token	*prv;

	prv = *lst;
	if (!(*lst))
	{
		*lst = new;
		return ;
	}
	while (prv->next)
		prv = prv->next;
	prv->next = new;
}

void	ft_lstadd_back_2(t_env **lst, t_env *new)
{
	t_env	*prv;

	prv = *lst;
	if (!(*lst))
	{
		*lst = new;
		return ;
	}
	while (prv->next)
		prv = prv->next;
	prv->next = new;
}

void	ft_lstadd_back_3(t_cmd **lst, t_cmd *new)
{
	t_cmd	*prv;

	prv = *lst;
	if (!(*lst))
	{
		*lst = new;
		return ;
	}
	while (prv->next)
		prv = prv->next;
	prv->next = new;
}

void	ft_lstadd_back_4(t_out **lst, t_out *new)
{
	t_out	*prv;

	prv = *lst;
	if (!(*lst))
	{
		*lst = new;
		return ;
	}
	while (prv->next)
		prv = prv->next;
	prv->next = new;
}
