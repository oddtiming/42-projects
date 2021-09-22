#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*ptr;
	t_list	*buffer;

	if (lst && del)
	{
		ptr = *lst;
		while (ptr)
		{
			buffer = ptr->next;
			ft_lstdelone(ptr, del);
			ptr = buffer;
		}
	}
	*lst = NULL;
}