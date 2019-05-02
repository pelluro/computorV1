/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrbase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipham <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 16:07:24 by mipham            #+#    #+#             */
/*   Updated: 2017/12/13 16:07:32 by mipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	ft_putnbrbase(uintmax_t nbr, char *base)
{
	ft_putnbrbase_fd(nbr, base, STDOUT_FILENO);
}
