/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaksimo <mmaksimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 13:42:21 by mmaksimo          #+#    #+#             */
/*   Updated: 2024/03/05 23:01:22 by mmaksimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include <stdint.h>
# include <limits.h>
# include <unistd.h>

char	*ft_strchr(const char *s, int c);
int		ft_putchar_fd(char c, int fd);
int		ft_putstr_fd(char *s, int fd);
int		ft_putnbr_fd(int n, int fd);
int		ft_putnbr_base_fd(long int nbr, char *base, int fd);
int		ft_putnbr_uint_fd(unsigned int n, int fd);
int		ft_putaddr_fd(void *ptr, int fd);
int		ft_printf(const char *format, ...);

#endif
