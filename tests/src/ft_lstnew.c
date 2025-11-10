#include "config.h"

Test(ft_lstnew, initializes_new_node_with_expected_values)
{
	t_list	*lst;
	char	*str;

	str = STR;
	lst = ft_lstnew(str);
	cr_expect(eq(ptr, lst->content, str),
		"ft_lstnew: expected string pointer to be stored in new node");
	cr_expect(zero(ptr, lst->next),
		"ft_lstnew: expected new node's next element to be null");
	free(lst);
}
