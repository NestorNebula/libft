#include "config.h"

Test(ft_lstsize, returns_size_of_list)
{
	t_list	*lst;
	t_list	*tmp;
	char	*str;
	int		i;

	str = STR;
	lst = ft_lstnew(str);
	i = 0;
	while (i < SIZE)
	{
		ft_lstadd_front(&lst, ft_lstnew(str));
		i++;
	}
	cr_expect(eq(int, ft_lstsize(lst), SIZE + 1),
		"ft_lstsize: expected to return list size (%d) but got %d", 
		SIZE + 1, ft_lstsize(lst));
	while (lst != NULL)
	{
		tmp = lst;
		lst = lst->next;
		free(tmp);
	}
}
