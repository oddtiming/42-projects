/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyahoui- <iyahoui-@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 14:56:08 by iyahoui-          #+#    #+#             */
/*   Updated: 2021/09/22 14:57:05 by iyahoui-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*first_node;
	t_list	*node_buffer;

	if (!lst || !f || !del)
		return (NULL);
	first_node = ft_lstnew((*f)(lst->content));
	if (!first_node)
		return (NULL);
	node_buffer = lst->next;
	while (node_buffer)
	{
		ft_lstadd_back(&first_node, ft_lstnew((*f)(node_buffer->content)));
		if (!node_buffer)
		{
			ft_lstclear(&first_node, del);
			return (NULL);
		}
		node_buffer = node_buffer->next;
	}
	ft_lstclear(&lst, del);
	return (first_node);
}
