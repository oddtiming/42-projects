#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		count;
	t_list	*ptr;

	count = 0;
	if (lst)
	{
		ptr = lst;
		count = 1;
		while (ptr->next)
		{
			count++;
			ptr = ptr->next;
		}
	}
	return (count);
}