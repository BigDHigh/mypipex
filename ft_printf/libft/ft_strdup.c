/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnebatz <dnebatz@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 17:46:27 by dnebatz           #+#    #+#             */
/*   Updated: 2023/05/31 08:43:21 by dnebatz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char			*copy;
	unsigned int	s1_len;

	s1_len = ft_strlen(s1);
	copy = malloc((s1_len * sizeof(char)) + 1);
	if (copy)
	{
		ft_strlcpy(copy, s1, s1_len + 1);
		return (copy);
	}
	else
		return (0);
}
