/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_command_arg_array.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnebatz <dnebatz@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 09:32:28 by dnebatz           #+#    #+#             */
/*   Updated: 2023/09/06 18:17:37 by dnebatz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

//"grep Hello", "awk '{count++} END {print count}'"
//"grep -v !", "sed 's/Hello/Salut/g'"

void	ft_remove(char *start, char *end)
{
	ft_memmove(start, end, (end - start) / sizeof(char));
}

int	ft_strchr_count(const char *string, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (string == NULL)
		return (0);
	while (string[i])
	{
		if (string[i] == c)
			j++;
		i++;
	}
	return (j);
}

int	ft_get_pos(char *s, char c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (0);
}

char	**ft_get_command_arg_array(char *command)
{
	unsigned int	size;
	char			**command_array;
	int				pos;
	char			*deleted;

	if (ft_strchr_count(command, '\'') == 2)
	{
		size = (ft_strrchr(command, '\'') - 
				ft_strchr(command, '\'')) / sizeof(char);
		pos = ft_get_pos(command, '\'');
		deleted = ft_substr(command, ft_get_pos(command, '\'') + 1, size - 1);
		ft_memmove(ft_strchr(command, '\'') - 1,
			ft_strrchr(command, '\'') + 1, size);
		command_array = ft_special_split(command, ' ');
		command_array[(sizeof(command_array) / sizeof(char *))] = deleted;
		return (command_array);
	}
	if (ft_strchr_count(command, '"') == 2)
	{
		size = (ft_strrchr(command, '"') - 
				ft_strchr(command, '"')) / sizeof(char);
		pos = ft_get_pos(command, '"');
		deleted = ft_substr(command, ft_get_pos(command, '"') + 1, size - 1);
		ft_memmove(ft_strchr(command, '"') - 1,
			ft_strrchr(command, '"') + 1, size);
		command_array = ft_special_split(command, ' ');
		command_array[(sizeof(command_array) / sizeof(char *))] = deleted;
		return (command_array);
	}
	command_array = ft_split(command, ' ');
	return (command_array);
}

// int	main(int argc, char **argv)
// {
// 	int		i;
// 	char	**command_array;

// 	command_array = ft_get_command_arg_array(argv[1]);
// 	i = 0;
// 	printf("string command: %s\n", command_array[i]);
// 	while (command_array[i])
// 	{
// 		printf("string command: %s\n", command_array[++i]);
// 	}
// }
