#include "libft.h"

/*
** EXTRA TEST FUNCTIONS
*/
void	lst_del_fct(void *data)
{
	free (data);
}

void	lst_touppcase(void *data)
{
	int		i;
	char	*str_ptr;

	i = 0;
	str_ptr = (char *)data;
	if (!data)
		return ;
	while (str_ptr[i])
	{
		if (str_ptr[i] >= 'a' && str_ptr[i] <= 'z')
			str_ptr[i] -= 32;
		i++;
	}
}
/*
//Try with no duplicate
void	*lst_fct_simple(void *data)
{
	int		i;
	char	*str_ptr;

	i = 0;
	str_ptr = (char *)data;
	if (!data)
		return ;
	while (str_ptr[i])
	{
		if (str_ptr[i] >= 'a' && str_ptr[i] <= 'z')
			str_ptr[i] -= 32;
		i++;
	}
	return (str_ptr);
}

void	*lst_touppcase_map(void *data)
{
	int		i;
	char	*str_ptr;

	i = 0;
	str_ptr = (char *)data;
	if (!data)
		return NULL;
	while (str_ptr[i])
	{
		if (str_ptr[i] >= 'a' && str_ptr[i] <= 'z')
			str_ptr[i] -= 32;
		i++;
	}
	return (str_ptr);
}
*/

void	*lst_touppcase_map(void *data)
{
	int		i;
	char	*str_ptr;
	char	*str_dup;

	i = 0;
	str_ptr = (char *)data;
	if (!data)
		return (NULL);
	str_dup = ft_strdup(str_ptr);
	if (!str_dup)
		return (NULL);
	while (str_dup[i])
	{
		if (str_dup[i] >= 'a' && str_dup[i] <= 'z')
			str_dup[i] -= 32;
		i++;
	}
	if (!ft_strncmp(str_dup, str_ptr, ft_strlen(str_ptr)))
	{
		free(str_dup);
		return (NULL);
	}
	return(str_dup);
}

//need to change the nodes' contents to individual assignation && fix memory leaks
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
	int		nb_structs;
	t_list	*first_node;
	t_list	*ptr_head;
	char	*s0;
	char	*s1;
	char	*s2;
	char	*s3;
	char	*strs[4];
	
	nb_structs = 4;
	s0 = ft_strdup("This is the 1st string");
	s1 = ft_strdup("This is the 2nd string");
	s2 = ft_strdup("This is the 3rd string");
	s3 = ft_strdup("This is the string to be added");
	strs[0] = s0;
	strs[1] = s1;
	strs[2] = s2;
	
	ptr_head = ft_lstnew(strs[0]);
	first_node = ptr_head;
	for (int i = 1; i < nb_structs; i++)
	{
		ptr_head->next = ft_lstnew(strs[i]);
		ptr_head = ptr_head->next;
	}
	ptr_head = first_node;
	for (int i = 0; i < nb_structs - 1; i++)
	{
		printf("Content[%d] = '%s'\n", i, (char *)ptr_head->content);
		ptr_head = ptr_head->next;
	}
	ft_lstadd_front(&first_node, ft_lstnew(s3));
	printf("\nAfter ft_lstadd_front:\n");
	ptr_head = first_node;
	for (int i = 0; i < nb_structs; i++)
	{
		printf("Content[%d] = '%s'\n", i, (char *)(ptr_head->content));
		ptr_head = ptr_head->next;
	}
	printf("\n");
	ft_lstclear(&first_node, &lst_del_fct);
}

//need to change the nodes' contents to individual assignation && fix memory leaks
void	ft_lstsize_test(void)
{
	//Tests for ft_lstsize
	printf("-------------------------\n###Tests for ft_lstsize###\n-------------------------\n");
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
	printf("The total number of elements = %d\n", ft_lstsize(first_node));
	printf("\n");
	for (i = 0; i < nb_structs; i++)
	{
		ptr_head = first_node->next;
		free (first_node);
		first_node = ptr_head;
	}
}

