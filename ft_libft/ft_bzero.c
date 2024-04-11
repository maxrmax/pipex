/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mring <mring@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 19:21:33 by mring             #+#    #+#             */
/*   Updated: 2023/10/16 14:57:50 by mring            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t len)
{
	char	*p;
	size_t	i;

	p = s;
	i = 0;
	while (i < len)
	{
		p[i] = '\0';
		i++;
	}
}
/* 
#include <stdio.h>

int	main(void)
{
	char	str[] = "Test string for memset.$#@!@#$";
	char	*ptr;

	ptr = str;
	printf("before: %s\n", str);
	ft_bzero(ptr, 5);
	printf(" after: %s\n", str);
}
 */