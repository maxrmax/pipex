/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mring <mring@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 14:19:28 by mring             #+#    #+#             */
/*   Updated: 2023/11/09 19:59:23 by mring            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*n_list;
	t_list	*n_obj;
	void	*newcontent;

	if (!lst || !f || !del)
		return (NULL);
	n_list = NULL;
	while (lst)
	{
		newcontent = f(lst->content);
		if (!newcontent)
		{
			ft_lstclear(&n_list, del);
			return (NULL);
		}
		n_obj = ft_lstnew(newcontent);
		if (!n_obj)
		{
			ft_lstclear(&n_list, del);
			return (del(newcontent), NULL);
		}
		ft_lstadd_back(&n_list, n_obj);
		lst = lst->next;
	}
	return (n_list);
}
