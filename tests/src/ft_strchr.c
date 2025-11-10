#include "config.h"

Test(ft_strchr, returns_pointer_to_first_found_character)
{
	cr_expect(eq(ptr, ft_strchr(STR, 't'), strchr(STR, 't')),
		"ft_strchr: bad return value for first character occurrence");
}

Test(ft_strchr, returns_terminating_null_when_searching_it)
{
	cr_expect(eq(ptr, ft_strchr(STR, '\0'), strchr(STR, '\0')),
		"ft_strchr: bad return value when searching terminating null");
}

Test(ft_strchr, returns_null_when_character_not_found)
{
	cr_expect(eq(ptr, ft_strchr(STR, '-'), strchr(STR, '-')),
		"ft_strchr: bad return value when searching non-existent character");
}
