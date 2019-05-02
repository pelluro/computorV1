/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipham <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 16:54:45 by mipham            #+#    #+#             */
/*   Updated: 2017/11/14 16:30:59 by mipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s)
{
	int			i;
	int			j;
	size_t		size;
	char		*dest;

	i = 0;
	j = 0;
	size = ft_strlen_skip_white(s) + 1;
	if (!s || !(dest = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		i++;
	while (size--)
	{
		dest[j] = s[i + j];
		j++;
	}
	dest[j] = '\0';
	return (dest);
}
