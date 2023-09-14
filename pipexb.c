/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipexb.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnebatz <dnebatz@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 11:29:51 by dnebatz           #+#    #+#             */
/*   Updated: 2023/09/12 19:02:01 by dnebatz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <signal.h>

void	ft_child1(int *pipe_fd1, int *pipe_fd2, char **command_array)
{
	int	fd;

	dprintf(2, "Hello 1\n");
	fd = open("input.txt", O_RDONLY);
	if (fd < 0)
	{
		perror("file error");
		return ;
	}
	close(pipe_fd1[0]);
	close(pipe_fd2[0]);
	close(pipe_fd2[1]);
	dup2(fd, 0);			// standard input now getting from the text file
	dup2(pipe_fd1[1], 1);	// standard output of cat now writing in the write end of the first pipe
	dprintf(2, "Bye 1\n");
	execve("/bin/cat", command_array, NULL);
	perror("Execve error:");
}

void	ft_child2(int *pipe_fd1, int *pipe_fd2, char **command_array)
{
	dprintf(2, "Hello 2\n");
	close(pipe_fd1[1]);		//closing write end of the first
	close(pipe_fd2[0]);		//closing read end of the second
	dup2(pipe_fd1[0], 0);	// standard input now getting from read end first pipe
	dup2(pipe_fd2[1], 1);	// standard output now writing in the write end of second pipe
	dprintf(2, "Bye 2\n");
	execve("/bin/cat", command_array, NULL);
	perror("Execve error:");
}

void	ft_child3(int *pipe_fd1, int *pipe_fd2, char **command_array)
{
	int	fd;

	dprintf(2, "Hello 3\n");
	fd = open("output.txt", O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
	{
		perror("file error");
		return ;
	}
	close(pipe_fd2[1]); // closing read end of the second
	close(pipe_fd1[0]); // closing first pipe
	close(pipe_fd1[1]); // closing first pipe
	dup2(pipe_fd2[0], 0); // standard input read now from read end of second pipe
	dup2(fd, 1);			// standard output now write in fd
	dprintf(2, "Bye 3\n");
	execve("/bin/cat", command_array, NULL);
	perror("Execve error:");
}


int	main(int argc, char **argv, char **envp)
{
	int		*pipe_fd1;
	int		*pipe_fd2;
	int		id;
	int		id2;
	int		id3;
	char	**command_array;

	command_array = ft_split("/bin/cat -e", ' ');
	pipe_fd1 = malloc(sizeof(int) * 2);
	pipe_fd2 = malloc(sizeof(int) * 2);
	pipe(pipe_fd1);
	pipe(pipe_fd2);
	id = fork();
	if (id > 0)
		id2 = fork();
	if (id > 0 && id2 > 0)
		id3 = fork();
	if (!id)
		ft_child1(pipe_fd1, pipe_fd2, command_array);
	if (!id2)
		ft_child2(pipe_fd1, pipe_fd2, command_array);
	if (!id3)
		ft_child3(pipe_fd1, pipe_fd2, command_array);
	close(pipe_fd1[0]);
	close(pipe_fd1[1]);
	close(pipe_fd2[0]);
	close(pipe_fd2[1]);
	waitpid(id, NULL, 0);
	waitpid(id2, NULL, 0);
	waitpid(id3, NULL, 0);
	dprintf(2, "ohoh");
	return (0);
}
