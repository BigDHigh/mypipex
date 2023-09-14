/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnebatz <dnebatz@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 14:05:38 by dnebatz           #+#    #+#             */
/*   Updated: 2023/05/31 08:39:52 by dnebatz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;

	if (lst)
	{
		while ((*lst) != NULL)
		{
			tmp = (*lst)->next;
			ft_lstdelone((*lst), del);
			(*lst) = tmp;
		}
		lst = NULL;
	}
}

/*void nothing()
{};

void	ft_printlist(t_list *list);

int	main()
{
	t_list *tomato;
	t_list *beer;
	tomato = NULL;
	//tomato = ft_lstnew("tomato");
	t_list *apple;
	apple = ft_lstnew("apple");
	//apple = NULL;
	//beer = NULL;
	beer = ft_lstnew("beer");
	ft_lstadd_front(&tomato, apple);
	ft_lstadd_front(&tomato, ft_lstnew("paper"));
	ft_lstadd_front(&tomato, ft_lstnew("pencil"));
	ft_lstadd_back(&tomato, ft_lstnew("chewing gum"));
	ft_printlist(tomato);
	printf("uhm hello?\n");
	ft_lstclear(&tomato, nothing);
}*/