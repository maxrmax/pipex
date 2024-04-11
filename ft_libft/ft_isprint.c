/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mring <mring@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 17:59:40 by mring             #+#    #+#             */
/*   Updated: 2023/10/16 14:47:32 by mring            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isprint(int c)
// ascii 32 - 126 are printable characters
// ascii 0 - 31 + 127 are control characters
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}
/*#include <stdio.h>
int main()
{
    printf("(' '): %i\n", ft_isprint(' '));
    printf("('A'): %i\n", ft_isprint('A'));
    printf("('1'): %i\n", ft_isprint('1'));
    printf("('/n'): %i\n", ft_isprint('\n'));
    printf("('@'): %i\n", ft_isprint('@'));
}*/