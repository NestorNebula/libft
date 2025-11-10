#include "config.h"

#define STRLCAT_SIZE 20

Test(ft_strlcat, return_expected_values)
{
	char	dest[STRLCAT_SIZE];
	int		expected;

	dest[0] = '\0';
	expected = strlcat(dest, STR, STRLCAT_SIZE);
	dest[0] = '\0';
	cr_expect(eq(int, ft_strlcat(dest, STR, STRLCAT_SIZE), expected),
		"ft_strlcat: bad return value when concatenating entire string");
	expected = strlcat(dest, STR, STRLCAT_SIZE);
	dest[strlen(STR)] = '\0';
	cr_expect(eq(int, ft_strlcat(dest, STR, STRLCAT_SIZE), expected),
		"ft_strlcat: bad return value when concatenating part of string");
	cr_expect(eq(int, strlcat(dest, STR, STRLCAT_SIZE),
				ft_strlcat(dest, STR, STRLCAT_SIZE)),
		"ft_strlcat: bad return value when concatenating on full string");
}

Test(ft_strlcat, concats_full_string)
{
	char	dest[STRLCAT_SIZE];

	dest[0] = '\0';
	ft_strlcat(dest, STR, STRLCAT_SIZE);
	cr_expect(zero(int, strcmp(dest, STR)),
		"ft_strlcat: expected full string to be concatenated");
}

Test(ft_strlcat, concats_part_of_string)
{
	char	dest[STRLCAT_SIZE];

	strcpy(dest, STR);
	ft_strlcat(dest, STR, STRLCAT_SIZE);
	cr_expect(zero(int, strncmp(dest + strlen(STR), STR, 
					STRLCAT_SIZE - strlen(STR) - 1)),
		"ft_strlcat: expected part of string to be concatenated");
}
