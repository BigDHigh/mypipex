/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_command_and_get_path.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnebatz <dnebatz@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 09:51:39 by dnebatz           #+#    #+#             */
/*   Updated: 2023/09/07 11:35:47 by dnebatz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

// is fetching all from enviroment after PATH=
char	*ft_get_path(char **envp)
{
	int		i;
	char	*path;

	i = 0;
	if (*envp != NULL)
	{
		while (envp[i])
		{
			if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			{
				path = ft_substr(envp[i], 5, ft_strlen(envp[i]));
				return (path);
			}
			i++;
		}
	}
	return (NULL);
}

// splitting the path variables into an array
char	**ft_get_path_array(char *all_path)
{
	char	**path_array;

	if (!all_path)
		return (NULL);
	path_array = ft_split(all_path, ':');
	return (path_array);
}

// testing if the path and command is valid
char	*ft_get_valid_path(char *command, char **path_array)
{
	char	*command_with_slash;
	char	*command_with_path;
	int		i;

	i = 0;
	if (!path_array)
		return (NULL);
	while (path_array[i])
	{
		command_with_slash = ft_strjoin("/", command);
		command_with_path = ft_strjoin(path_array[i], command_with_slash);
		free(command_with_slash);
		if (!access(command_with_path, X_OK))
			return (command_with_path);
		i++;
		free(command_with_path);
	}
	return (NULL);
}

// combinig the functions to check commands and get with right path
char	*ft_check_command_and_get_path(char *command, char **envp)
{
	char	*all_path;
	char	**path_array;
	char	*valid_path;

	if (!access(command, X_OK))
		return (command);
	all_path = ft_get_path(envp);
	path_array = ft_get_path_array(all_path);
	free(all_path);
	valid_path = ft_get_valid_path(command, path_array);
	ft_free_array(path_array);
	return (valid_path);
}
