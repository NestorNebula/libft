#include "config.h"

Test(ft_tolower, returns_expected_values)
{
	int	c;

	c = 0;
	while (c <= UCHAR_MAX)
	{
		cr_expect(eq(int, ft_tolower(c), tolower(c)),
			"ft_tolower: bad return value for %c", c);
		c++;
	}
}
