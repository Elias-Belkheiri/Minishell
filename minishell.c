/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebelkhei <ebelkhei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 11:32:23 by ebelkhei          #+#    #+#             */
/*   Updated: 2023/03/01 11:08:10 by ebelkhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char *argv[], char *envp[])
{
	char	*line;
	t_token	*tokens;
	t_env	*environment;
	t_cmd	*cmds;

	(void)argc;
	(void)argv;
	environment = NULL;
	g_global_data.exit_status = 0;
	if (!parse_env(envp, &environment))
		write(2, "Invalid environment\n", 21);
	while (1)
	{
		tokens = NULL;
		cmds = NULL;
		line = readline(RED "minishell$ " RESET);
		add_history(line);
		if (tokenize(line, &tokens))
		{
			if (check_syntax_errors(tokens))
			{
				expansion(tokens, environment, &tokens);
				del_spaces(tokens, &tokens);
				// print_data(tokens);
				parse_cmds(&cmds, &tokens);
				print_cmd(cmds);
				clear_cmds(&cmds);
			}
			else
				ft_lstclear(&tokens);
		}
		free(line);
	}
}
