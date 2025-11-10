#include "config.h"

Test(ft_lstadd_front, add_new_node_to_list_beginning)
{
	t_list	*lst;
	t_list	*new;
	char	*str1;
	char	*str2;

	str1 = STR1;
	str2 = STR2;
	lst = ft_lstnew(str1);
	new = ft_lstnew(str2);
	ft_lstadd_front(&lst, new);
	cr_expect(eq(ptr, lst->content, str2),
		"ft_lstadd_front: expected new node to be set at list beginning");
	cr_expect(eq(ptr, lst->next->content, str1),
		"ft_lstadd_front: expected previous list head to be keeped as next node");
	free(lst->next);
	free(lst);
}
