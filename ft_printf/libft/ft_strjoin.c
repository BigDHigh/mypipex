/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnebatz <dnebatz@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 17:30:32 by dnebatz           #+#    #+#             */
/*   Updated: 2023/05/31 08:43:34 by dnebatz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*joined;
	int		i;
	int		j;

	i = -1;
	j = -1;
	joined = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (joined)
	{
		while (s1[++i])
			joined[i] = s1[i];
		i = ft_strlen(s1);
		while (s2[++j])
		{
			joined[i] = s2[j];
			i++;
		}
		joined[i] = 0;
		return (joined);
	}
	else
		return (0);
}
