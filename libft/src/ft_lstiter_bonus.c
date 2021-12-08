/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyahoui- <iyahoui-@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 14:55:51 by iyahoui-          #+#    #+#             */
/*   Updated: 2021/12/06 12:09:17 by iyahoui-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (lst && f)
	{
		while (lst)
		{
			(*f)(lst->content);
			lst = lst->next;
		}
	}
}

void	ft_lstiter_add(t_list *lst, void (*f)(void *, t_list *))
{
	t_list	*lst_head;

	lst_head = lst;
	if (lst && f)
	{
		while (lst)
		{
			(*f)(lst->content, lst_head);
			lst = lst->next;
		}
	}
}
