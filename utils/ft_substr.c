/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mring <mring@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 12:56:35 by mring             #+#    #+#             */
/*   Updated: 2024/05/06 14:46:31 by mring            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

char	*ft_substr(char const *s, int start, size_t len)
{
	char	*str2;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (start > ft_strlen(s) || start < 0)
		return (ft_strdup(""));
	if (len > ft_strlen(s) - (size_t) start)
		len = ft_strlen(s) - (size_t) start;
	str2 = ft_calloc(len + 1, sizeof(char));
	if (str2 == 0)
		return (NULL);
	while (i < len)
	{
		str2[i] = s[i + start];
		i++;
	}
	str2[i] = '\0';
	return (str2);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char	*string;
// 	char	*ptr;		

// 	string = "Nobody knows what to expect of life";
// 	ptr = ft_substr(string, -1, -1);
// 	printf("%s", ptr);
//	free(str2);
// }
