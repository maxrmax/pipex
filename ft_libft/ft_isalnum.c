/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mring <mring@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 13:45:12 by mring             #+#    #+#             */
/*   Updated: 2023/10/16 14:45:32 by mring            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int alnum)
// UPPERCASE check ASCII 65-90 - 1 if upper case
	// lowercase check ASCII 97-122 - 2 if lower case
		// digit check ASCII 48-57 - 3 if digit
			// return 0 if not alnum
{
	if (alnum >= 'A' && alnum <= 'Z')
		return (1);
	else if (alnum >= 'a' && alnum <= 'z')
		return (2);
	else if (alnum >= '0' && alnum <= '9')
		return (3);
	else
		return (0);
}
/*
#include <stdio.h>
int main()
{                   // \101 octal for A
    printf("ft_isalnum('\101'): %i\n", ft_isalnum('A'));
    printf("ft_isalnum('1'): %i\n", ft_isalnum('1'));
    printf("ft_isalnum('b'): %i\n", ft_isalnum('b'));
    printf("ft_isalnum('@'): %i\n", ft_isalnum('@'));
} */