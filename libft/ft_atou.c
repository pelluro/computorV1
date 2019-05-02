/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atou.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipham <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 16:35:12 by mipham            #+#    #+#             */
/*   Updated: 2017/11/16 17:24:51 by mipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned long long	ft_atou(const char *str)
{
	unsigned long long	nb;
	unsigned long long	tmp;

	nb = 0;
	tmp = 0;
	while (ft_isspace((int)*str))
		str++;
	if (*str == '+')
		str++;
	while (ft_isdigit((int)*str))
	{
		tmp = tmp * 10 + *str - '0';
		str++;
		if (tmp < nb)
			return (0);
		nb = tmp;
	}
	return (nb);
}
