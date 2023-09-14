/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnebatz <dnebatz@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 09:28:44 by dnebatz           #+#    #+#             */
/*   Updated: 2023/06/20 09:19:56 by dnebatz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include "libft/libft.h"

int	ft_printf(const char *s, ...);
int	ft_putnbr_ret(int n);
int	ft_putnbr_unsigned_ret(unsigned int n);
int	ft_putnbr_hex(unsigned int nbr, char *base);
int	ft_putnbr_p(unsigned long nbr, char *base);

#endif