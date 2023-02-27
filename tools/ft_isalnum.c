/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebelkhei <ebelkhei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 14:44:24 by ebelkhei          #+#    #+#             */
/*   Updated: 2023/02/24 18:55:54 by ebelkhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_isalpha(int argument)
{
	if ((argument >= 'a' && argument <= 'z'))
		return (1);
	if ((argument >= 'A' && argument <= 'Z'))
		return (1);
	return (0);
}

int	ft_isdigit(int arg)
{
	if (arg >= '0' && arg <= '9')
		return (1);
	return (0);
}

int	ft_isalnum(int argument)
{
	if (ft_isdigit(argument) || ft_isalpha(argument))
		return (1);
	return (0);
}
