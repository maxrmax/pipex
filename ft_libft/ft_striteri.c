/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mring <mring@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 16:26:26 by mring             #+#    #+#             */
/*   Updated: 2023/10/30 17:40:55 by mring            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int		i;

	i = 0;
	while (s[i])
	{
		f(i, s + i);
		i++;
	}
}

// char	functionname(unsigned int x, char c)
// {
// 	(void) x;
// 	(void) c;
// 	return ('g');
// }

// int	main(void)
// {
// 	char *s = ft_strieteri("some string", functionname);
// 	printf("s: %s\n", s);
// }

// // for every char in a string call f, return value of that into a new string