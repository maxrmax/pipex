/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mring <mring@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 23:02:47 by mring             #+#    #+#             */
/*   Updated: 2023/10/16 19:38:50 by mring            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	char	*temp_src;
	char	*temp_dst;
	size_t	i;

	temp_src = (char *) src;
	temp_dst = (char *) dst;
	i = 0;
	if (dst == NULL && src == NULL)
		return (NULL);
	if (temp_dst > temp_src)
		while (n-- > 0)
			temp_dst[n] = temp_src[n];
	else
	{
		while (i < n)
		{
			temp_dst[i] = temp_src[i];
			i++;
		}
	}
	return (dst);
}

// declare 2 temporary pointer for src and dst
// declare a counter
// check if both src and dst are NULL
// make dst tmp pointer equal to dst converted to char *
// make src tmp pointer equal to src converted to char *
// if src and dst are overlapping
//     loop while len is greater than 0 and copy src into dst
// if src and dst are not overlapping
//     loop while our counter is less than len and copy src into dst
// return dst