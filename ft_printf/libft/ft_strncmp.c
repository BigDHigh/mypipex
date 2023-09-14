/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnebatz <dnebatz@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 18:56:38 by dnebatz           #+#    #+#             */
/*   Updated: 2023/05/31 08:44:02 by dnebatz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;
	unsigned char	*s1_c;
	unsigned char	*s2_c;

	s1_c = (unsigned char *) s1;
	s2_c = (unsigned char *) s2;
	i = 0;
	while (s1_c[i] && s2_c[i] && s1_c[i] == s2_c[i] && i < n)
		i++;
	if (n == i)
		return (0);
	return (s1_c[i] - s2_c[i]);
}
