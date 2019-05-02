/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipham <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 16:04:39 by mipham            #+#    #+#             */
/*   Updated: 2017/12/13 16:06:12 by mipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_check_in_base(char *base, char c)
{
	int i;

	i = 0;
	if (c < 32)
		return (0);
	while (base[i])
	{
		if (base[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int		ft_check_base(char *str)
{
	int i;
	int y;

	i = 1;
	y = 0;
	if (str[0] == 0 || str[1] == 0)
		return (0);
	while (str[y])
	{
		if (str[y] == '+' || str[y] == '-' || str[y] < ' ')
			return (0);
		i = y + 1;
		while (str[i])
		{
			if (str[i] == str[y])
				return (0);
			i++;
		}
		y++;
	}
	return (y);
}

void	ft_check_str(char *str, char *base, int tab[])
{
	tab[0] = 0;
	tab[1] = 0;
	tab[2] = 1;
	tab[3] = 0;
	if (str[0] == 0)
		tab[2] = 0;
	if (str[0] == '+')
	{
		tab[0]++;
		tab[1] = 1;
	}
	else if (str[tab[0]] == '-')
	{
		tab[3] = 1;
		tab[1] = 1;
		tab[0]++;
	}
	while (str[tab[0]])
	{
		if (!(ft_check_in_base(base, str[tab[0]])))
			tab[2] = 0;
		tab[0]++;
		if (str[tab[0]] == '+' || str[tab[0]] == '-')
			break ;
	}
}

int		get_index_into_str(char *str, char c)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (0);
}

int		ft_atoi_base(char *str, char *base)
{
	int tab[4];
	int nb;
	int i;
	int t_base;

	nb = 0;
	t_base = 0;
	if (!(ft_check_base(base)))
		return (0);
	ft_check_str(str, base, tab);
	if (!(tab[2]))
		return (0);
	while (base[t_base])
		t_base++;
	i = tab[1];
	while (str[i] && str[i] != '+' && str[i] != '-')
	{
		nb = (nb * t_base) + (get_index_into_str(base, str[i]));
		i++;
	}
	if (tab[3])
		nb = -nb;
	return (nb);
}
