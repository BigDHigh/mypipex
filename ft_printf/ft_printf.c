/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnebatz <dnebatz@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 09:28:46 by dnebatz           #+#    #+#             */
/*   Updated: 2023/06/20 09:29:56 by dnebatz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_handle_percent(int *len)
{
	*len = *len + 1;
	write(1, "%", 1);
}

static void	ft_handle_string(int *len, va_list *args)
{
	char	*string;

	string = va_arg(*args, char *);
	if (string == NULL)
	{
		ft_putstr_fd("(null)", 1);
		*len = *len + 6;
	}
	else
	{
		ft_putstr_fd(string, 1);
		*len = *len + ft_strlen(string);
	}
}

static int	ft_found_percent(char *s, va_list *args, int *len)
{
	char	cr;

	if (s[0] == '%')
		ft_handle_percent(len);
	else if (s[0] == 'i' || s[0] == 'd')
		*len = *len + ft_putnbr_ret(va_arg(*args, int));
	else if (s[0] == 'u')
		*len = *len + ft_putnbr_unsigned_ret(va_arg(*args, unsigned int));
	else if (s[0] == 'c')
	{
		cr = va_arg(*args, int);
		write(1, &cr, 1);
		*len = *len + 1;
	}
	else if (s[0] == 's')
		ft_handle_string(len, args);
	else if (s[0] == 'p')
		*len += ft_putnbr_p(va_arg(*args, unsigned long), "0123456789abcdef");
	else if (s[0] == 'x')
		*len += ft_putnbr_hex(va_arg(*args, unsigned int), "0123456789abcdef");
	else if (s[0] == 'X')
		*len += ft_putnbr_hex(va_arg(*args, unsigned int), "0123456789ABCDEF");
	return (2);
}

int	ft_printf(const char *s, ...)
{
	int		i;
	int		retnbr;
	va_list	args;

	va_start(args, s);
	i = 0;
	retnbr = 0;
	while (s[i])
	{
		if (s[i] == '%')
			i = i + ft_found_percent((char *)&s[i + 1], &args, &retnbr);
		if (s[i] && s[i] != '%')
		{
			write(1, &s[i++], 1);
			retnbr++;
		}
	}
	va_end(args);
	return (retnbr);
}
