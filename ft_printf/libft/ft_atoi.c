/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnebatz <dnebatz@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 06:12:10 by dnebatz           #+#    #+#             */
/*   Updated: 2023/05/31 09:14:16 by dnebatz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int		ft_recursive_str_to_int(const char *str, int *number);

int	ft_atoi(const char *str)
{
	int		i;
	int		count_minus;
	int		number;

	i = 0;
	count_minus = 0;
	number = 0;
	if (!str[0])
		return (0);
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str [i] == '+')
		if (str[i++] == '-')
			count_minus++;
	if (!(str[i] >= '0' && str [i] <= '9'))
		return (0);
	ft_recursive_str_to_int(&str[i], &number);
	if (((!(count_minus % 2)) || number == -2147483648))
		return (number);
	else if ((i) && (count_minus % 2))
		return (number * -1);
	else
		return (0);
}

static int	ft_recursive_str_to_int(const char *str, int *number)
{
	if (!str[0])
		return (0);
	if (!(str[0] >= '0' && str[0] <= '9'))
		return (0);
	if (str[0] >= '0' && str[0] <= '9')
		*number = *number * 10 + str[0] - '0';
	ft_recursive_str_to_int(&str[1], number);
	return (0);
}
/*
   #include <stdio.h>
   #include <unistd.h>
   int	main(int argc, char **argv)
   {
   	int i;
  	i = argc;
   	i = 0;
   	i = ft_atoi(argv[1]);
   	printf("return is: %i\n", i);
   }*/