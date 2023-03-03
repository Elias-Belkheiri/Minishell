/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebelkhei <ebelkhei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 15:27:19 by ebelkhei          #+#    #+#             */
/*   Updated: 2023/03/02 18:51:29 by ebelkhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_lstdelone(t_token *lst)
{
	if (lst)
	{
		if (lst->content)
			free(lst->content);
		free(lst);
	}
}

void	ft_lstdelone_2(t_redirection *lst)
{
	if (lst)
	{
		if (lst->redirection)
			free(lst->redirection);
		free(lst);
	}
}
