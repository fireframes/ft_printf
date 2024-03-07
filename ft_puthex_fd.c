/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaksimo <mmaksimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 11:50:45 by mmaksimo          #+#    #+#             */
/*   Updated: 2024/03/07 14:39:54 by mmaksimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_hex(unsigned int nbr, char *base, char *num_arr, int fd)
{
	int	i;
	int	len;

	i = 0;
	while (nbr)
	{
		num_arr[i] = base[nbr % 16];
		nbr /= 16;
		i++;
	}
	num_arr[i] = '\0';
	len = i;
	i = 0;
	while (i < len)
	{
		write(fd, &num_arr[len - i - 1], 1);
		i++;
	}
	return (i);
}

int	ft_puthex_fd(int nbr, char *base, int fd)
{
	char	num_arr[64];
	int		cnt;

	cnt = 0;
	if (nbr == 0)
	{
		write(fd, "0", 1);
		return (1);
	}
	cnt += print_hex((unsigned int) nbr, base, num_arr, fd);
	return (cnt);
}
