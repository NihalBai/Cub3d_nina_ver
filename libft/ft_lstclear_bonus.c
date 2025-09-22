/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbaidaou <nbaidaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 11:35:42 by nbaidaou          #+#    #+#             */
/*   Updated: 2024/10/29 18:36:01 by nbaidaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*here;
	t_list	*temp;

	if (lst && del)
	{
		here = *lst;
		while (here)
		{
			temp = here->next;
			del(here->content);
			free(here);
			here = temp;
		}
		*lst = NULL;
	}
}
