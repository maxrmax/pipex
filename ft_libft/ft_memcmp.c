/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mring <mring@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 15:38:23 by mring             #+#    #+#             */
/*   Updated: 2023/10/16 20:26:13 by mring            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	unsigned char	*stri1;
	unsigned char	*stri2;
	size_t			counter;

	stri1 = (unsigned char *) str1;
	stri2 = (unsigned char *) str2;
	counter = 0;
	while (counter < n)
	{
		if (stri1[counter] > stri2[counter] || stri1[counter] < stri2[counter])
			return (stri1[counter] - stri2[counter]);
		counter++;
	}
	return (0);
}

/* #include <stdio.h>
int main()
{
    const char *str1 = "idk yet but here  go";
    const char *str2 = "idk yet but here i go";
    size_t str_length = ft_strlen(str1);

    int result = memcmp(str1, str2, str_length);
    int ft_result = ft_memcmp(str1, str2, str_length);

    printf("original: %i\n", result);
    printf("resultft: %i\n", ft_result);
} */