//need to change the nodes' contents to individual assignation && fix memory leaks
void	ft_lstlast_test(void)
{
	//Tests for ft_lstlast
	printf("-------------------------\n###Tests for ft_lstlast###\n-------------------------\n");
	int		i;
	int		nb_structs;
	t_list	*first_node;
	t_list	*ptr_head;

	i = 0;
	nb_structs = 7;
	ptr_head = malloc(sizeof(t_list));
	if(!ptr_head)
	{
		ptr_head = NULL;
		return ;
	}
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

void	ft_lstadd_back_test(void)
{
	printf("-------------------------\n###Tests for ft_lstadd_back###\n-------------------------\n");
	int		nb_structs;
	t_list	*first_node;
	t_list	*ptr_head;
	char	*s0;
	char	*s1;
	char	*s2;
	char	*s3;
	char	*strs[4];
	
	nb_structs = 4;
	s0 = ft_strdup("This is the 1st string");
	s1 = ft_strdup("This is the 2nd string");
	s2 = ft_strdup("This is the 3rd string");
	s3 = ft_strdup("This is the string to be added");
	strs[0] = s0;
	strs[1] = s1;
	strs[2] = s2;
	
	ptr_head = ft_lstnew(strs[0]);
	first_node = ptr_head;
	//Sets the linked list
	for (int i = 1; i < nb_structs - 1; i++)
	{
		ptr_head->next = ft_lstnew(strs[i]);
		ptr_head = ptr_head->next;
	}
	ptr_head = first_node;
	for (int i = 0; i < nb_structs - 1; i++)
	{
		printf("Content[%d] = '%s'\n", i, (char *)ptr_head->content);
		ptr_head = ptr_head->next;
	}
	ft_lstadd_back(&first_node, ft_lstnew(s3));
	printf("\nAfter ft_lstadd_back:\n");
	ptr_head = first_node;
	for (int i = 0; i < nb_structs; i++)
	{
		printf("Content[%d] = '%s'\n", i, (char *)(ptr_head->content));
		ptr_head = ptr_head->next;
	}
	printf("\n");
	ft_lstclear(&first_node, &lst_del_fct);
}

void	ft_lstdelone_test(void (*del)(void *))
{
	printf("-------------------------\n###Tests for ft_lstdelone###\n-------------------------\n");
	int		nb_structs;
	t_list	*first_node;
	t_list	*ptr_head;
	char	*s0;
	char	*s1;
	char	*s2;
	char	*strs[3];
	
	nb_structs = 4;
	s0 = ft_strdup("This is the 1st string");
	s1 = ft_strdup("This is the 2nd string");
	s2 = ft_strdup("This is the 3rd string");
	strs[0] = s0;
	strs[1] = s1;
	strs[2] = s2;
	

	ptr_head = ft_lstnew(strs[0]);
	first_node = ptr_head;
	//Sets the linked list
	for (int i = 1; i < nb_structs - 1; i++)
	{
		ptr_head->next = ft_lstnew(strs[i]);
		ptr_head = ptr_head->next;
	}
	ptr_head = first_node;
	//Prints the list's nodes' contents
	for (int i = 0; i < nb_structs - 1; i++)
	{
		printf("Content[%d] = '%s'\n", i, (char *)ptr_head->content);
		ptr_head = ptr_head->next;
	}
	printf("\nAfter ft_lstdelone on first_node->next (second node) and relinking 1st node to 3rd:\n");
	
	//Delinking the second node and reattaching 1st to 3rd:
	ptr_head = first_node->next->next;
	ft_lstdelone(first_node->next, del);
	first_node->next = ptr_head;
	ptr_head = first_node;
	
	for (int i = 0; i < nb_structs - 2; i++)
	{
		printf("Content[%d] = '%s'\n", i, (char *)(ptr_head->content));
		ptr_head = ptr_head->next;
	}
	printf("\n");
	//
	//FIX A MEMORY LEAK
	//
	ft_lstclear(&first_node, del);
}

void	ft_lstclear_test(void (*del)(void *))
{
	printf("-------------------------\n###Tests for ft_lstclear###\n-------------------------\n");
	int		nb_structs;
	t_list	*first_node;
	t_list	*ptr_head;
	char	*s0;
	char	*s1;
	char	*s2;
	char	*s3;
	char	*s4;
	char	*strs[5];
	
	nb_structs = 5;
	s0 = ft_strdup("This is the 1st string");
	s1 = ft_strdup("This is the 2nd string");
	s2 = ft_strdup("This is the 3rd string");
	s3 = ft_strdup("This is the 4th string");
	s4 = ft_strdup("This is the 5th string");
	strs[0] = s0;
	strs[1] = s1;
	strs[2] = s2;
	strs[3] = s3;
	strs[4] = s4;
	
	ptr_head = ft_lstnew(strs[0]);
	first_node = ptr_head;
	//Sets the linked list
	for (int i = 1; i < nb_structs; i++)
	{
		ptr_head->next = ft_lstnew(strs[i]);
		ptr_head = ptr_head->next;
	}
	ptr_head = first_node;
	//Prints the list's nodes' contents
	for (int i = 0; ptr_head; i++)
	{
		printf("Content[%d] = '%s'\n", i, (char *)ptr_head->content);
		ptr_head = ptr_head->next;
	}
	printf("\nAfter ft_lstclear on first_node->next->next (third node):\n");
	
	//Clearing the third node onwards:
	ft_lstclear(&first_node->next->next, del);
	ptr_head = first_node;
	for (int i = 0; ptr_head; i++)
	{
		printf("Content[%d] = '%s'\n", i, (char *)(ptr_head->content));
		ptr_head = ptr_head->next;
	}
	printf("\n");
	ft_lstclear(&first_node, del);
}

void	ft_lstiter_test(void (*iter_fct)(void *))
{
	printf("-------------------------\n###Tests for ft_lstiter###\n-------------------------\n");
	int		nb_structs;
	t_list	*first_node;
	t_list	*ptr_head;
	char	*s0;
	char	*s1;
	char	*s2;
	char	*s3;
	char	*s4;
	char	*strs[5];
	
	nb_structs = 5;
	s0 = ft_strdup("This is the 1st string");
	s1 = ft_strdup("This is the 2nd string");
	s2 = ft_strdup("This is the 3rd string");
	s3 = ft_strdup("This is the 4th string");
	s4 = ft_strdup("This is the 5th string");
	strs[0] = s0;
	strs[1] = s1;
	strs[2] = s2;
	strs[3] = s3;
	strs[4] = s4;
	
	ptr_head = ft_lstnew(strs[0]);
	first_node = ptr_head;
	//Sets the linked list
	for (int i = 1; i < nb_structs; i++)
	{
		ptr_head->next = ft_lstnew(strs[i]);
		ptr_head = ptr_head->next;
	}
	ptr_head = first_node;
	//Prints the list's nodes' contents
	for (int i = 0; ptr_head; i++)
	{
		printf("Content[%d] = '%s'\n", i, (char *)ptr_head->content);
		ptr_head = ptr_head->next;
	}
	printf("\nAfter ft_lstiter on first_node:\n");
	
	ft_lstiter(first_node, iter_fct);
	ptr_head = first_node;
	for (int i = 0; ptr_head; i++)
	{
		printf("Content[%d] = '%s'\n", i, (char *)(ptr_head->content));
		ptr_head = ptr_head->next;
	}
	printf("\n");
	ft_lstclear(&first_node, &lst_del_fct);
}

//NEEDS TO BE DEBUGGED BIG TIME
void	ft_lstmap_test(void *(*map_fct)(void *), void (*del)(void *))
{
	printf("-------------------------\n###Tests for ft_lstmap###\n-------------------------\n");
	int		nb_structs;
	t_list	*first_node;
	t_list	*ptr_head;
	char	*s0;
	char	*s1;
	char	*s2;
	char	*s3;
	char	*s4;
	char	*strs[5];
	
	nb_structs = 5;
	s0 = ft_strdup("This is the 1st string");
	s1 = ft_strdup("TEST");
	s2 = ft_strdup("This is the 3rd string");
	s3 = ft_strdup("This is the 4th string");
	s4 = ft_strdup("This is the 5th string");
	strs[0] = s0;
	strs[1] = s1;
	strs[2] = s2;
	strs[3] = s3;
	strs[4] = s4;
	
	ptr_head = ft_lstnew(strs[0]);
	first_node = ptr_head;
	//Sets the linked list
	for (int i = 1; i < nb_structs; i++)
	{
		ptr_head->next = ft_lstnew(strs[i]);
		ptr_head = ptr_head->next;
	}
	ptr_head = first_node;
	//Prints the list's nodes' contents
	for (int i = 0; ptr_head; i++)
	{
		printf("Content[%d] = '%s'\n", i, (char *)ptr_head->content);
		ptr_head = ptr_head->next;
	}
	printf("\nAfter ft_lstmap on first_node->next->next (third node):\n");
	
	//Printing the return content of ft_lstmap + clearing the two lists:
	ptr_head = ft_lstmap(first_node, map_fct, del);
	for (int i = 0; ptr_head; i++)
	{
		printf("Content[%d] = '%s'\n", i, (char *)(ptr_head->content));
		ptr_head = ptr_head->next;
	}
	printf("\n");
	ft_lstclear(&ptr_head, &lst_del_fct);
	ft_lstclear(&first_node, &lst_del_fct);
}
/*
void	ft_lstmap_test_simple(void *(*map_fct)(void *), void (*del)(void *))
{
	printf("-------------------------\n###SIMPLE Tests for ft_lstmap###\n-------------------------\n");
	t_list	*first_node;
	t_list	*ptr_head;
	char	*s0;
	char	*s1;
	char	*s2;
	char	*strs[5];
	int		nb_stucts;
	
	nb_structs = 5;
	s0 = ft_strdup("This is the 1st string");
	s1 = ft_strdup("TEST");
	s2 = ft_strdup("This is the 3rd string");
	s3 = ft_strdup("This is the 4th string");
	s4 = ft_strdup("This is the 5th string");
	strs[0] = s0;
	strs[1] = s1;
	strs[2] = s2;
	strs[3] = s3;
	strs[4] = s4;
	
	ptr_head = ft_lstnew(strs[0]);
	first_node = ptr_head;
	//Sets the linked list
	for (int i = 1; i < nb_structs; i++)
	{
		ptr_head->next = ft_lstnew(strs[i]);
		ptr_head = ptr_head->next;
	}
	ptr_head = first_node;
	//Prints the list's nodes' contents
	for (int i = 0; ptr_head; i++)
	{
		printf("Content[%d] = '%s'\n", i, (char *)ptr_head->content);
		ptr_head = ptr_head->next;
	}
	printf("\nAfter ft_lstmap on first_node->next->next (third node):\n");
	
	//Clearing the third node onwards:
	ptr_head = ft_lstmap(first_node, map_fct, del);
	for (int i = 0; ptr_head; i++)
	{
		printf("Content[%d] = '%s'\n", i, (char *)(ptr_head->content));
		ptr_head = ptr_head->next;
	}
	printf("\n");
	ft_lstclear(&ptr_head, &lst_del_fct);
}
*/
int	main(void)
{
	void	(*del_fct)(void *);
	void	(*iter_fct)(void *);
	void	*(*map_fct)(void *);
	void	*(*map_fct_simple)(void *);

	del_fct = &lst_del_fct;
	iter_fct = &lst_touppcase;
	map_fct = &lst_touppcase_map;
	//map_fct_simple = &lst_fct_simple;
	ft_lstnew_test();
	ft_lstadd_front_test();
	ft_lstsize_test();
	ft_lstlast_test();
	ft_lstadd_back_test();
	ft_lstdelone_test(del_fct);
	ft_lstclear_test(del_fct);
	ft_lstiter_test(iter_fct);
	ft_lstmap_test(map_fct, del_fct);
	//ft_lstmap_test_simple(map_fct, del_fct);
	return (0);
}

/*
**leaks command:
leaks --atExit -- ./a.out
*/