/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnebatz <dnebatz@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 10:03:31 by dnebatz           #+#    #+#             */
/*   Updated: 2023/05/31 08:39:44 by dnebatz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (lst)
	{
		if ((*lst) != NULL)
		{
			ft_lstlast((*lst))->next = new;
		}
		else
		{
			(*lst) = new;
		}
	}
}

/*void	ft_printlist(t_list *list);

int	main()
{
	t_list **buyinglist;
	t_list *tomato;
	t_list *beer;
	buyinglist = &tomato;
	tomato = NULL;
	//tomato = ft_lstnew("tomato");
	t_list *apple;
	apple = ft_lstnew("apple");
	//apple = NULL;
	//beer = NULL;
	beer = ft_lstnew("beer");
	ft_lstadd_front(&tomato, apple);
	ft_printlist(tomato);
	//ft_lstadd_front(&tomato, apple);
	//ft_lstadd_front(&tomato, ft_lstnew("paper"));
	//ft_lstadd_front(&tomato, ft_lstnew("pencil"));
	printf("uhm hello?\n");
	//ft_lstadd_back(NULL, NULL);
	ft_lstadd_back(&tomato, ft_lstnew("chewing gum"));
	// ft_lstadd_back(&tomato, NULL);
	// ft_lstadd_back(&tomato, ft_lstnew("rubber"));
	// ft_lstadd_back(&tomato, ft_lstnew("schnitzel"));
	ft_printlist(tomato);
}*/