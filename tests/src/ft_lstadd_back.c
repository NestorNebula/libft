#include "config.h"

Test(ft_lstadd_back, adds_new_node_to_end_of_list)
{
	t_list	*lst;
	char	*str1;
	char	*str2;

	str1 = STR1;
	str2 = STR2;
	lst = ft_lstnew(str1);
	ft_lstadd_back(&lst, ft_lstnew(str2));
	cr_expect(eq(ptr, lst->next->content, str2),
		"ft_lstadd_back: expected new node to be added at end of list");
	cr_expect(eq(ptr, lst->content, str1),
		"ft_lstadd_back: expected first node to stay at head of list");
	free(lst->next);
	free(lst);
}
