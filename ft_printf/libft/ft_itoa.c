/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnebatz <dnebatz@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 12:52:58 by dnebatz           #+#    #+#             */
/*   Updated: 2023/07/17 18:06:38 by dnebatz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_size(int n);
static void	ft_handle_negativ(char *s, int size, int n);
static void	ft_handle_positive(char *s, int size, int n);

char	*ft_itoa(int n)
{
	char	*number;
	int		size;
	int		size2;

	size = ft_size(n);
	size2 = size;
	number = malloc((size + 1) * sizeof(char));
	if (number)
	{
		if (n < 0)
			ft_handle_negativ(number, size, n);
		else
			ft_handle_positive(number, size, n);
		*(number + size2) = 0;
		return (number);
	}
	else
		return (0);
}

static void	ft_handle_negativ(char *s, int size, int n)
{
	int	size2;

	size2 = size;
	*s = '-';
	s++;
	size--;
	*(s + size - 1) = ((n % 10) * -1) + '0';
	n = n / -10;
	size--;
	while (size)
	{
		*(s + size - 1) = (n % 10) + '0';
		n = n / 10;
		size--;
	}
	*(s + size2 - 1) = 0;
}

static void	ft_handle_positive(char *s, int size, int n)
{
	int	size2;

	size2 = size;
	while (size)
	{
		*(s + size - 1) = (n % 10) + '0';
		n = n / 10;
		size--;
	}
	*(s + size2) = 0;
}

static int	ft_size(int n)
{
	int	size;

	size = 0;
	if (n < 1)
		size++;
	while (n)
	{
		n = n / 10;
		size++;
	}
	return (size);
}

/*
int main()
{
	printf("return: %s\n",ft_itoa(2147483647));
	printf("return: %s\n",ft_itoa(-2147483648));
	printf("return: %s\n",ft_itoa(0));
	printf("return: %s\n",ft_itoa(42));
	printf("return: %s\n",ft_itoa(-42));
	return (0);
}*/