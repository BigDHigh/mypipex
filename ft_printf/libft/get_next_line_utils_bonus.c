/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnebatz <dnebatz@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 10:26:33 by dnebatz           #+#    #+#             */
/*   Updated: 2023/07/17 18:23:31 by dnebatz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstn(void *content)
{
	t_list	*tmp;

	if (!(content))
		return (0);
	tmp = malloc(sizeof(t_list));
	if (!tmp)
		return (0);
	if (tmp)
	{
		tmp->content = content;
		tmp->next = NULL;
	}
	return (tmp);
}

int	ft_lstab(t_list **lst, t_list *new)
{
	t_list	*tmp;

	tmp = (*lst);
	if (!new)
		return (0);
	if (!lst)
		return (0);
	if ((tmp) != NULL)
	{
		while ((tmp)->next != NULL)
			(tmp) = (tmp)->next;
		(tmp)->next = new;
	}
	else
		(*lst) = new;
	return (1);
}

void	ft_olstclear(t_list **lst)
{
	t_list	*tmp;

	if (lst)
	{
		tmp = (*lst)->next;
		free(*lst);
		(*lst) = tmp;
		while ((*lst) != NULL)
		{
			tmp = (*lst)->next;
			free((*lst)->content);
			(*lst)->content = NULL;
			free(*lst);
			*lst = tmp;
		}
		lst = NULL;
	}
}

char	*ft_list_to_str(t_list *list)
{
	t_list	*tmp;
	size_t	i;
	int		j;
	char	*ret;

	i = 0;
	j = 0;
	tmp = list;
	while (tmp != NULL)
	{
		i = i + ft_strlen(tmp->content);
		tmp = tmp->next;
	}
	ret = malloc((i + 1) * sizeof(char));
	if (!ret)
		return (NULL);
	while (list != NULL)
	{
		i = -1;
		while (((char *)list->content)[++i])
			ret[j++] = ((char *)list->content)[i];
		ret[j] = 0;
		list = list->next;
	}
	return (ret);
}
