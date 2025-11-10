#include "config.h"

Test(ft_memchr, returns_pointer_to_first_occurrence_found)
{
	cr_expect(eq(ptr, ft_memchr((void *) STR, 't', strlen(STR)),
				memchr((void *) STR, 't', strlen(STR))),
		"ft_memchr: bad return value for first occurrence");
}

Test(ft_memchr, returns_null_when_not_found)
{
	cr_expect(eq(ptr, ft_memchr((void *) STR, '-', strlen(STR)),
				memchr((void *) STR, '-', strlen(STR))),
		"ft_memchr: bad return value when not found");
}
