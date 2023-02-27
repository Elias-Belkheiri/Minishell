/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebelkhei <ebelkhei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 16:35:45 by ebelkhei          #+#    #+#             */
/*   Updated: 2023/02/26 19:17:39 by ebelkhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	set_operator(t_token *token, char **cmd, t_out **out)
{
	if (!out && token->next && token->next->token)
		*cmd = ft_strdup(token->next->token);
	else if (out && token->next && token->next->token)
		ft_lstadd_back_4(out, ft_lstnew_4(ft_strdup(token->next->token)));
}

void	is_operator(t_token *token, t_cmd *cmd)
{
	if (!ft_strcmp(token->token, "<<"))
		set_operator(token, &cmd->here_doc, NULL);
	else if (!ft_strcmp(token->token, ">>"))
		set_operator(token, &cmd->append, NULL);
	else if (*(token->token) == '<')
		set_operator(token, &cmd->in, NULL);
	else if (*(token->token) == '>')
		set_operator(token, NULL, &cmd->out);
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
