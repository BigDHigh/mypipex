/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_special_split.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnebatz <dnebatz@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 10:46:55 by dnebatz           #+#    #+#             */
/*   Updated: 2023/09/06 18:33:48 by dnebatz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	**ft_free(char **splitted, int i)
{
	while (i >= 0)
		free(splitted[i--]);
	free(splitted);
	return (NULL);
}

static char	*ft_start(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (!(s[i] == c))
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

static char	*ft_end(char const *s, char c)
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return ((char *)&s[i - 1]);
		i++;
	}
	if (ft_strlen(s) == i)
		return ((char *)&s[i - 1]);
	return ((char *)s);
}

static int	ft_get_array_count(char const *s, char c)
{
	int	count;
	int	new_word;
	int	once;

	new_word = 1;
	count = 0;
	once = 0;
	while (*s)
	{
		if (*s == c)
		{
			new_word = 1;
			once = 1;
		}
		if (!(*s == c) && new_word)
		{
			count++;
			new_word = 0;
		}
		s++;
	}
	if (count == 0 && once == 1)
		return (0);
	return (count);
}

// mallocing one more than needed for the quoted part
char	**ft_special_split(char const *s, char c)
{
	char	**splitted;
	int		i;
	int		len;

	splitted = malloc((ft_get_array_count(s, c) + 2) * sizeof(char *));
	if (splitted)
	{
		i = 0;
		while (i < ft_get_array_count(s, c))
		{
			len = (ft_end(ft_start(s, c), c) - ft_start(s, c)) / sizeof(char);
			splitted[i] = malloc((len + 2) * sizeof(char));
			if (splitted[i])
				ft_strlcpy(splitted[i++], ft_start(s, c), len + 2);
			else
				return (ft_free(splitted, i++ + 1));
			s = s + (ft_end(ft_start(s, c), c) - s) / sizeof(char) + 1;
		}
		splitted[i] = NULL;
		splitted[i + 1] = NULL;
		return (splitted);
	}
	else
		return (0);
}
