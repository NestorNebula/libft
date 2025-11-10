#include "config.h"

Test(ft_atoi, returns_corresponding_number)
{
	cr_expect(eq(int, ft_atoi("42"), 42),
		"ft_atoi: expected return value to match number");
	cr_expect(eq(int, ft_atoi("-42"), -42),
		"ft_atoi: expected return value to match number");
}

Test(ft_atoi, stops_reading_at_first_non_digit)
{
	cr_expect(eq(int, ft_atoi("42-21"), 42),
		"ft_atoi: expected return value to match number");
}

Test(ft_atoi, skips_leading_whitespaces)
{
	cr_expect(eq(int, ft_atoi("       42"), 42),
		"ft_atoi: expected return value to match number");
}

Test(ft_atoi, returns_zero_when_string_is_not_a_number)
{
	cr_expect(zero(int, ft_atoi(" fr.42")),
		"ft_atoi: expected non-number input to return zero");
}
