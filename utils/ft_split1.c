/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mring <mring@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 14:36:16 by mring             #+#    #+#             */
/*   Updated: 2024/05/06 19:14:35 by mring            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_libft/libft.h"

int	wordcount(char const *s, char c)
{
	int	wordcounter;
	int	i;
	int	qflag;

	wordcounter = 0;
	i = 0;
	qflag = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '\'' && qflag == 0)
		{
			qflag = 1;
			i++;
		}
		if (s[i] == '\'' && qflag == 1)
		{
			qflag = 0;
		}
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0') && qflag == 0)
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
	int		start;

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
		if (s[j] == '\'')
		{
			start = j + 1;
			j++;
			while (s[j] != '\'' && s[j] != '\0')
				j++;
			result[i] = ft_substr(s, start, j - start);
		}
		else
		{
			result[i] = ft_substr(s, j, wordsize(s + j, c));
		}
		if (!result[i])
			return (freecandy(result, i));
		j += wordsize(s + j, c);
		i++;
	}
	return (result);
}

// int	main(void)
// {
// 	char	**split;
// 	int		i = 0;

// 	split = ft_split("awk '{count++} END {print count}'", ' ');
// 	while (split[i])
// 	{
// 		printf("sp:%s\n", split[i]);
// 		i++;
// 	}
// 	free(split);
// 	return 0;
// }
