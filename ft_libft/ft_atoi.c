/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mring <mring@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 19:27:43 by mring             #+#    #+#             */
/*   Updated: 2023/11/09 18:05:12 by mring            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isspace(int c)
{
	if (c == 9 || c == 10 || c == 11 || c == 12 || c == 13 || c == 32)
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int	result;
	int	vorzeichen;
	int	counter;

	counter = 0;
	result = 0;
	vorzeichen = 1;
	while (ft_isspace(str[counter]))
		counter++;
	if (str[counter] == '+' && str[counter + 1] != '-')
		counter++;
	if (str[counter] == '-')
	{
		vorzeichen = -1;
		counter++;
	}
	while (str[counter] >= '0' && str[counter] <= '9')
	{
		result *= 10;
		result += str[counter] - 48;
		counter++;
	}
	result *= vorzeichen;
	return (result);
}
// #include <stdio.h>
// int	main(void)
// {
// 	char	*str;
// 	int		result;

// 	str = "  2147483648  ";
// 	result = atoi(str);
// 	printf("Before: %s, After: %i\n", str, result);
// 	result = ft_atoi(str);
// 	printf("Before: %s, After: %i\n", str, result);
// }