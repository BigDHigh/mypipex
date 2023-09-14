/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnebatz <dnebatz@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 15:29:33 by dnebatz           #+#    #+#             */
/*   Updated: 2023/05/31 08:43:57 by dnebatz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*new_s;
	int		len_s;

	if (!f)
		return (0);
	len_s = ft_strlen(s);
	i = 0;
	new_s = malloc((len_s + 1) * sizeof(char));
	if (!new_s)
		return (0);
	while (s[i])
	{
		new_s[i] = f(i, s[i]);
		i++;
	}
	new_s[i] = 0;
	return (new_s);
}

/*int	main()
{
	printf("return: %s\n", ft_strmapi("HELLO", &ft_lol));
	printf("return: %s\n", ft_strmapi("HELLO", NULL));
	printf("return: %s\n", ft_strmapi("", &ft_lol));
}*/