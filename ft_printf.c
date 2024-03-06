/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaksimo <mmaksimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 19:37:28 by mmaksimo          #+#    #+#             */
/*   Updated: 2024/03/06 16:58:50 by mmaksimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_spec_type(char type, va_list *args)
{
	int	ch_out;

	ch_out = 0;
	if (type == 'c')
		ch_out = ft_putchar_fd(va_arg(*args, int), 1);
	else if (type == 's')
		ch_out = ft_putstr_fd(va_arg(*args, char *), 1);
	else if (type == 'p')
		ch_out = ft_putaddr_fd(va_arg(*args, void *), 1);
	else if (type == 'd')
		ch_out = ft_putnbr_fd(va_arg(*args, int), 1);
	else if (type == 'i')
		ch_out = ft_putnbr_fd(va_arg(*args, int), 1);
	else if (type == 'u')
		ch_out = ft_putuint_fd(va_arg(*args, unsigned int), 1);
	else if (type == 'x')
		ch_out = ft_puthex_fd(va_arg(*args, int), "0123456789abcdef", 1);
	else if (type == 'X')
		ch_out = ft_puthex_fd(va_arg(*args, int), "0123456789ABCDEF", 1);
	else if (type == '%')
		ch_out = ft_putchar_fd('%', 1);
	return (ch_out);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	char	*set;
	char	type;
	int		ch_out;
	int		i;

	set = "cspdiuxX%";
	va_start(args, format);
	i = 0;
	ch_out = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%' && ft_strchr(set, format[i + 1]))
		{
			i++;
			type = ft_strchr(set, format[i])[0];
			ch_out += print_spec_type(type, &args);
		}
		else
			ch_out += ft_putchar_fd(format[i], 1);
		i++;
	}
	va_end(args);
	return (ch_out);
}
