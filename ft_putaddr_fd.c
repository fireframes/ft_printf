/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddr_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaksimo <mmaksimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 21:50:39 by mmaksimo          #+#    #+#             */
/*   Updated: 2024/03/05 22:09:34 by mmaksimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_addr(uintptr_t addr, char *base, char *num_arr, int fd)
{
	int	i;
	int	len;

	write(fd, "0x", 2);
	i = 0;
	while (addr)
	{
		num_arr[i] = base[addr % 16];
		addr /= 16;
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
	return (i + 2);
}

int	ft_putaddr_fd(void *ptr, int fd)
{
	char		num_arr[64];
	int			cnt;
	char		*base;
	uintptr_t	addr;

	if (ptr == NULL)
	{
		write(fd, "(nil)", 5);
		return (5);
	}
	addr = (uintptr_t) ptr;
	base = "0123456789abcdef";
	cnt = 0;
	cnt += print_addr(addr, base, num_arr, fd);
	return (cnt);
}
