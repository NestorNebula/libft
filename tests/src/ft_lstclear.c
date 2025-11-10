#include "config.h"

static int	g_calls;

static void	increase_calls(void *content)
{
	cr_expect(eq(str, content, STR),
		"ft_lstclear: expected del to be called with node's content");
	g_calls++;
}

static void	do_nothing(void *content)
{
	(void) content;
}

Test(ft_lstclear, calls_del_for_each_node_content)
{
	t_list	*lst;
	char	*str;
	int		i;

	str = STR;
	lst = ft_lstnew(str);
	i = 0;
	while (i < SIZE)
	{
		ft_lstadd_back(&lst, ft_lstnew(str));
		i++;
	}
	g_calls = 0;
	ft_lstclear(&lst, increase_calls);
	cr_expect(eq(int, g_calls, SIZE + 1),
		"ft_lstclear: expected del to be called for each node's content");
}

Test(ft_lstclear, set_pointer_to_null_after_clear)
{
	t_list *lst;
	char *str;

	str = STR;
	lst = ft_lstnew(str);
	ft_lstclear(&lst, do_nothing);
	cr_expect(zero(ptr, lst),
		"ft_lstclear: expected list pointer to be set to NULL");
}
