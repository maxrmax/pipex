/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mring <mring@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 16:13:18 by mring             #+#    #+#             */
/*   Updated: 2023/10/16 15:52:16 by mring            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* 
size_t is a datatype like int or char. its unsigned int (only positive numbers)
*/
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
/* // checking both src and dst for their length
	// if dst_length is bigger or same as dstsize -> return dstsize(20) + source length (6)
			// if src_length is smaller than dstsize - dst_length (6 < 20 - 7) do memcpy
				// dst + its own length to start at the end of it, src, src_length(6) + 1 for NUL-terminating
						// start at end of dst_length, src, 15 - 6 - 1 (8) */
{
	size_t	src_length;
	size_t	dst_length;

	dst_length = ft_strlen(dst);
	src_length = ft_strlen(src);
	if (dst_length >= dstsize)
		return (dstsize + src_length);
	if (src_length < dstsize - dst_length)
	{
		ft_memcpy(dst + dst_length, src, src_length + 1);
	}
	else
	{
		ft_memcpy(dst + dst_length, src, dstsize - dst_length - 1);
		dst[dstsize - 1] = '\0';
	}
	return (dst_length + src_length);
}

/*
// #include <string.h>
// #include <stdio.h>

// int main()
// {
//     char destination[15] = "Hello,";
//     char source[] = "World of doom";
//     size_t result = strlcat(destination, source, sizeof(destination));

//     printf("   Concatenated: %s\n", destination);
//     printf("   Result: %zu\n", result);

//     char ft_destination[15] = "Hello,";
//     char ft_source[] = "World of doom";
//     size_t ft_result = ft_strlcat\
(ft_destination, ft_source, sizeof(ft_destination));

//     printf("ft_Concatenated: %s\n", ft_destination);
//     printf("ft_Result: %zu\n", ft_result);
// }
// */