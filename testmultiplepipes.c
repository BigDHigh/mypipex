/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testmultiplepipes.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnebatz <dnebatz@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 12:09:23 by dnebatz           #+#    #+#             */
/*   Updated: 2023/09/12 19:28:07 by dnebatz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	ft_parent(int **pipe_fd, int *id, int argc)
{
	int	status;

	status = 0;
	waitpid(id[0], &status, 0);
	waitpid(id[1], &status, 0);
	// waitpid(id[2], &status, 0);
	printf("parent here childs done\n");
	return (1);
}

// standard output now pipe write end
// standard input now pipe read end
int	ft_child(char **envp, int i, char **argv, int *fd)
{
	char	*command;
	char	**command_array;

	command_array = ft_get_command_arg_array(argv[i + 2]);
	command = ft_check_command_and_get_path(command_array[0], envp);
	dup2(fd[0], 0);		// standard input now pipe read end
	dup2(fd[1], 1);		// standard output now pipe write end
	close(fd[0]);
	close(fd[1]);
	execve(command, command_array, envp);
	perror("Execve error:");
	dprintf(2, "child error i: %i\n", i);
	return (1);
}

int	main(int argc, char **argv, char **envp)
{
	int		*id;
	int		**pipe_fd;
	int		i;
	int		j;
	int		error;

	error = -1;
	i = -1;
	pipe_fd = malloc(sizeof(int *) * (argc - 3));
	id = malloc(sizeof(int) * (argc - 2));
	if (pipe_fd == NULL || id == NULL)
		return (1);
	while (++i < argc - 3)
	{
		pipe_fd[i] = malloc(sizeof(int) * 2);
		if (pipe_fd[i] == NULL)
			return (1);
	}
	i = -1;
	printf("argc: %i\n", argc);
	while (++i < argc - 4)
	{
		if (pipe(pipe_fd[i]) == -1)
		{
			ft_putstr_fd("Pipe Error!\n", 2);
			return (1);
		}
	}
	i = -1;
	while (++i < argc - 3)
	{
		id[i] = fork();
		if (id[i] == 0)
			break ;
	}
	if ((id[i] < 0) && (i < argc - 3))
	{
		dprintf(2, "fork error at id[%i]: %i\n", i, id[i]);
		perror("fork error");
	}
	else if (id[i] == 0 && i == 0)
	{
		pipe_fd[i][0] = open(argv[1], O_RDONLY);
		ft_child(envp, i, argv, pipe_fd[i]);
	}
	else if (id[i] == 0 && i == (argc - 4))
	{
		pipe_fd[i][0] = pipe_fd[i - 1][0];
		error = open(argv[argc - 1], O_RDWR | O_CREAT | O_TRUNC, 0644);
		if (error < 1)
			perror("open error");
		dprintf(2, "open last fd[%i]: %i\n", i, error);
		pipe_fd[i][1] = error;
		ft_child(envp, i, argv, pipe_fd[i]);
	}
	else
	{
		pipe_fd[i][0] = pipe_fd[i - 1][0];
		ft_child(envp, i, argv, pipe_fd[i]);
	}
	ft_parent(pipe_fd, id, argc);
	return (0);
}
