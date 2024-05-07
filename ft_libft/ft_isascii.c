/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mring <mring@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 13:45:16 by mring             #+#    #+#             */
/*   Updated: 2023/10/16 15:30:28 by mring            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int ascii)
// ASCII check ASCII 0-127
{
	if (ascii >= 0 && ascii <= 127)
		return (1);
	else
		return (0);
}
/* main for testing
#include <stdio.h>
int main()
{
    printf("ft_ascii('A'): %i\n", ft_ascii('A'));
    printf("ft_ascii('1'): %i\n", ft_ascii('1'));
    printf("ft_ascii('b'): %i\n", ft_ascii('b'));
    printf("ft_ascii('@'): %i\n", ft_ascii('@'));
    printf("ft_ascii('~'): %i\n", ft_ascii('~'));
}*/