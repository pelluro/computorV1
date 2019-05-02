/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipham <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 16:35:12 by mipham            #+#    #+#             */
/*   Updated: 2017/11/16 17:24:51 by mipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int		i;
	long	result;
	int		signe;

	i = 0;
	result = 0;
	signe = 1;
	while (str[i] == '\t' || str[i] == '\v' || str[i] == '\n' || str[i] == ' '
				|| str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-')
		signe = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] <= '9' && str[i] >= '0')
	{
		result = result * 10 + (str[i] - 48);
		i++;
	}
	result = result * signe;
	if (result < -2147483648 || result > 2147483647)
		return (0);
	return ((int)result);
}
