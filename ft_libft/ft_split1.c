/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mring <mring@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 14:36:16 by mring             #+#    #+#             */
/*   Updated: 2023/11/09 20:04:21 by mring            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	wordcount(char const *s, char c)
{
	int	wordcounter;
	int	i;

	wordcounter = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			wordcounter++;
		i++;
	}
	return (wordcounter);
}

int	wordsize(char const *s, char c)
{
	int	wordsize;

	wordsize = 0;
	while (s[wordsize] != '\0' && s[wordsize] != c)
	{
		wordsize++;
	}
	return (wordsize);
}

char	**freecandy(char **result, int i)
{
	while (i >= 0)
		free(result[i--]);
	free(result);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		i;
	int		j;

	if (!s)
		return (NULL);
	result = ft_calloc(wordcount(s, c) + 1, sizeof(char *));
	if (!result)
		return (NULL);
	i = 0;
	j = 0;
	while (i < wordcount(s, c))
	{
		while (s[j] == c)
			j++;
		if (s[j] == '\0')
			break ;
		result[i] = ft_substr(s, j, wordsize(s + j, c));
		if (!result[i])
			return (freecandy(result, i));
		j += wordsize(s + j, c);
		i++;
	}
	return (result);
}

// int	main2(void)
// {
// 	char	**split;

// 	split = ft_split(" ", ' ');
// 	free(split);
// 	return 0;
// }

// int	main(void)
// {
// 	main2();
// 	system("leaks a.out");
// }

//git remote add "name" "intra link"
// git push -u "name" main