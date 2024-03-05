/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaksimo <mmaksimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 13:23:18 by mmaksimo          #+#    #+#             */
/*   Updated: 2024/03/05 22:59:32 by mmaksimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "libftprintf.h"

int main(void)
{
	// const char *input;
	int 			ft = 42243;
	unsigned int	max = UINT_MAX;
	int diff = 0;
	char ch = 'i';
	char *s = "Now";
	// char *s2 = "Wow";

	// input = "%s The %d life %cs %%incredible! %s\n";
	// input = "\0";


	// printf(" The %d life %cs % %incredible! %s\n", ft, ai, s);
	int char_cnt = ft_printf("%p, %x, %c, %s, %%, %u\n", s, ft, diff, &ch, max);
	int check_org = printf("%p, %x, %c, %s, %%, %u\n", s, ft, diff, &ch, max);

	printf("custom work  : %d\n", char_cnt);
	printf("original work: %d\n", check_org);

	return (0);
}

// NOT WORKING WITH NEGATIVE HEX

// putnbr functions are too big


/*

ft_putnbr_fd.c: Error!
Error: TOO_MANY_LINES       (line:  74, col:   1):      Function has more than 25 lines
ft_putstr_fd.c: Error!
Error: SPACE_REPLACE_TAB    (line:  17, col:   9):      Found space when expecting tab
Error: EMPTY_LINE_FUNCTION  (line:  22, col:   1):      Empty line in function
ft_strchr.c: OK!
libftprintf.h: Error!
Error: MISSING_IDENTIFIER   (line:  28, col:  29):      missing type qualifier or identifier in function arguments
ft_putchar_fd.c: OK!
ft_putnbr_uint_fd.c: OK!
ft_putnbr_base_fd.c: OK!
ft_putaddr_fd.c: Error!
Error: SPACE_REPLACE_TAB    (line:  44, col:  14):      Found space when expecting tab
Error: MISALIGNED_VAR_DECL  (line:  44, col:  15):      Misaligned variable declaration
*/
