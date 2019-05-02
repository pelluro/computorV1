/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipham <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 17:15:16 by mipham            #+#    #+#             */
/*   Updated: 2017/11/14 18:25:19 by mipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	if (*str == 0 && *to_find != 0)
		return (0);
	if (*to_find == 0)
		return ((char*)str);
	while (str[i] && i < len)
	{
		j = 0;
		while (str[i + j] == to_find[j] && to_find[j] != 0 && i + j < len)
			j++;
		if (to_find[j] == 0)
			return ((char*)(str + i));
		i++;
	}
	return (0);
}
