#include "config.h"

Test(ft_strdup, returns_string_duplicate)
{
	char	*s;
	char	*dup;

	s = STR;
	dup = ft_strdup(s);
	cr_expect(eq(str, s, dup),
		"ft_strdup: expected duplicate to match original");
	cr_expect(ne(ptr, s, dup),
		"ft_strdup: duplicate is pointing to original");
	free(dup);
}

Test(ft_strdup, creates_empty_string_duplicate)
{
	char 	*dup;
	char	*expected;

	dup = ft_strdup("");
	expected = strdup("");

	cr_expect(eq(str, dup, expected),
		"ft_strdup: expected duplicate of empty string to be created");
	free(dup);
	free(expected);
}
