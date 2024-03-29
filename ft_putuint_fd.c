/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuint_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaksimo <mmaksimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 20:20:13 by mmaksimo          #+#    #+#             */
/*   Updated: 2024/03/07 14:59:35 by mmaksimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	count_pow(unsigned int num)
{
	int		pow;

	pow = 0;
	while (num)
	{
		num /= 10;
		pow++;
	}
	pow--;
	return (pow);
}

static unsigned int	rec_pow(unsigned int base, int power)
{
	if (power == 0)
		return (1);
	else
		return (rec_pow(base, power - 1) * base);
}

int	ft_putuint_fd(unsigned int nbr, int fd)
{
	char	c;
	int		pow;
	int		cnt;

	cnt = 0;
	if (nbr == 0)
	{
		write(fd, "0", 1);
		return (1);
	}
	pow = count_pow(nbr);
	cnt += pow + 1;
	while (pow + 1)
	{
		c = nbr / rec_pow(10, pow) + 48;
		write(fd, &c, 1);
		nbr %= rec_pow(10, pow);
		pow--;
	}
	return (cnt);
}
