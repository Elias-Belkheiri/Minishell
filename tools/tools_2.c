/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebelkhei <ebelkhei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 16:31:56 by ebelkhei          #+#    #+#             */
/*   Updated: 2023/02/26 19:15:38 by ebelkhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	initialize_cmd(t_cmd *cmd)
{
	cmd->cmd = NULL;
	cmd->in = NULL;
	cmd->out = NULL;
	cmd->append = NULL;
	cmd->here_doc = NULL;
	cmd->pipe = 0;
}

int	is_expansion_separator(int a)
{
	if (!ft_isalnum(a) && a != '_')
		return (1);
	return (0);
}

void	print_cmd(t_cmd *command)
{
	int	i;

	i = 0;
	while (command)
	{
		printf("------------\n");
		i = -1;
		while (command->cmd && command->cmd[++i])
		{
			if (!i)
				printf("command: %s\n", command->cmd[i]);
			else
				printf("Arg: %s\n", command->cmd[i]);
		}
		printf("In: %s\n", command->in);
		i = 0;
		while (command->out)
		{
			printf("Out %d: %s\n", i++, command->out->out);
			command->out = command->out->next;
		}
		printf("Append: %s\n", command->append);
		printf("Here_doc: %s\n", command->here_doc);
		printf("Pipe: %d\n", command->pipe);
		command = command->next;
		printf("------------\n");
	}
}

void	ft_free_all_mfs(char **str)
{
	int	i;

	i = 0;
	if (str)
	{
		while (str[i])
			free(str[i++]);
		free(str);
	}
}

void	clear_cmds(t_cmd **cmds)
{
	t_cmd	*tmp;
	t_cmd	*tmp2;

	if (!cmds || !*cmds)
		return ;
	tmp = *cmds;
	while (tmp)
	{
		if (tmp->in)
			free((tmp->in));
		if (tmp->out)
			free((tmp->out));
		if (tmp->append)
			free((tmp->append));
		if (tmp->here_doc)
			free((tmp->here_doc));
		if (tmp->cmd)
			ft_free_all_mfs(tmp->cmd);
		tmp2 = tmp->next;
		free(tmp);
		tmp = tmp2;
	}
}