/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnebatz <dnebatz@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 16:02:57 by dnebatz           #+#    #+#             */
/*   Updated: 2023/05/31 09:16:00 by dnebatz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}

/*int	main()
{
	char hello[] = "HELLO";
	ft_striteri(hello, &ft_loliteri);
	printf("return: %s\n", hello);
	char hello1[] = "HELLO";
	ft_striteri(hello1, NULL);
	printf("return: %s\n", hello1);
	char hello2[] = "";
	ft_striteri(hello2, &ft_loliteri);
	printf("return: %s\n", hello2);
}*/