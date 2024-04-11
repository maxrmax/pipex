/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mring <mring@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 15:46:16 by mring             #+#    #+#             */
/*   Updated: 2023/10/23 15:34:43 by mring            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*result;
	char	cc;
	int		i;

	cc = (char) c;
	i = 0;
	result = NULL;
	while (s[i] != '\0')
	{
		if (s[i] == cc)
		{
			result = ((char *) &s[i]);
		}
		i++;
	}
	if (s[i] == cc)
		result = ((char *) &s[i]);
	return (result);
}

// #include <stdio.h>

// int	main(void)
// {
// 	const char	*str = "The lack of brainsoup is astonishing!";
// 	char		searchfor;
// 	char		*foundat;

// 	searchfor = 'l';
// 	// foundat = ft_strrchr(str, searchfor);
// 	foundat = ft_strrchr(str, 1024 + 'e');
// 	printf("%c, %ld\n", *foundat, foundat - str);
// 	if (foundat != NULL)
// 	{
// 		printf("Character '%c' at position: %s\n", searchfor, foundat);
// 	}
// 	else
// 	{
// 		printf("Character '%c' not found in the string.\n", searchfor);
// 	}
// }
