#include "config.h"

Test(ft_memcmp, returns_zero_for_equivalent_strings)
{
	cr_expect(zero(int, ft_memcmp(STR, STR2, strlen(STR))),
		"ft_memcmp: expected to return zero for equivalent strings");
}

Test(ft_memcmp, returns_non_zero_for_different_strings)
{
	cr_expect(ne(int, ft_memcmp(STR, STR2, strlen(STR2)), 0),
		"ft_memcmp: expected to return non-zero value for different strings");
}
