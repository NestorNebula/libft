#include "config.h"

Test(ft_strjoin, concatenates_strings)
{
	char	*join;

	join = ft_strjoin(STR1, STR2);
	cr_expect(zero(int, strncmp(join, STR1, strlen(STR1))),
		"ft_strjoin: expected first argument to be at start of concatenated string");
	cr_expect(zero(int, strcmp(join + strlen(STR2), STR2)),
		"ft_strjoin: expected second argument to be at end of concatenated string");
	free(join);
}
