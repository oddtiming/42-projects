#include "libft.h"

t_list	*ft_lstnew(void *data)
{
	t_list *new_node;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->content = data;
	new_node->next = NULL;
	return (new_node);
}