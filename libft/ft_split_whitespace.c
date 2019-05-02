/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespace.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipham <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 19:37:31 by mipham            #+#    #+#             */
/*   Updated: 2017/12/01 19:37:35 by mipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_count_words(char *str)
{
	int		i;

	i = 0;
	while (*str)
	{
		while (*str && (*str == '\t' || *str == ' ' || *str == '\n'))
			str++;
		if (*str && *str != '\t' && *str != ' ' && *str != '\n')
		{
			i++;
			while (*str && *str != '\t' && *str != ' ' && *str != '\n')
				str++;
		}
	}
	return (i);
}

char			**ft_split_whitespaces(char *str)
{
	char	**result;
	int		i;
	int		j;
	int		k;

	i = ft_count_words(str);
	if (!(result = (char **)malloc((i + 1) * sizeof(char *))))
		return (NULL);
	result[i] = NULL;
	i = 0;
	j = 0;
	k = 0;
	while (str[i])
	{
		while (str[i] && (str[i] == '\t' || str[i] == ' ' || str[i] == '\n'))
			i++;
		if (str[i] && str[i] != '\t' && str[i] != ' ' && str[i] != '\n')
		{
			j = i;
			while (str[i] && str[i] != '\t' && str[i] != ' ' && str[i] != '\n')
				i++;
			result[k++] = ft_strsub(str, j, i - j);
		}
	}
	return (result);
}
