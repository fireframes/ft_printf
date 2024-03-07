/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putdec_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaksimo <mmaksimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 20:20:13 by mmaksimo          #+#    #+#             */
/*   Updated: 2024/03/07 15:15:29 by mmaksimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_dec(int nbr, char *base, char *num_arr, int fd)
{
	int	i;
	int	len;

	i = 0;
	while (nbr)
	{
		num_arr[i] = base[nbr % 10];
		nbr /= 10;
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

int	ft_putdec_fd(int nbr, char *base, int fd)
{
	char	num_arr[64];
	int		cnt;

	cnt = 0;
	if (nbr == 0 || nbr == INT_MIN)
	{
		if (nbr == 0)
			write(fd, "0", 1);
		else if (nbr == INT_MIN)
		{
			write(fd, "-2147483648", 11);
			cnt = 10;
		}
		return (cnt + 1);
	}
	else if (nbr < 0)
	{
		nbr *= -1;
		write(fd, "-", 1);
		cnt++;
	}
	cnt += print_dec(nbr, base, num_arr, fd);
	return (cnt);
}
