#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	t_list	*ptr;

	ptr = *lst;
	printf("**lst (first_node)'s content = %d\n", *(int *)ptr->content);	
	new->next = ptr;
	printf("Node's next content = %d", *(int *)new->next->content);
	*lst = new;
}