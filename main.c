/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaksimo <mmaksimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 13:23:18 by mmaksimo          #+#    #+#             */
/*   Updated: 2024/03/07 18:47:13 by mmaksimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include "ft_printf.h"

int main(void)
{
	// int ft = INT_MAX;
	// unsigned int	max = UINT_MAX;
	// int diff = 0;
	// char ch = 'i';
	// char *s = "Now";
	// char *s2 = "Wow";

	// input = "%s The %d life %cs %%incredible! %s\n";
	// input = "\0";

// //
	// int char_cnt = ft_printf(" NULL %s NULL ", NULL);
	// int check_org = printf(" NULL %s NULL ", NULL);
	int char_cnt = ft_printf("%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%", 'A', "42", 42, 42 ,42 , 42, 42, 'B', "-42", -42, -42 ,-42 ,-42, 42, 'C', "0", 0, 0 ,0 ,0, 42, 0);
	printf("\n");
	int check_org = printf("%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%", 'A', "42", 42, 42 ,42 , 42, 42, 'B', "-42", -42, -42 ,-42 ,-42, 42, 'C', "0", 0, 0 ,0 ,0, 42, 0);
	printf("\n");
	printf("custom work  : %d\n", char_cnt);
	printf("original work: %d\n", check_org);

	return (0);
}
// #include <stdio.h>

// int main() {
//     unsigned int hexadecimal_number = 0x7fffffd6; // Given hexadecimal number
//     int twos_complement;

//     // Reinterpret the hexadecimal number as a signed integer
//     twos_complement = (int)(signed char)hexadecimal_number;

//     printf("Original hexadecimal number: %x\n", hexadecimal_number);
//     printf("2's complement representation: %x\n", twos_complement);

//     return 0;
// }
