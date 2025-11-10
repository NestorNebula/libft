#include "config.h"

Test(ft_strncmp, returns_zero_when_comparing_equivalent_strings)
{
	cr_expect(zero(int, ft_strncmp(STR1, STR2, strlen(STR1) - 1)),
		"ft_strncmp: expected ft_strncmp to return zero for equal strings");
}

Test(ft_strncmp, returns_non_zero_when_comparing_different_strings)
{
	cr_expect(ne(int, ft_strncmp(STR1, STR2, strlen(STR2)), 0),
		"ft_strncmp: expected ft_strncmp to return non-zero for non-equal strings");
}
