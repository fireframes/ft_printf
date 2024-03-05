/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaksimo <mmaksimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 11:50:45 by mmaksimo          #+#    #+#             */
/*   Updated: 2024/03/05 22:04:16 by mmaksimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	get_radix(char *base)
{
	char	*base0;

	base0 = base;
	while (*base)
		base++;
	return (base - base0);
}

int	checker(char *cpy_base, char curr_char)
{
	int	unique_count;

	unique_count = 0;
	while (*cpy_base)
	{
		if (*cpy_base == curr_char)
			unique_count++;
		cpy_base++;
	}
	if (unique_count > 1)
		return (0);
	else
		return (1);
}

int	check_base(char *base)
{
	char	*cpy_base;

	cpy_base = base;
	if (get_radix(base) == 0 || get_radix(base) == 1)
		return (0);
	while (*base)
	{
		if (!((*base >= 48 && *base <= 57) || (*base >= 65 && *base <= 90)
				|| (*base >= 97 && *base <= 122)))
			return (0);
		if (!checker(cpy_base, *base) || *base == '+' || *base == '-'
			|| *base == ' ' || *base == '\0')
			return (0);
		base++;
	}
	return (1);
}

int	print_nbr(long int nbr, char *base, char *num_arr, int fd)
{
	int	i;
	int	len;
	int	radix;

	i = 0;
	radix = get_radix(base);
	while (nbr)
	{
		num_arr[i] = base[nbr % radix];
		nbr /= radix;
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

int	ft_putnbr_base_fd(long int nbr, char *base, int fd)
{
	char	num_arr[128];
	int		cnt;

	cnt = 0;
	if (nbr == -2147483648)
	{
		write(fd, "-", 1);
		ft_putnbr_base_fd(-(nbr / get_radix(base)), base, fd);
		cnt = ft_putnbr_base_fd(-(nbr % get_radix(base)), base, fd);
		return (cnt + 1);
	}
	else if (nbr < 0 && check_base(base))
	{
		nbr *= -1;
		write(fd, "-", 1);
		cnt++;
	}
	else if (nbr == 0)
	{
		write(fd, "0", 1);
		return (1);
	}
	if (check_base(base))
		cnt += print_nbr(nbr, base, num_arr, fd);
	return (cnt);
}
