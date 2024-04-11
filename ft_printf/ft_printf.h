/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mring <mring@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 13:22:13 by mring             #+#    #+#             */
/*   Updated: 2024/02/07 16:43:48 by mring            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	print_char(int c);
int	print_str(char *str);
int	print_hex_ptr(unsigned long number, int hex, int ptr);
int	print_digit(long number);
int	print_format(char specifier, va_list args);
int	ft_printf(const char *str, ...);

#endif