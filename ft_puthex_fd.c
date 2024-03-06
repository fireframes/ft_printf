/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaksimo <mmaksimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 11:50:45 by mmaksimo          #+#    #+#             */
/*   Updated: 2024/03/06 23:00:38 by mmaksimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	print_hex(int nbr, char *base, char *num_arr, int fd)
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
    unsigned int tws_cmpl;

	cnt = 0;
	if (nbr == -2147483648)
	{
		ft_puthex_fd(-(nbr / 16), base, fd);
		cnt = ft_puthex_fd(-(nbr % 16), base, fd);
		return (cnt + 1);
	}
	else if (nbr < 0)
	{
        // int num_bits = sizeof(int) * 8;
      	// mask = ~((unsigned int)0 << 1);
        // mask = mask << (num_bits - 1);
        tws_cmpl = (unsigned int) nbr;

		printf("\n-- %u --\n", tws_cmpl);

		cnt += print_hex(tws_cmpl, base, num_arr, fd);

	}
	else if (nbr == 0)
	{
		write(fd, "0", 1);
		return (1);
	}
	else
		cnt += print_hex(nbr, base, num_arr, fd);
	return (cnt);
}
