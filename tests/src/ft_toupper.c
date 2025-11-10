#include "config.h"

Test(ft_toupper, returns_expected_values)
{
	int	c;

	c = 0;
	while (c <= UCHAR_MAX)
	{
		cr_expect(eq(int, ft_toupper(c), toupper(c)),
			"ft_toupper: bad return value for %c", c);
		c++;
	}
}
