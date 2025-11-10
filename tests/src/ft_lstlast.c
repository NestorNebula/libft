#include "config.h"

Test(ft_lstlast, returns_last_node_of_list)
{
	t_list	*lst;
	char	*str1;
	char	*str2;

	str1 = STR1;
	str2 = STR2;
	lst = ft_lstnew(str1);
	ft_lstadd_front(&lst, ft_lstnew(str2));
	cr_expect(eq(ptr, ft_lstlast(lst)->content, str1),
		"ft_lstlast: expected to return last list node");
	free(lst->next);
	free(lst);
}
