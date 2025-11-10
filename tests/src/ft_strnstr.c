#include "config.h"

#define STRNSTR_STR "strnstr test string"
#define STRNSTR_BIG_N 10000

Test(ft_strnstr, returns_pointer_to_substring_when_found)
{
	cr_expect(eq(ptr, ft_strnstr(STR, SUBSTR, strlen(STR)),
				strnstr(STR, SUBSTR, strlen(STR))),
		"ft_strnstr: bad return value when substring is found");
}

Test(ft_strnstr, returns_null_when_substring_not_found)
{
	cr_expect(zero(ptr, ft_strnstr(STR, SUBSTR, strlen(SUBSTR))),
		"ft_strnstr: expected to return null when substring not found");
}

Test(ft_strnstr, returns_string_when_substring_is_empty)
{
	char	*str;

	str = STR;
	cr_expect(eq(ptr, ft_strnstr(str, "", strlen(str)), str),
		"ft_strnstr: expected to return pointer to string on empty substring");
}

Test(ft_strnstr, doenst_return_unexpectd_value_on_big_n)
{
	char	*str;
	char	*str2;

	str = STR;
	str2 = STRNSTR_STR;
	cr_expect(zero(ptr, ft_strnstr(str, str2, STRNSTR_BIG_N)),
		"ft_strnstr: expected to return null when substring not found \
		despite big n");
}
