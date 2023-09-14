/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnebatz <dnebatz@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 17:26:22 by dnebatz           #+#    #+#             */
/*   Updated: 2023/05/31 09:02:44 by dnebatz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	dest_count;
	size_t	src_count;
	size_t	j;

	i = 0;
	dest_count = 0;
	src_count = 0;
	while (dest[dest_count])
		dest_count++;
	while (src[src_count])
		src_count++;
	j = dest_count;
	if (!size)
		return (src_count);
	while (src[i] && j < size - 1)
		dest[j++] = src[i++];
	dest[j] = 0;
	if (size < dest_count)
		return (src_count + size);
	return (dest_count + src_count);
}
