#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	printf("**lst (first_node)'s content = %d\n", *(int *)(*lst)->content);	
	new->next = *lst;
	printf("Node's next content = %d", *(int *)new->next->content);
	*lst = new;
}