/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaidaou <nbaidaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 12:02:52 by nbaidaou          #+#    #+#             */
/*   Updated: 2024/10/29 22:05:52 by nbaidaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*rp;
	t_list	*new;
	void	*content;

	if (!lst || !f || !del)
		return (NULL);
	rp = NULL;
	while (lst)
	{
		content = f(lst->content);
		new = ft_lstnew(content);
		if (new == NULL)
		{
			free(content);
			ft_lstclear(&rp, del);
			return (NULL);
		}
		ft_lstadd_back(&rp, new);
		lst = lst->next;
	}
	return (rp);
}
