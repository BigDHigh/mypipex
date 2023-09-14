/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnebatz <dnebatz@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 17:42:27 by dnebatz           #+#    #+#             */
/*   Updated: 2023/05/31 09:15:37 by dnebatz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	unsigned int	i;
	char			*s_c;

	c = (char)c;
	s_c = (char *)s;
	i = 0;
	while (s_c[i])
	{
		if (s_c[i] == c)
			return (&s_c[i]);
		i++;
	}
	if (c == '\0')
		return (&s_c[i]);
	else
		return (0);
}
