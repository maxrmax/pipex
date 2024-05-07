/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mring <mring@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 15:39:20 by mring             #+#    #+#             */
/*   Updated: 2023/10/26 22:31:51 by mring            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_digits(long n)
{
	int		i;

	i = 1;
	if (n < 0)
	{
		n = -n;
		i++;
	}
	while (n >= 10)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*result;
	long	nr;
	int		i;

	nr = n;
	result = ft_calloc(count_digits(nr) + 1, sizeof(char));
	if (!result)
		return (NULL);
	if (nr < 0)
	{
		nr = -nr;
	}
	i = count_digits(n);
	while (i > 0)
	{
		result[i - 1] = (nr % 10) + '0';
		nr = nr / 10;
		i--;
	}
	if (n < 0)
		result[0] = '-';
	result[count_digits(n)] = '\0';
	return (result);
}

// int	main(void)
// {
// 	int		inter;
// 	char	*string;

// 	inter = -0;
// 	string = ft_itoa(inter);
// 	if (string[0] == 0)
// 		printf("string is NULL");
// 	else
// 		printf("string:%s", string);
// 	free(string);
// }
