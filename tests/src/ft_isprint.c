#include "config.h"

Test(ft_isprint, returns_expected_values)
{
	int	c;
	int	expected;

	c = 0;
	while (c <= CHAR_MAX)
	{
		expected = isprint(c) != 0;
		cr_expect(eq(ft_isprint(c), expected),
			"ft_isprint: bad return value for %c", c);
		c++;
	}
}
