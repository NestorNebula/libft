#include "config.h"

#define MEMMOVE_SIZE 20

Test(ft_memmove, works_when_dest_overwrites_end_of_source)
{
	char	src[MEMMOVE_SIZE];
	char	*dest;

	dest = src + MEMMOVE_SIZE / 2;
	strcpy(src, STR);
	ft_memmove(dest, src, MEMMOVE_SIZE / 2);
	cr_expect(zero(int, strncmp(dest, STR, MEMMOVE_SIZE / 2)),
		"ft_memmove: expected first %d bytes of src to have been copied to dest",
		MEMMOVE_SIZE / 2);
}

Test(ft_memmove, works_when_dest_overwrites_start_of_source)
{
	char 	dest[MEMMOVE_SIZE];
	char	*src;

	src = dest + 1;
	strcpy(src, STR);
	ft_memmove(dest, src, MEMMOVE_SIZE / 2);
	cr_expect(zero(int, strncmp(dest, STR, MEMMOVE_SIZE / 2)),
		"ft_memmove: expected first %d bytes of src to have been copied to dest",
		MEMMOVE_SIZE / 2);
}
