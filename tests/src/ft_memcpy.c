#include "config.h"

Test(ft_memcpy, copies_bytes)
{
	char	*src;
	char	dest[SIZE];

	src = "Test string";
	ft_memcpy(dest, src, SIZE);
	cr_expect(zero(int, strncmp(dest, src, SIZE)),
		"ft_memcpy: expected src's first %d bytes to be copied into dest", SIZE);
}
