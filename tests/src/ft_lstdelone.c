#include "config.h"

static int	g_calls;

static void	check_content(void *content)
{
	cr_expect(eq(str, content, STR),
		"ft_lstdelone: expected node's content to be passed as argument to del");
	g_calls++;
}

Test(ft_lstdelone, calls_del_for_node_content)
{
	t_list	*node;
	char	*str;

	str = STR;
	node = ft_lstnew(str);
	ft_lstdelone(node, check_content);
	cr_expect(eq(int, g_calls, 1),
		"ft_lstdelone: expected del to be called");
}
