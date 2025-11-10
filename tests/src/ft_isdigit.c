#include "config.h"

Test(ft_isdigit, returns_expected_values)
{
	int	c;
	int	expected;

	c = 0;
	while (c <= CHAR_MAX)
	{
		expected = isdigit(c) != 0;
		cr_expect(eq(ft_isdigit(c), expected), "ft_isdigit: bad return for %c", c);
		c++;
	}
}
