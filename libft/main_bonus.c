#include "libft.h"

void	ft_lstnew_test(void)
{
	//Tests for ft_lstnew
	printf("-------------------------\n###Tests for ft_lstnew###\n-------------------------\n");
	int		i;
	int		nb_structs;
	t_list	*first_node;
	t_list	*ptr_head;

	i = 0;
	nb_structs = 7;
	ptr_head = malloc(sizeof(t_list));
	if(!ptr_head)
		ptr_head = NULL;
	ptr_head->content = &i;
	first_node = ptr_head;
	for (i = 1; i < nb_structs; i++)
	{
		ptr_head->next = ft_lstnew(&i);
		ptr_head = ptr_head->next;
	}
	ptr_head->next = NULL;
	ptr_head = first_node;
	for (i = 0; i < nb_structs; i++)
	{
		printf("Content[%d] = '%d'\n", i, *(int *)(ptr_head->content));
		ptr_head = ptr_head->next;
	}
	printf("\n");
	for (i = 0; i < nb_structs; i++)
	{
		ptr_head = first_node->next;
		free (first_node);
		first_node = ptr_head;
	}
}

void	ft_lstadd_front_test(void)
{
	//Tests for ft_lstadd_front
	printf("-------------------------\n###Tests for ft_lstadd_front###\n-------------------------\n");
	int		i;
	int		nb_structs;
	t_list	*first_node;
	t_list	*ptr_head;

	i = 0;
	nb_structs = 7;
	ptr_head = malloc(sizeof(t_list));
	if(!ptr_head)
		ptr_head = NULL;
	ptr_head->content = &i;
	first_node = ptr_head;
	for (i = 1; i < nb_structs; i++)
	{
		ptr_head->next = ft_lstnew(&i);
		ptr_head = ptr_head->next;
	}
	ptr_head = first_node;
	printf("Initial value of first_node->content: '%d'\n", *(int *)first_node->content);
	for (i = 0; i < nb_structs; i++)
	{
		printf("Content[%d] = '%d'\n", i, *(int *)(ptr_head->content));
		ptr_head = ptr_head->next;
	}
	printf("After printing value of first_node->content: '%d'\n", *(int *)first_node->content);
	ft_lstadd_front(&first_node, ft_lstnew(&nb_structs));
	printf("\nAfter ft_lstadd_front:\n");
	ptr_head = first_node;
	for (i = 0; i <= nb_structs; i++)
	{
		printf("Content[%d] = '%d'\n", i, *(int *)(ptr_head->content));
		ptr_head = ptr_head->next;
	}
	printf("\n");
	for (i = 0; i < nb_structs; i++)
	{
		ptr_head = first_node->next;
		free (first_node);
		first_node = ptr_head;
	}
}

void	ft_lstadd_back_test(void)
{
	//Tests for ft_lstadd_back
	printf("-------------------------\n###Tests for ft_lstadd_back###\n-------------------------\n");
	int		i;
	int		nb_structs;
	t_list	*first_node;
	t_list	*ptr_head;

	i = 0;
	nb_structs = 7;
	ptr_head = malloc(sizeof(t_list));
	if(!ptr_head)
		ptr_head = NULL;
	ptr_head->content = &i;
	first_node = ptr_head;
	for (i = 1; i < nb_structs; i++)
	{
		ptr_head->next = ft_lstnew(&i);
		ptr_head = ptr_head->next;
	}
	ptr_head = first_node;
	for (i = 0; i < nb_structs; i++)
	{
		printf("Content[%d] = '%d'\n", i, *(int *)(ptr_head->content));
		ptr_head = ptr_head->next;
	}
	ft_lstadd_back(&first_node, ft_lstnew(&nb_structs));
	printf("This one was added by ft_lstadd_back:\n");
	ptr_head = first_node;
	while (ptr_head->next)
		ptr_head = ptr_head->next;
	printf("Content[%d] = '%d'\n\n", nb_structs, *(int *)ptr_head->content);
	for (i = 0; i < nb_structs; i++)
	{
		ptr_head = first_node->next;
		free (first_node);
		first_node = ptr_head;
	}
}

int	main(void)
{
	ft_lstnew_test();
	ft_lstadd_front_test();

	//ft_lstadd_back_test();
}