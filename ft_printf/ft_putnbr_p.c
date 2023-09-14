/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnebatz <dnebatz@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 10:00:11 by dnebatz           #+#    #+#             */
/*   Updated: 2023/08/28 15:01:49 by dnebatz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_rev_int_tab(char *tab, int size)
{
	int		i;
	char	temp;

	i = 0;
	while (i < size / 2)
	{
		temp = tab[i];
		tab[i] = tab[size - i -1];
		tab[size - i -1] = temp;
		i++;
	}
	i = 0;
	write(1, "0x", 2);
	while (i < size)
	{
		write(1, &tab[i], 1);
		i++;
	}
}

static void	ft_ini_array(char *array)
{
	int		i;

	i = 0;
	while (i < 17)
	{
		array[i] = 0;
		i++;
	}
}

static int	ft_length(char *base)
{
	int		i;

	i = 0;
	while (base[i])
		i++;
	return (i);
}

int	ft_putnbr_p(unsigned long nbr, char *base)
{
	char	result[17];
	int		i;

	ft_ini_array(result);
	i = 0;
	result[i] = base[nbr % ft_length(base)];
	while ((nbr / ft_length(base)))
	{
		i++;
		nbr = nbr / ft_length(base);
		result[i] = base[nbr % ft_length(base)];
	}
	ft_rev_int_tab(result, ft_length(result));
	return (ft_length(result) + 2);
}
