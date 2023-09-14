/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnebatz <dnebatz@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 10:00:11 by dnebatz           #+#    #+#             */
/*   Updated: 2023/07/17 18:06:09 by dnebatz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_length(char *base)
{
	int		i;

	i = 0;
	while (base[i])
		i++;
	return (i);
}

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
	while (i < 9)
	{
		array[i] = 0;
		i++;
	}
}

int	ft_putnbr_hex(unsigned int nbr, char *base)
{
	char	result[9];
	int		i;

	ft_ini_array(result);
	i = 0;
	result[i] = base[nbr % 16];
	while ((nbr / 16))
	{
		i++;
		nbr = nbr / 16;
		result[i] = base[nbr % 16];
	}
	ft_rev_int_tab(result, ft_length(result));
	return (ft_length(result));
}
