/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mring <mring@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 16:52:51 by mring             #+#    #+#             */
/*   Updated: 2023/10/18 20:12:11 by mring            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dst;
	size_t	i;

	i = 0;
	dst = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!dst)
		return (NULL);
	ft_strlcpy(dst, s1, (sizeof(char) * (ft_strlen(s1) + 1)));
	return (dst);
}

// #include <stdlib.h>

// int	main(void)
// {
// 	char	*str;
// 	char	*strcpy;

// 	str = "this is my testestestestets11";
// 	printf("       str: %s\n", str);
// 	printf("ft     str: %s\n", str);
// 	strcpy = strdup(str);
// 	printf("    strcpy: %s\n", strcpy);
// 	strcpy = ft_strdup(str);
// 	printf("ft  strcpy: %s\n", strcpy);
// }
