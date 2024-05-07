/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mring <mring@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 16:13:18 by mring             #+#    #+#             */
/*   Updated: 2024/03/08 13:59:45 by mring            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	src_length;

	src_length = ft_strlen(src);
	if (dstsize > src_length + 1)
	{
		ft_memcpy(dst, src, src_length + 1);
	}
	else if (dstsize != 0)
	{
		ft_memcpy(dst, src, dstsize - 1);
		dst[dstsize - 1] = 0;
	}
	return (src_length);
}

/*#include <stdio.h>

int main()
{
    char destination[16]; // Destination buffer
    const char *source = "Hello, strlcpy!";

    // Copy 'source' into 'destination' with a maximum size of 20 bytes
    size_t copied = ft_strlcpy(destination, source, sizeof(destination));

    // Check if the copy operation was successful
    if (copied >= sizeof(destination)) {
        printf("String was truncated.\n");
    } else {
        printf("Copied string: %s\n", destination);
        printf("Number of bytes copied: %zu\n", copied);
    }

    return 0;
}*/

//gcc ft_strlcpy.c ft_strlen.c ft_memcpy.c

	// size_t	srcsize;
	// size_t	i;

	// srcsize = ft_strlen(src);
	// i = 0;
	// if (dstsize > 0)
	// {
	// 	while (i < srcsize && i < dstsize - 1)
	// 	{
	// 		dst[i] = src[i];
	// 		i++;
	// 	}
	// 	dst[i] = '\0';
	// }
	// return (srcsize);