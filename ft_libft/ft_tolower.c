/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mring <mring@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 15:34:27 by mring             #+#    #+#             */
/*   Updated: 2023/10/16 15:30:36 by mring            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
		return (c + 32);
	return (c);
}

/*#include <stdio.h>

int main()
{
    char lower = 'a';
    char upper = 'F';
    int digit = 1;

    printf("original: %c\n", lower);
    printf("original: %c\n", upper);
    printf("original: %i\n", digit);
    printf("after: %c\n", ft_toupper(lower));
    printf("after: %c\n", ft_toupper(upper));
    printf("after: %i\n", ft_toupper(digit));
}*/