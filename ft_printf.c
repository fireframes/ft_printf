/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaksimo <mmaksimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 19:37:28 by mmaksimo          #+#    #+#             */
/*   Updated: 2024/03/04 23:48:40 by mmaksimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>


char	*ft_strchr(const char *s, int c)
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char) c)
			return ((char *) &s[i]);
		i++;
	}
	if (s[i] == (char) c)
		return ((char *) &s[i]);
	return (0);
}

int ft_printf(const char *format);//, ...);

int main(void)
{
    const char *input;
    int ft = 42;
    char ai = 'i';
    char *s = "Now";
    
    input = " The %d life %cs % %incredible! %s\n";

    printf(input, ft, ai, s);
    printf(" The %d life %cs % %incredible! %s\n", ft, ai, s);

    int argc = ft_printf(input);
    printf("Argc : %d\n", argc);
    return (0);
}

int ft_printf(const char *format)//, ...)
{
    int i;
    int argc;
    // int len_out;
    char type;
    char *set = "cspdiuxX%";

    i = 0;
    argc = 0;
    // len_out = 0;
    while (format[i] != '\0')
    {
        if (format[i] == '%')
        {
            int j = 1;
            while (format[i + j] == ' ')
                j++;
            if (ft_strchr(set, format[i + j]))
            {
                type = ft_strchr(set, format[i + j])[0];
                printf("type: %c\n", type);
                // Maybe use ft_split?? 
                // Make found types linked list? char type variable + char *fornat specifier- address
                // Or get 2 pointers = *start = % + *end = specifier
                             
                argc++;
            }
            i += j;
        }
        i++;
    }
    return (argc);
}