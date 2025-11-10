#include "config.h"

Test(ft_itoa, returns_positive_number_as_string)
{
	char	*str;

	str = ft_itoa(POSNBR);
	cr_expect(zero(strcmp(str, POSSTR)),
		"ft_itoa: expected returned string (%s) to match number %d", str, POSNBR);
	free(str);
}

Test(ft_itoa, returns_negative_number_as_string)
{
	char	*str;

	str = ft_itoa(NEGNBR);
	cr_expect(zero(strcmp(str, NEGSTR)),
		"ft_itoa: expected returned string (%s) to match number %d", str, NEGNBR);
	free(str);
}
