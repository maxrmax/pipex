/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mring <mring@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 12:40:00 by mring             #+#    #+#             */
/*   Updated: 2023/10/16 14:46:19 by mring            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int alpha)
// UPPERCASE check ASCII 65-90
	// lowercase check ASCII 97-122
		// return 0
{
	if (alpha >= 'A' && alpha <= 'Z')
		return (1);
	else if (alpha >= 'a' && alpha <= 'z')
		return (2);
	else
		return (0);
}

/*  main to test.
#include <stdio.h>
int main()
{
    printf("ft_isalpha('A'): %i\n", ft_isalpha('A'));
    printf("ft_isalpha('1'): %i\n", ft_isalpha('1'));
    printf("ft_isalpha('b'): %i\n", ft_isalpha('b'));
}
*/