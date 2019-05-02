/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_skip_white.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipham <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 11:58:09 by mipham            #+#    #+#             */
/*   Updated: 2017/11/14 16:32:25 by mipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlen_skip_white(const char *s)
{
	size_t i;
	size_t j;

	i = 0;
	if (!s)
		return (0);
	j = ft_strlen(s) - 1;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		i++;
	if (s[i] == '\0')
		return (0);
	while (s[j] == ' ' || s[j] == '\t' || s[j] == '\n')
		j--;
	return (j - i);
}
