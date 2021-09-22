#include "libft.h"

t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*first_node;
	t_list	*node_buffer;

	if (!lst || !f || !del)
		return (NULL);
	first_node = ft_lstnew((*f)(lst->content));
	//check for null
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