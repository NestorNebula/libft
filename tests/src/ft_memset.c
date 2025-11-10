#include "config.h"

#define MEMSET_VALUE 2

Test(ft_memset, fills_memory_correctly)
{
	char	s1[SIZE];
	char	s2[SIZE];
	int		i;

	memset((void *) s1, MEMSET_VALUE, SIZE);
	ft_memset((void *) s2, MEMSET_VALUE, SIZE);
	i = 0;
	while (i < SIZE)
	{
		cr_expect(eq(s1[i], s2[i]), "ft_memset: expected %d to be %d", s2[i], s1[i]);
		i++;
	}
}
