/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mring <mring@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 17:59:41 by mring             #+#    #+#             */
/*   Updated: 2023/10/23 15:46:08 by mring            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t length)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (needle[0] == 0)
		return ((char *) haystack);
	while (haystack[i] && j < length)
	{
		while (haystack[i + j] == needle[j] \
		&& haystack[i + j] && i + j < length)
		{
			j++;
			if (needle[j] == 0)
				return ((char *) haystack + i);
		}
		i++;
		j = 0;
	}
	return (NULL);
}

// #include <stdio.h>

// int	main(void)
// {
// 	const char	*haystack = "";
// 	const char	*needle = "";
// 	char		*ptr;

// 	ptr = ft_strnstr(haystack, needle, 2);
// 	puts(ptr);
// 	ptr = strnstr(haystack, needle, 2);
// 	puts(ptr);
// }
