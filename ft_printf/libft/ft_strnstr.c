/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnebatz <dnebatz@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 09:56:09 by dnebatz           #+#    #+#             */
/*   Updated: 2023/08/28 15:02:45 by dnebatz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	unsigned int	i;
	unsigned int	needle_len;

	i = 0;
	needle_len = ft_strlen(needle);
	if (!needle[i])
	{
		return ((char *)haystack);
	}
	if (!haystack[i])
		return (NULL);
	if (needle_len > n)
		return (0);
	while (haystack[i] && (n - needle_len) >= i)
	{
		if (ft_strncmp((char *)&haystack[i], (char *)needle, needle_len) == 0)
			return ((char *)&haystack[i]);
		i++;
	}
	return (0);
}
