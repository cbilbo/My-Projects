#include "../libasm.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!new)
		return ;
	if (!*lst)
		*lst = new;
	else
	{
		new->next = *lst;
		*lst = new;
	}
}

void	printlist(t_list *list)
{
	t_list *temp;
	temp = list;
	if (!temp)
	{
		printf("Lists not existed.\n");
	}
	for (int i = 1; temp; i++)
	{
		printf("| %d = %s |", i, temp->content);
		temp = temp->next;
	}
	printf("\n");
}

void free_int(void *i)
{
	i = 0;
}

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list) * 1);
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

void free_ftc(void *data)
{
	if (data)
	{
		free(data);
		data = NULL;
	}

}

void ft_allocfree(void **data)
{
	if (*data)
	{
		free(*data);
		*data = NULL;
	}
}

int main(void)
{
	printf("\n==========ft_atoi_base==========\n");
	printf("str = 10011100011010101,------------------base = 01,-----------------atoi = %d\n", ft_atoi_base("10011100011010101", "01"));
	printf("str = \\n\\t ---+++--10011100011010101,-----base = 01,-----------------atoi = %d\n", ft_atoi_base("\n\t ---+++--10011100011010101", "01"));
	printf("str = -10011100011010101565100101101,-----base = 01,-----------------atoi = %d\n", ft_atoi_base("-1001110-0011010101", "01"));
	printf("str = 234325,-----------------------------base = 01234567,-----------atoi = %d\n", ft_atoi_base("234325", "01234567"));
	printf("str = 80085,------------------------------base = 0123456789,---------atoi = %d\n", ft_atoi_base("80085", "0123456789"));
	printf("str = 138d5,------------------------------base = 0123456789abcdef,---atoi = %d\n", ft_atoi_base("138d5", "0123456789abcdef"));
	printf("str = 138D5,------------------------------base = 0123456789ABCDEF,---atoi = %d\n", ft_atoi_base("138D5", "0123456789ABCDEF"));
	printf("str = 10011100011010101,------------------base = -01,----------------atoi = %d\n", ft_atoi_base("", ""));
	printf("str = \\n\\t ---+++--1001112000110101,------base = 01,-----------------atoi = %d\n", ft_atoi_base("\n\t ---+++--100111200011010101", "01"));
	printf("str = EMPTY,------------------------------base = 01,-----------------atoi = %d\n", ft_atoi_base("", "01"));
	printf("str = 121,--------------------------------base = EMPTY,--------------atoi = %d\n", ft_atoi_base("121", ""));
	

	t_list *list;
	list = NULL;
	printf("\n==========ft_list_push_front==========\n");
	ft_list_push_front(&list, ft_strdup("0"));
	ft_list_push_front(&list, ft_strdup("-"));
	ft_list_push_front(&list, ft_strdup("3"));
	ft_list_push_front(&list, ft_strdup("1"));
	ft_list_push_front(&list, ft_strdup("8"));
	ft_list_push_front(&list, ft_strdup("-"));
	ft_list_push_front(&list, ft_strdup("-"));
	ft_list_push_front(&list, ft_strdup("5"));
	printlist(list);
	printf("\n==========ft_list_size==========\n");
	printf(" libft = %d\n", ft_lstsize(list));
	printf(" libasm = %d\n", ft_list_size(list));
	printf("\n===========ft_list_sort==============\n");
	ft_list_sort(&list, ft_strcmp);
	printlist(list);
	printf("\n==========ft_list_remove_if==========\n");
	ft_list_remove_if(&list, "-", ft_strcmp, free_ftc);
	printlist(list);
	ft_list_remove_if(&list, "1", ft_strcmp, free_ftc);
	printlist(list);
	ft_list_remove_if(&list, "3", ft_strcmp, free_ftc);
	printlist(list);
	ft_list_remove_if(&list, "5", ft_strcmp, free_ftc);		
	printlist(list);
	ft_list_remove_if(&list, "8", ft_strcmp, free_ftc);
	printlist(list);
	ft_allocfree((void *)&list->content);
	free(list);
	return (0);
}