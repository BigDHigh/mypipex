/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnebatz <dnebatz@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 20:50:22 by dnebatz           #+#    #+#             */
/*   Updated: 2023/09/14 15:26:59 by dnebatz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_init(t_pipex *new, int argc, char **argv, char **envp)
{
	new->count_children = argc - 3 - new->here_doc;
	new->id = malloc(sizeof(int) * new->count_children);
	new->count_pipes = argc - 4 - new->here_doc;
	new->pipe_fd = malloc(sizeof(int *) * new->count_pipes);
	new->error = 0;
	new->commands = &argv[2 + new->here_doc];
	new->envp = envp;
	new->argc = argc;
	new->argv = argv;
	return (1);
}

void	ft_free_array(char **array)
{
	int	i;

	i = 0;
	if (array)
	{
		while (array[i])
		{
			free(array[i]);
			i++;
		}
	}
	free(array);
}

void	ft_close_all_fds(t_pipex *data)
{
	int	i;

	i = 0;
	while (i < data->count_pipes)
	{
		close(data->pipe_fd[i][0]);
		close(data->pipe_fd[i][1]);
		i++;
	}
}


void	ft_close_fds(t_pipex *data, int current_child)
{
	int	i;

	i = 0;
	while (i < data->count_pipes)
	{
		if (i != current_child && !(current_child == data->count_children - 1 && i == 0))
		{
			close(data->pipe_fd[i][1]);
			dprintf(2, "closing in child:%i pipe_fd[%i][1]\n", current_child, i);
		}
		if (i != current_child - 1 && !(current_child == 0 && i == data->count_pipes - 1))
		{
			close(data->pipe_fd[i][0]);
			dprintf(2, "closing in child:%i pipe_fd[%i][0]\n", current_child, i);
		}
		i++;
	}
}
