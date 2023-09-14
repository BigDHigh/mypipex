/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnebatz <dnebatz@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 18:05:11 by dnebatz           #+#    #+#             */
/*   Updated: 2023/05/31 09:16:24 by dnebatz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	unsigned int	i;
	char			*s_c;

	c = (char)c;
	s_c = (char *)s;
	i = 0;
	while (s_c[i])
		i++;
	if (c == 0)
		return (&s_c[i]);
	while (i-- > 0)
		if (s_c[i] == c)
			return (&s_c[i]);
	return (0);
}
