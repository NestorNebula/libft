#include "config.h"

Test(ft_strrchr, returns_pointer_to_first_found_character_from_end)
{
	cr_expect(eq(ptr, ft_strrchr(STR, 't'), strrchr(STR, 't')),
		"ft_strrchr: bad return value for first found character from end");
}

Test(ft_strrchr, returns_pointer_to_termination_null_when_searchint_it)
{
	cr_expect(eq(ptr, ft_strrchr(STR, '\0'), strrchr(STR, '\0')),
		"ft_strrchr: bad return value for terminating null search");
}

Test(ft_strrchr, returns_null_when_character_not_found)
{
	cr_expect(eq(ptr, ft_strrchr(STR, '-'), strrchr(STR, '-')),
		"ft_strrchr: bad return value for non-existent character");
}
