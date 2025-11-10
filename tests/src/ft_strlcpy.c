#include "config.h"

#define STRLCPY_SIZE 20

Test(ft_strlcpy, returns_expected_values)
{
	char	dest[STRLCPY_SIZE];

	cr_expect(eq(int, strlcpy(dest, STR, STRLCPY_SIZE),
				ft_strlcpy(dest, STR, SIZE)),
		"ft_strlcpy: bad return value when copying full string");
	cr_expect(
		eq(int, strlcpy(dest, STR, STRLCPY_SIZE / 2),
			ft_strlcpy(dest, STR, SIZE / 2)),
		"ft_strlcpy: bad return value when copying part of string");
}

Test(ft_strlcpy, copies_full_string)
{
	char	dest[STRLCPY_SIZE];

	ft_strlcpy(dest, STR, STRLCPY_SIZE);
	cr_expect(zero(int, strcmp(dest, STR)),
		"ft_strlcpy: expected src to be completely copied");
}

Test(ft_strlcpy, copies_part_of_string)
{
	char	dest[STRLCPY_SIZE];

	ft_strlcpy(dest, STR, STRLCPY_SIZE / 2);
	cr_expect(zero(int, strncmp(dest, STR, STRLCPY_SIZE / 2 - 1)),
		"ft_strlcpy: expected src first %d characters to be copied to dest",
		STRLCPY_SIZE / 2 - 1);
}
