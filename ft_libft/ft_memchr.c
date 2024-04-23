/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mring <mring@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 18:55:30 by mring             #+#    #+#             */
/*   Updated: 2023/10/16 17:28:34 by mring            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
// strmp   = pointer to string
// inttemp = byte to search for
{
	unsigned char	*strtemp;
	unsigned char	inttemp;
	size_t			counter;

	strtemp = (unsigned char *) str;
	inttemp = (unsigned char) c;
	counter = 0;
	while (counter < n)
	{
		if (strtemp[counter] == inttemp)
			return ((void *)&strtemp[counter]);
		counter++;
	}
	return (NULL);
}
/* #include <stdio.h>
#include <string.h>

int main()
{
    const char *str = "idk yet but here i go";
    int searchingthis = 'h';
    size_t str_length = ft_strlen(str);

    void *result = memchr(str, searchingthis, str_length);
    void *ft_result = ft_memchr(str, searchingthis, str_length);

    if (ft_result != NULL)
    {
        printf("Character found at position: %li\n", (char *)result - str);
        printf("Character found at position: %li\n", (char *)ft_result - str);
    }
    else
    {
        printf("Character not found.\n");
    }
} */