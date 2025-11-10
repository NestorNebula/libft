#include "config.h"

Test(ft_calloc, returns_pointer_to_data_that_can_be_freed_on_success)
{
	void	*p;

	p = ft_calloc(NMEMB, SIZE);
	cr_expect(ne(ptr, p, 0),
		"ft_calloc: expected to return a non-null pointer");
	free(p);
}

Test(ft_calloc, initializes_every_element_to_zero)
{
	int	*p;
	int	i;

	p = ft_calloc(NMEMB, sizeof(int));
	i = 0;
	while (i < NMEMB)
		cr_expect(zero(int, p[i++]),
			"ft_calloc: expected all members to be set to zero");
	free(p);
}

Test(ft_calloc, returns_null_pointer_on_empty_nmemb_size)
{
	void	*p;

	p = ft_calloc(0, SIZE);
	cr_expect(zero(ptr, p),
		"ft_calloc: expected to return a null pointer on empty nmemb");
	free(p);
	p = ft_calloc(NMEMB, 0);
	cr_expect(zero(ptr, p),
		"ft_calloc: expected to return a null pointer on empty size");
	free(p);
}

Test(ft_calloc, returns_null_pointer_that_can_be_freed_on_size_overflow)
{
	void	*p;

	p = ft_calloc(NMEMB, INT_MAX);
	cr_expect(zero(ptr, p),
		"ft_calloc: expected to return a null pointer on size overflow");
	free(p);
}
