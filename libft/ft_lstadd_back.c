#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*ptr;

	if (lst)
	{
		ptr = *lst;
		while (ptr->next)
		{
			//printf("IN ft_lstadd_back, ptr_head->content = '%s'\nptr_head->next = %p\n", (char *)ptr->content, ptr->next);
			ptr = ptr->next;
			//printf("IN ft_lstadd_back, ptr_head->content = '%s'\nptr_head->next = %p\n", (char *)ptr->content, ptr->next);
		}
	//	printf("After the while loop, ptr_head->content = '%s'\nptr_head->next = %p\n", (char *)ptr->content, ptr->next);
		ptr->next = new;
	//	printf("After ptr_nead->next = new, ptr_head->content = '%s'\nptr_head->next = %p\n", (char *)ptr->content, ptr->next);
	//	printf("new->content = %s", (char *)new->content);
	}
}