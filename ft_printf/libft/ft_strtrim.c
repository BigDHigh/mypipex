/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnebatz <dnebatz@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 18:02:53 by dnebatz           #+#    #+#             */
/*   Updated: 2023/05/31 08:44:17 by dnebatz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_start_tri(char const *s1, char const *set);
static unsigned int	ft_end_tri(char const *s1, char const *set);

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	len_trim;
	char			*trimmed;
	unsigned int	i;
	unsigned int	j;

	i = ft_start_tri(s1, set);
	j = 0;
	if (ft_start_tri(s1, set) + ft_end_tri(s1, set) > ft_strlen(s1))
		len_trim = 0;
	else
		len_trim = ft_strlen(s1) - ft_start_tri(s1, set) - ft_end_tri(s1, set);
	trimmed = (char *)malloc((len_trim + 1) * sizeof(char));
	if (trimmed)
	{
		while (j < len_trim)
		{
			trimmed[j] = s1[i];
			j++;
			i++;
		}
		trimmed[j] = 0;
		return (trimmed);
	}
	else
		return (0);
}

static unsigned int	ft_start_tri(char const *s1, char const *set)
{
	unsigned int	found;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	found = 0;
	while (s1[i])
	{
		j = 0;
		found = 0;
		while (set[j])
		{
			if (s1[i] == set[j])
				found = 1;
			j++;
		}
		if (found)
			i++;
		else
			return (i);
	}
	return (i);
}

static unsigned int	ft_end_tri(char const *s1, char const *set)
{
	unsigned int	found;
	unsigned int	i;
	unsigned int	j;

	if (s1[0] && set[0])
		i = ft_strlen(s1) - 1;
	else
		return (0);
	found = 0;
	while (s1[i])
	{
		j = 0;
		found = 0;
		while (set[j])
		{
			if (s1[i] == set[j])
				found = 1;
			j++;
		}
		if (found && i != 0)
			i--;
		else
			return (ft_strlen(s1) - 1 - i);
	}
	return (ft_strlen(s1) - 1 - i);
}

/*
int	main()
{
	//printf("return get_start: %i\n",ft_start_tri("dfasdfaefads", "sd"));
	//printf("return end_start: %i\n",ft_end_tri("dfasdfaefads", "sd"));
	printf("return get_start: %i\n",ft_start_tri("111111", "1"));
	printf("return end_start: %i\n",ft_end_tri("111111", "21"));
	printf("return ft_strtrim: %s\n",ft_strtrim("", ""));
	printf("return ft_strtrim: %s\n",ft_strtrim("123", ""));
	printf("return ft_strtrim: %s\n",ft_strtrim("", "123"));
	//printf("return ft_strtrim: %s\n",ft_strtrim("     ", " "));
	printf("return ft_strtrim: %s\n",ft_strtrim("111111", "1"));
	return (0);
}*/