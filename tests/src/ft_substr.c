#include "config.h"

#define SUBSTR_START 3
#define SUBSTR_LEN 3

Test(ft_substr, returns_malloced_substring)
{
	char	*s;
	char	*substr;

	s = STR;
	substr = ft_substr(s, SUBSTR_START, SUBSTR_LEN);
	cr_expect(zero(int, strncmp(s + SUBSTR_START, substr, SUBSTR_LEN)),
		"ft_substr: expected substr to be a substring of the original string");
	cr_expect(ne(ptr, substr, s),
		"ft_substr: substr is pointing to the original string");
	free(substr);
}

Test(ft_substr, copies_until_end_of_string)
{
	char	*s;
	char	*substr;

	s = STR;
	substr = ft_substr(s, SUBSTR_START, strlen(s) * 2);
	cr_expect(zero(int, strcmp(s + SUBSTR_START, substr)),
		"ft_substr: expected substr to match end of original string");
	free(substr);
}
