/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebelkhei <ebelkhei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 15:27:39 by ebelkhei          #+#    #+#             */
/*   Updated: 2023/02/26 19:19:13 by ebelkhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_token	*ft_lstnew(void *content)
{
	t_token	*ptr;

	ptr = malloc(sizeof(t_token));
	if (!ptr)
		return (NULL);
	ptr->token = content;
	ptr->type = token_mode(content);
	ptr->next = NULL;
	return (ptr);
}

t_env	*ft_lstnew_2(void *key, void *value)
{
	t_env	*ptr;

	ptr = malloc(sizeof(t_env));
	if (!ptr)
		return (NULL);
	ptr->key = key;
	ptr->value = value;
	ptr->next = NULL;
	return (ptr);
}

t_cmd	*ft_lstnew_3(void)
{
	t_cmd	*ptr;

	ptr = malloc(sizeof(t_cmd));
	if (!ptr)
		return (NULL);
	ptr->next = NULL;
	return (ptr);
}

t_out	*ft_lstnew_4(char *out)
{
	t_out	*ptr;

	ptr = malloc(sizeof(t_out));
	if (!ptr)
		return (NULL);
	ptr->out = out;
	ptr->next = NULL;
	return (ptr);
}
