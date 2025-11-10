#include "config.h"

#define LSTITER_CHAR 'c'

static void	increase_first_char(void *content)
{
	((char *) content)[0]++;
}

Test(ft_lstiter, calls_f_on_each_node_content)
{
	t_list	*lst;
	char	c;

	
	c = LSTITER_CHAR;
	lst = ft_lstnew(&c);
	ft_lstadd_back(&lst, ft_lstnew(&c));
	ft_lstiter(lst, increase_first_char);
	cr_expect(eq(int, ((char *) lst->content)[0], LSTITER_CHAR + 2),
		"ft_lstiter: expected first node content's first char to have been set \
		to %c", LSTITER_CHAR + 2);
	cr_expect(eq(int, ((char *) lst->next->content)[0], LSTITER_CHAR + 2),
		"ft_lstiter: expected second node content's first char to have been set \
		to %c", LSTITER_CHAR + 2);
	free(lst->next);
	free(lst);
}
