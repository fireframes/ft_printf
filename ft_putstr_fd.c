/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaksimo <mmaksimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 19:37:11 by mmaksimo          #+#    #+#             */
/*   Updated: 2024/03/07 15:15:59 by mmaksimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr_fd(char *s, int fd)
{
	char	*s0;

	if (s == NULL)
	{
		write(fd, "(null)", 6);
		return (6);
	}
	s0 = s;
	while (*s)
		write(fd, s++, 1);
	return (s - s0);
}
