#include "config.h"

#define SPLIT_STR "Test string 1:Test string 2:Test string 3"
#define SPLIT_DELIMITER ':'

void	free_strs(char **strs, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
		free(strs[i++]);
	free(strs);
}

Test(ft_split, returns_array_of_correct_size)
{
	char	**split;
	size_t	i;

	split = ft_split(SPLIT_STR, SPLIT_DELIMITER);
	i = 0;
	while (split[i] != NULL)
		i++;
	cr_expect(eq(int, i, STR_COUNT),
		"ft_split: expected returned array to have size %d but got size %d",
		STR_COUNT, i);
	free_strs(split, i);
}

Test(ft_split, returns_copy_of_every_string)
{
	char	**split;

	split = ft_split(SPLIT_STR, SPLIT_DELIMITER);
	cr_expect(zero(int, strcmp(split[0], STR1)),
		"ft_split: expected first element (%s) to match first string (%s)",
		split[0], STR1);
	cr_expect(zero(int, strcmp(split[1], STR2)),
		"ft_split: expected second element (%s) to match second string (%s)",
		split[1], STR2);
	cr_expect(zero(int, strcmp(split[2], STR3)),
		"ft_split: expected third element (%s) to match third string (%s)",
		split[2], STR3);
	free_strs(split, STR_COUNT);
}

Test(ft_split, returns_empty_array_when_string_only_has_delimiters)
{
	char	**split;

	split = ft_split(":::::", SPLIT_DELIMITER);
	cr_expect(zero(ptr, split[0]),
		"ft_split: expected first element to be null");
	free_strs(split, 0);
}
