/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebelkhei <ebelkhei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 21:02:19 by ebelkhei          #+#    #+#             */
/*   Updated: 2023/02/24 12:04:10 by ebelkhei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	ft_check(char *trim, char a)
{
	while (*trim)
	{
		if (*trim == a)
			return (1);
		trim++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		len;
	char	*str;
	char	*s;
	int		j;

	str = (char *)s1;
	s = (char *)set;
	i = 0;
	j = 0;
	if (!str || ft_strlen(str) == 2)
		return (ft_strdup(""));
	while (s && str[i] && ft_check(s, str[i]))
		i++;
	len = ft_strlen(str) - 1;
	while (s && str[len] && ft_check(s, str[len]))
	{
		len--;
		j++;
	}
	return (ft_substr(str, i, ft_strlen(str) - j - i));
}
