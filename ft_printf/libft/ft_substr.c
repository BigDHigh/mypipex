/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnebatz <dnebatz@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 16:22:15 by dnebatz           #+#    #+#             */
/*   Updated: 2023/05/31 08:44:36 by dnebatz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_get_copy_len(char const *s, unsigned int start, size_t len);

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*copy;
	unsigned int	empty;
	size_t			len_copy;

	empty = 0;
	len_copy = ft_get_copy_len(s, start, len);
	if (!len)
		empty = 1;
	else if (start > ft_strlen(s))
		empty = 1;
	if (empty)
	{
		copy = (char *)malloc(sizeof(char));
		if (copy)
			copy[0] = 0;
	}
	else
	{
		copy = (char *)malloc((len_copy + 1) * sizeof(char));
		if (copy)
			ft_strlcpy(copy, (s + start), (len_copy + 1));
	}
	return (copy);
}

static size_t	ft_get_copy_len(char const *s, unsigned int start, size_t len)
{
	size_t	len_s;

	len_s = ft_strlen(s);
	if (!len)
		return (0);
	else if (len_s > start + len)
		return (len);
	else if (len_s < 1 + start)
		return (0);
	else
		return (len_s - start);
}
