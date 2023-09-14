/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnebatz <dnebatz@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 16:56:52 by dnebatz           #+#    #+#             */
/*   Updated: 2023/09/13 17:02:51 by dnebatz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_print_execve_error(char **argv, int error_code)
{
	return (error_code);
}

int	ft_print_command_error(char **argv, int error_code)
{
	ft_putstr_fd(&argv[0][2], 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(argv[2], 2);
	ft_putstr_fd(": command not found\n", 2);
	return (error_code);
}
