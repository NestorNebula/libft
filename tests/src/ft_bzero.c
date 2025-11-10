#include "config.h"

Test(ft_bzero, sets_bytes_to_zero)
{
	char	s1[SIZE];
	int		i;

	s1[0] = 1;
	ft_bzero((void *) s1, SIZE);
	i = 0;
	while (i < SIZE)
		cr_expect(zero(chr, s1[i++]), "ft_bzero: byte not set to zero");
}
