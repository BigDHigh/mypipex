/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnebatz <dnebatz@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 19:32:24 by dnebatz           #+#    #+#             */
/*   Updated: 2023/09/14 15:23:52 by dnebatz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_parent(t_pipex *data)
{
	int	i;

	i = -1;
	// freeing
	printf("parent: closing all pipes\n");
	ft_close_all_fds(data); // closing all pipes
	printf("waiting for children to be closed\n");
	while (++i < data->count_children)
	{
		waitpid(data->id[i], NULL, 0);
	}
	// printf("thanks parent is done!\n");
	return (0);
}

// standard input now last pipe read end
// standard input now before pipe read end
// standard output now first pipe write end
// standard output now pipe write end
int	ft_child(int i, t_pipex *data)
{
	char	**command_array;
	char	*command;

	ft_close_fds(data, i);
	if (i == 0)
		dup2(data->pipe_fd[data->count_pipes - 1][0], 0);
	else
		dup2(data->pipe_fd[i - 1][0], 0);
	if (i == data->count_children - 1)
		dup2(data->pipe_fd[0][1], 1);
	else
		dup2(data->pipe_fd[i][1], 1);
	command_array = ft_get_command_arg_array
		(data->commands[i]);
	command = ft_check_command_and_get_path(command_array[0], data->envp);
	if (command == NULL)
		return (ft_print_command_error(data->argv, 127));
	execve(command, command_array, data->envp);
	ft_free_array(command_array);
	free(command);
	perror("Execve error:");
	return (127);
}

int	ft_here_doc(t_pipex *data)
{
	char	*red_line;

	printf("hallo ich bin get next line\n");
	red_line = get_next_line(0);
	while (red_line != NULL)
	{
		write(data->pipe_fd[data->count_pipes - 1][1], red_line, ft_strlen(red_line));
		free(red_line);
		red_line = get_next_line(0);
		if (ft_strnstr(red_line, "limiter", ft_strlen(red_line)) != NULL)
			break ;
	}
	free(red_line);
	return (1);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	data;
	int		i;

	if (argc < 5)
	{
		ft_putstr_fd("Wrong argument count!\n", 2);
		return (1);
	}
	data.here_doc = 0;
	if (!ft_strncmp(argv[1], "here_doc", 8))
	{
		printf("someone wrote here_doc!\n");
		data.here_doc = 1;
	}
	ft_init(&data, argc, argv, envp);
	if (data.id == NULL || data.pipe_fd == NULL)
		return (1);
	i = -1;
	while (++i < data.count_pipes)
	{
		data.pipe_fd[i] = malloc(sizeof(int) * 2);
		if (data.pipe_fd[i] == NULL)
			return (1);
	}
	i = -1;
	while (++i < data.count_pipes)
	{
		if (pipe(data.pipe_fd[i]) == -1)
		{
			ft_putstr_fd("Pipe Error!\n", 2);
			return (1);
		}
	}
	i = -1;
	while (++i < data.count_children)
	{
		data.id[i] = fork();
		if (data.id[i] == 0)
			break ;
	}
	if (i == data.count_children)
		i--;
	if ((data.id[i] < 0) && (i < data.count_children))
	{
		dprintf(2, "fork error at id[%i]: %i\n", i, data.id[i]);
		perror("fork error");
	}
	else if (data.id[i] == 0 && i == 0 && data.here_doc) // first child here doc
	{
		ft_here_doc(&data);
		data.error += ft_child(i, &data);
	}
	else if (data.id[i] == 0 && i == 0) // first child
	{
		close(data.pipe_fd[data.count_pipes - 1][0]);
		data.pipe_fd[data.count_pipes - 1][0] = open(argv[1], O_RDONLY);
		data.error += ft_child(i, &data);
	}
	else if (data.id[i] == 0 && i == data.count_children - 1) // last child
	{
		close(data.pipe_fd[0][1]);
		data.pipe_fd[0][1] = open(argv[argc - 1], O_RDWR | O_CREAT | O_TRUNC, 0644);
		data.error += ft_child(i, &data);
	}
	else if (data.id[i] == 0)
		data.error += ft_child(i, &data);
	else if (data.id[i] > 0)
		data.error += ft_parent(&data);
	return (data.error);
}
