#include "config.h"

static void	*returns_new_string(void *content)
{
	static const char	*new_str = STR2;

	(void) content;
	return ((void *) new_str);
}

static void	does_nothing(void *content)
{
	(void) content;
}

Test(ft_lstmap, creates_new_list_with_results)
{
	t_list	*lst;
	t_list	*new_lst;
	char	*s;

	s = STR;
	lst = ft_lstnew(s);
	ft_lstadd_back(&lst, ft_lstnew(s));
	new_lst = ft_lstmap(lst, returns_new_string, does_nothing);
	cr_expect(ne(ptr, new_lst, lst),
		"ft_lstmap: new list points to old list");
	cr_expect(eq(str, new_lst->content, STR2),
		"ft_lstmap: expected first node's content (%s) to match (%s)",
		new_lst->content, STR2);
	cr_expect(eq(str, new_lst->next->content, STR2),
		"ft_lstmap: expected second node's content (%s) to match (%s)",
		new_lst->next->content, STR2);
	free(new_lst->next);
	free(new_lst);
	free(lst->next);
	free(lst);
}
