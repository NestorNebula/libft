#include "config.h"

Test(ft_isascii, returns_expected_values)
{
	int	c;
	int	expected;

	c = 0;
	while (c <= CHAR_MAX)
	{
		expected = isascii(c) != 0;
		cr_expect(eq(ft_isascii(c), expected),
			"ft_isascii: bad return value for %c", c);
		c++;
	}
}
