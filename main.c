/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnebatz <dnebatz@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 14:15:37 by dnebatz           #+#    #+#             */
/*   Updated: 2023/09/11 12:03:01 by dnebatz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_parent(char **argv, char **envp, int pipe_fd[2])
{
	int		filefd;
	char	**command_array;
	char	*command;
	char	*progname;

	close(pipe_fd[1]);
	filefd = open(argv[4], O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (filefd < 1)
	{
		perror("Error");
		return (1);
	}
	command_array = ft_get_command_arg_array(argv[3]);
	command = ft_check_command_and_get_path(command_array[0], envp);
	if (command == NULL)
	{
		// ft_putstr_fd("Command not found!\n", 2);
		ft_putstr_fd(&argv[0][2], 2);
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(argv[3], 2);
		ft_putstr_fd(": command not found\n", 2);
		return (127);
	}
	dup2(pipe_fd[0], 0);
	dup2(filefd, 1);
	execve(command, command_array, envp);
	ft_free_array(command_array);
	free(command);
	perror("Could not execute\n");
	return (127);
}

// standard output now pipe write end
// standard input now pipe read end
int	ft_child(char **argv, char **envp, int fd[2])
{
	int		filefd;
	char	*command;
	char	**command_array;

	filefd = open(argv[1], O_RDONLY);
	if (filefd < 1)
	{
		ft_putstr_fd(&argv[0][2], 2);
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(argv[1], 2);
		ft_putstr_fd(": ", 2);
		perror(NULL);
		return (1);
	}
	command_array = ft_get_command_arg_array(argv[2]);
	command = ft_check_command_and_get_path(command_array[0], envp);
	if (command == NULL)
	{
		ft_putstr_fd(&argv[0][2], 2);
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(argv[2], 2);
		ft_putstr_fd(": command not found\n", 2);
		return (127);
	}
	close(fd[0]);
	dup2(fd[1], 1);
	dup2(filefd, 0);
	execve(command, command_array, envp);
	ft_free_array(command_array);
	free(command);
	perror("could not execute\n");
	return (127);
}

int	main(int argc, char **argv, char **envp)
{
	int		id;
	int		pipe_fd[2];
	int		filefd;
	int		error;

	error = 0;
	if (!(argc == 5))
	{
		ft_putstr_fd("Wrong argument count!\n", 2);
		return (1);
	}
	if (!envp)
	{
		ft_putstr_fd("No envp!\n", 2);
		return (127);
	}
	if (!*envp)
	{
		//ft_putstr_fd("No envp!\n", 2);
		return (0);
	}
	if (pipe(pipe_fd) == -1)
	{
		ft_putstr_fd("Pipe Error!\n", 2);
		return (1);
	}
	id = fork();
	if (id != 0)
	{
		error += ft_parent(argv, envp, pipe_fd);
	}
	else
	{
		error += ft_child(argv, envp, pipe_fd);
	}
	return (error);
}
