/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mring <mring@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 11:46:04 by mring             #+#    #+#             */
/*   Updated: 2024/02/07 16:58:27 by mring            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_format(char specifier, va_list args)
{
	int	count;

	count = 0;
	if (specifier == 'c')
		count += print_char(va_arg(args, int));
	else if (specifier == 's')
		count += print_str(va_arg(args, char *));
	else if (specifier == 'p')
		count += print_hex_ptr(va_arg(args, unsigned long), 0, 1);
	else if (specifier == 'd' || specifier == 'i')
		count += print_digit(va_arg(args, int));
	else if (specifier == 'u')
		count += print_digit(va_arg(args, unsigned int));
	else if (specifier == 'x')
		count += print_hex_ptr(va_arg(args, unsigned int), 0, 0);
	else if (specifier == 'X')
		count += print_hex_ptr(va_arg(args, unsigned int), 1, 0);
	else
		count += print_char(specifier);
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		result;
	int		i;

	va_start(args, str);
	i = 0;
	result = 0;
	while (str[i])
	{
		if (str[i] == '%')
			result += print_format(str[i++ + 1], args);
		else
			result += print_char(str[i]);
		if (result == -1)
		{
			va_end(args);
			return (-1);
		}
		i++;
	}
	va_end(args);
	return (result);
}

// #include <stdio.h>
// int	main(void)
// {
	// int		value = 42;
	// void	*ptr = &value;

	// ft_printf("ft_printf\n");
	// ft_printf("char: %c\n", 'c');
	// ft_printf("string: %s \n", "string");
	// ft_printf("pointer address: %p\n", ptr);
	// ft_printf("decimal: %d\n", -21474836481);
	// ft_printf("int: %i\n", -220);
	// ft_printf("unsigned int: %u\n", 33333333);
	// ft_printf("hex: %x\n", 30);
	// ft_printf("HEX: %X\n", 31);
	// ft_printf("%x\n", -10);
	//ft_printf("%%: %%\n\n");

	// printf("printf\n");
	// printf("char: %c\n", 'c');
	// printf("string: %s \n", "string");
	// printf("pointer address: %p\n", ptr);
	// printf("decimal: %d\n", -21474836481);
	// printf("int: %i\n", -220);
	// printf("unsigned int: %u\n", 33333333);
	// printf("hex: %x\n", 30);
	// printf("HEX: %X\n", 31);
	// printf("%x\n", -10);
	//printf("%%: %%\n\n");
// }