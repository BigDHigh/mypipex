/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnebatz <dnebatz@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 10:07:28 by dnebatz           #+#    #+#             */
/*   Updated: 2023/07/17 18:17:19 by dnebatz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_get_pos(char *string)
{
	int	i;

	i = 0;
	while (*string && ++i)
	{
		if (*string == '\n')
			return (i);
		string++;
	}
	return (0);
}

static char	*ft_strcpy(char *buffer)
{
	int		i;
	char	*dst;
	int		len;

	i = -1;
	if (ft_strlen(buffer))
	{
		if (!ft_get_pos(buffer))
			len = ft_strlen(buffer);
		else
			len = ft_get_pos(buffer);
		dst = malloc((len + 1) * sizeof(char));
		if (!dst)
			return (0);
		while (buffer[++i] && buffer[i] != '\n')
			dst[i] = buffer[i];
		if (buffer[i] == '\n')
		{
			dst[i] = buffer[i];
			i++;
		}
		dst[i] = 0;
		return (dst);
	}
	return (0);
}

static int	ft_handle_buffer(char *buffer)
{
	int	pos;
	int	i;
	int	j;

	i = 0;
	pos = ft_get_pos(buffer);
	j = pos;
	if (pos)
	{
		while (buffer[pos])
		{
			buffer[i] = buffer[pos];
			i++;
			pos++;
		}
	}
	while (i <= BUFFER_SIZE)
		buffer[i++] = 0;
	return (j);
}

int	ft_check_buffer(char *buffer, int fd, t_list *s_list)
{
	int	i;
	int	not_found;

	i = 0;
	not_found = 1;
	if (ft_strlen(buffer))
		if (!ft_lstab(&s_list, ft_lstn(ft_strcpy(buffer))))
			return (-1);
	if (ft_get_pos(buffer))
		not_found = 0;
	ft_handle_buffer(buffer);
	if (not_found)
		i = read(fd, buffer, BUFFER_SIZE);
	if (i < 0)
		return (i);
	while (i > 0 && not_found)
	{
		if (!ft_lstab(&s_list, ft_lstn(ft_strcpy(buffer))))
			return (-1);
		if (ft_handle_buffer(buffer))
			break ;
		i = read(fd, buffer, BUFFER_SIZE);
	}
	return (i);
}

char	*get_next_line(int fd)
{
	static char	buffer[FOPEN_MAX][BUFFER_SIZE + 1];
	char		*ret_string;
	t_list		*string_list;
	char		start;

	start = '\0';
	if (fd < 0 || BUFFER_SIZE < 1 || FOPEN_MAX <= fd)
		return (0);
	string_list = ft_lstn(&start);
	if (!string_list)
		return (0);
	if (0 > ft_check_buffer(buffer[fd], fd, string_list))
	{
		ft_olstclear(&string_list);
		return (NULL);
	}
	ret_string = ft_list_to_str(string_list);
	ft_olstclear(&string_list);
	if (!ret_string || ret_string[0] == 0)
	{
		free(ret_string);
		return (NULL);
	}
	return (ret_string);
}
