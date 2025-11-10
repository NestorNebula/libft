#include "config.h"

void	set_index(unsigned int index, char *c)
{
	if (index <= 126)
		*c = (char) index;
}

Test(ft_striteri, applies_function_results_in_place)
{
	char	*def;
	int		i;

	def = malloc(sizeof(char) * (SIZE + 1));
	memset(def, 42, SIZE);
	def[SIZE] = '\0';
	ft_striteri((char *) def, set_index);
	i = 0;
	while (i < SIZE)
	{
		cr_expect(eq(def[i], i),
			"ft_striteri: unexpected value (%d) at index (%d)", def[i], i);
		i++;
	}
}
