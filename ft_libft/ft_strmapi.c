/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mring <mring@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 16:26:26 by mring             #+#    #+#             */
/*   Updated: 2023/10/30 17:24:15 by mring            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*result;
	int		i;

	result = ft_strdup(s);
	if (result == NULL)
		return (NULL);
	i = 0;
	while (result[i])
	{
		result[i] = f(i, result[i]);
		i++;
	}
	return (result);
}

// char	functionname(unsigned int x, char c)
// {
// 	(void) x;
// 	(void) c;
// 	return ('g');
// }

// int	main(void)
// {
// 	char *s = ft_strmapi("some string", functionname);
// 	printf("s: %s\n", s);
// }

// // for every char in a string call f, return value of that into a new string