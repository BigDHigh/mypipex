/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned_ret.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnebatz <dnebatz@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 16:30:47 by dnebatz           #+#    #+#             */
/*   Updated: 2023/06/19 12:51:49 by dnebatz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_count_digits(unsigned int n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

int	ft_putnbr_unsigned_ret(unsigned int n)
{
	int	ret;

	ret = ft_count_digits(n);
	if (n > 9)
		ft_putnbr_unsigned_ret(n / 10);
	if (n < 10)
		ft_putchar_fd(n + '0', 1);
	else
		ft_putchar_fd((n % 10) + '0', 1);
	return (ret);
}

/*int	main()
{
	printf("ret: %i\n", ft_putnbr_ret(2147483647));
	printf("ret: %i\n", ft_putnbr_ret(-2147483648));
	printf("ret: %i\n", ft_putnbr_ret(0));
	printf("ret: %i\n", ft_putnbr_ret(-42));
	printf("ret: %i\n", ft_putnbr_ret(42));
	printf("ret: %i\n", ft_putnbr_ret(10));
	printf("ret: %i\n", ft_putnbr_ret(-10));
	printf("ret: %i\n", ft_putnbr_ret(100));
}*/