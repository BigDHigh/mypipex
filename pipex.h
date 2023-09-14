/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnebatz <dnebatz@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 10:18:35 by dnebatz           #+#    #+#             */
/*   Updated: 2023/09/14 11:13:59 by dnebatz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>		//open
# include <sys/wait.h>	//wait
# include <stdio.h>
# include <string.h>	//strerror
# include "ft_printf/ft_printf.h"

typedef struct s_pipex {
	int		here_doc;
	int		count_children;
	int		*id;
	int		count_pipes;
	int		**pipe_fd;
	int		error;
	int		argc;
	char	**commands;
	char	**envp;
	char	**argv;
}	t_pipex;

char	*ft_check_command_and_get_path(char *command, char **envp);
void	ft_free_array(char **array);
char	**ft_special_split(char const *s, char c);
char	**ft_get_command_arg_array(char *command);
void	ft_remove(char *start, char *end);
void	ft_close_fds(t_pipex *data, int current_child);
void	ft_close_all_fds(t_pipex *data);
int		ft_print_command_error(char **argv, int error_code);
int		ft_init(t_pipex *new, int argc, char **argv, char **envp);

#endif