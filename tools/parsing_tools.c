/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebelkhei <ebelkhei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 16:35:45 by ebelkhei          #+#    #+#             */
/*   Updated: 2023/03/01 15:30:52 by ebelkhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	set_operator(t_token *token, t_redirection **redirection, int type)
{
	if (token->next)
		ft_lstadd_back_4(redirection, ft_lstnew_4(ft_strdup(token->next->token), type));
}

void	is_operator(t_token *token, t_cmd *cmd)
{
	if (!ft_strcmp(token->token, "<<"))
		set_operator(token, &cmd->in, HERE_DOC);
	else if (*(token->token) == '<')
		set_operator(token, &cmd->in, IN);
	else if (!ft_strcmp(token->token, ">>"))
		set_operator(token, &cmd->out, APPEND);
	else if (*(token->token) == '>')
		set_operator(token, &cmd->out, OUT);
}

void	hyphen_expansion(t_token *token, t_env *env)
{
	char *tmp;

	if (token)
	{
		tmp = token->token;
		token->token = get_expansion(env, ft_strdup("HOME"));
		free(tmp);
	}
}

void	initialize_args(t_token *token, t_cmd *command)
{
	int	i;

	i = 0;
	while (token && token->type != PIPE)
	{
		if (token->type == WORD || token->type == DOUBLE
		|| token->type == SINGLE || token->type == HYPHEN)
			i++;
		token = token->next;
	}
	if (!i++)
		return ;
	command->cmd = malloc(i * sizeof(char *));
	if (!command->cmd)
		return ;
	command->cmd[--i] = NULL;
}
