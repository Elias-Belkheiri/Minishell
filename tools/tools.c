/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebelkhei <ebelkhei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 13:37:04 by ebelkhei          #+#    #+#             */
/*   Updated: 2023/02/25 11:06:28 by ebelkhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	print_data(t_token *tokens)
{
    while (tokens)
    {
        printf("Content: %s\n", tokens->token);
        printf("Type: %d\n", tokens->type);
        tokens = tokens->next;
    }
}

void	print_environment(t_env *tokens)
{
    while (tokens)
    {
        printf("|%s| ", tokens->key);
        printf("|%s|\n", tokens->value);
        tokens = tokens->next;
    }
}

int ft_error(t_token **tokens)
{
    ft_lstclear(tokens);
    return (0);
}

int check_syntax_errors(t_token *token)
{
	t_token	*tmp;

	tmp = NULL;
	if (token && !token->next && (token->type == OPERATOR || token->type == PIPE))
		return (ft_putendl_fd("syntax error near unexpected token", "newline", 2));
	while (token)
	{
		if (tmp)
		{
			if ((tmp->type == OPERATOR || tmp->type == PIPE) && (token->type == OPERATOR || token->type == PIPE))
				return (ft_putendl_fd("syntax error near unexpected token", token->token, 2));
		}
		tmp = token;
		token = token->next;
	}
	if (tmp && (tmp->type == OPERATOR || tmp->type == PIPE))
		return (ft_putendl_fd("syntax error near unexpected token", "newline", 2));
	return (1);
}
