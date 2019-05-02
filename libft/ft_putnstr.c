/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mipham <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 16:09:09 by mipham            #+#    #+#             */
/*   Updated: 2017/12/13 16:09:14 by mipham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <unistd.h>
#include "libft.h"

void	ft_putnstr(char const *str, size_t str_len)
{
	ft_putnstr_fd(str, str_len, STDOUT_FILENO);
}
