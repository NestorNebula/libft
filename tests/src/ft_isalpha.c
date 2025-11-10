#include "config.h"

Test(ft_isalpha, returns_expected_values)
{
	int	c;
	int	expected;

	c = 0;
	while (c <= CHAR_MAX)
	{
		expected = isalpha(c) != 0;
		cr_expect(eq(ft_isalpha(c), expected),
			"ft_isalpha: bad return value for %c", c);
		c++;
	}
}
