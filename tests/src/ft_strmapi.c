#include "config.h"

#define STRMAPI_SIZE 4

char	get_index(unsigned int index, char c)
{
	if (index <= 126)
		return ((char) index);
	return (c);
}

Test(ft_strmapi, returns_results_in_new_string)
{
	const char	def[STRMAPI_SIZE] = { 10, 5, 20, 7 };
	char		*res;

	res = ft_strmapi((char *) def, get_index);
	cr_expect(ne(ptr, res, (char *) def),
		"ft_strmapi: returned pointer points to original string");
	free(res);
}

Test(ft_strmapi, applies_function_to_each_character)
{
	const char	def[STRMAPI_SIZE] = { 10, 5, 20,  7 };
	char		*res;
	int			i;

	res = ft_strmapi((char *) def, get_index);
	i = 0;
	while (i < STRMAPI_SIZE)
	{
		cr_expect(eq(int, res[i], i),
			"ft_strmapi: unexpected character (%d) at index (%d)",
			res[i], i);
		i++;
	}
	free(res);
}
