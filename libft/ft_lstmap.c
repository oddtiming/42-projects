#include "libft.h"

t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*first_node_lst;
	t_list	*first_node_cpy;
	t_list	*node_buffer;

	if (!lst || !f || !del)
		return (NULL);
	first_node_lst = lst;
	//check for null
	node_buffer = ft_lstnew((*f)(lst->content));
	if (!node_buffer)
		return (NULL);
	first_node_cpy = node_buffer;
	lst = lst->next;
	node_buffer = node_buffer->next;
	while (lst)
	{
		node_buffer = ft_lstnew((*f)(lst->content));
		if (!node_buffer)
		{
			ft_lstclear(&first_node_cpy, del);
			return (NULL);
		}
		node_buffer = node_buffer->next;
		lst = lst->next;
	}
	ft_lstclear(&first_node_lst, del);
	return (first_node_cpy);
}