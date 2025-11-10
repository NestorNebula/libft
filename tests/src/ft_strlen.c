#include "config.h"

Test(ft_strlen, returns_string_length)
{
	cr_expect(eq(int, ft_strlen(STR), strlen(STR)));
}
