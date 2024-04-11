/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mring <mring@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 21:46:45 by mring             #+#    #+#             */
/*   Updated: 2023/10/16 15:55:08 by mring            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//test with restrict removed
void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*temp_dst;
	const unsigned char	*temp_src;

	i = 0;
	temp_dst = (unsigned char *)dst;
	temp_src = (const unsigned char *)src;
	if (dst == (void *)0 && src == (void *)0)
		return (dst);
	while (i < n)
	{
		temp_dst[i] = temp_src[i];
		i++;
	}
	return (dst);
}
// #include <stdio.h>
// int main(void)
// {
// 	char	or_src[3] = "\0";
// 	char	or_dst[20];
// 	char	ft_src[3] = "\0";
// 	char	ft_dst[20];

// 	printf("src original before: %p\n", or_src);
// 	printf("dst original before: %p\n", or_dst);
// 	printf(" src ft before: %p\n", ft_src);
// 	printf(" dst ft before: %p\n", ft_dst);
// 	ft_memcpy(ft_dst, ft_src, ft_strlen(ft_src) + 1); // +1 to include the \0
// 	memcpy(or_dst, or_src, strlen(or_src) + 1); // +1 to include the \0
// 	printf("src original  after: %p\n", or_src);
// 	printf("dst original  after: %p\n", or_dst);
// 	printf(" src ft  after: %p\n", ft_src);
// 	printf(" dst ft  after: %p\n", ft_dst);
// }
