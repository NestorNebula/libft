#include "config.h"

Test(ft_isalnum, returns_expected_values)
{
	int	c;
	int	expected;

	c = 0;
	while (c <= CHAR_MAX)
	{
		expected = isalnum(c) != 0; 
		cr_expect(eq(ft_isalnum(c), expected),
			"ft_isalnum: bad return value for %c", c);
		c++;
	}
}
