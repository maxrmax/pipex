/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mring <mring@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 16:04:05 by mring             #+#    #+#             */
/*   Updated: 2023/10/18 18:58:13 by mring            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*tmp;
	size_t			i;

	i = 0;
	tmp = malloc(count * size);
	if (!tmp)
		return (NULL);
	while (i < count * size)
		tmp[i++] = 0;
	return (tmp);
}

// #include <stdio.h>
// #include <stdlib.h>

// int	main(void)
// {
// 	char	*array;
// 	size_t	count;
// 	size_t	size;

// 	count = 5;
// 	size = 0;
// 	array = ft_calloc(count, size);
// 	for (size_t i = 0; i < count; i++)
// 		printf("%d", *array);
// 	printf("\n");
// 	array = calloc(count, size);
// 	for (size_t i = 0; i < count; i++)
// 		printf("%d", *array);
// 	free(array);
// }
