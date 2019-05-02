/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipham <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 16:10:45 by mipham            #+#    #+#             */
/*   Updated: 2017/11/14 18:24:19 by mipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *to_find)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (*str == 0 && *to_find != 0)
		return (0);
	if (*to_find == 0)
		return ((char*)str);
	while (str[i])
	{
		j = 0;
		while (str[i + j] == to_find[j] && to_find[j] != 0)
			j++;
		if (to_find[j] == 0)
			return ((char *)(str + i));
		i++;
	}
	return (0);
}
