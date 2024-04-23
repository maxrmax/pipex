/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mring <mring@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 16:19:36 by mring             #+#    #+#             */
/*   Updated: 2023/10/24 14:46:24 by mring            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*new(const char *s1, size_t start, size_t length)
{
	char	*str;
	size_t	i;

	i = 0;
	if (length <= 0 || start >= (size_t)ft_strlen(s1))
		return (ft_strdup(""));
	str = ft_calloc(length + 1, sizeof(char));
	if (!str)
		return (NULL);
	while (i < length)
	{
		str[i] = s1[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;

	start = 0;
	if (!s1 || !set)
		return (NULL);
	end = ft_strlen(s1);
	while (ft_strchr(set, s1[start]) && s1[start] != '\0')
		start++;
	while (ft_strchr(set, s1[end]) && end > 0)
		end--;
	end++;
	return (new(s1, start, end - start));
}

// int	main(void)
// {
// 	char	*trimm;

// 	trimm = ft_strtrim("", "");
// 	printf("%s", trimm);
// }
