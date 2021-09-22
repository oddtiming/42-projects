#include "libft.h"

t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*first_node;
	t_list	*node_buffer;
	void	*content_buffer;

	if (!lst || !f || !del)
		return (NULL);
	first_node = lst;
	while (lst)
	{
		content_buffer = (*f)(lst->content);
		if (content_buffer)
		{
			node_buffer = lst;
			lst = ft_lstnew(content_buffer);
			if (!lst)
			{
				free(content_buffer);
				return (NULL);
			}
			lst->next = node_buffer->next;
			ft_lstdelone(node_buffer, del);
		}
		lst = lst->next;
	}
	return (first_node);
}