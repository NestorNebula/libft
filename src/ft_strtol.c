/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhoussie <nhoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 11:50:31 by nhoussie          #+#    #+#             */
/*   Updated: 2026/04/02 12:56:42 by nhoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdint.h>
#include "libft.h"

long	read_long(const char *nptr, char **endptr, int base,
			const char *base_arr);

int		char_in_base(char c, int base, const char *base_arr);

long	ft_strtol(const char *nptr, char **endptr, int base)
{
	static const char	*base_arr = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

	if (nptr == NULL || base < 2 || base > 36)
		return (0);
	return (read_long(nptr, endptr, base, base_arr));
}

long	read_long(const char *nptr, char **endptr, int base,
			const char *base_arr)
{
	long		l;
	int			index;
	int			is_negative;
	
	is_negative = *nptr == '-';
	if (*nptr == '+' || *nptr == '-')
		nptr++;
	l = 0;
	index = char_in_base(*nptr, base, base_arr);
	while (index != -1 && (l <= LONG_MAX / base - index + is_negative))
	{
		l = l * base + index;
		index = char_in_base(*++nptr, base, base_arr);
	}
	if (index != -1 && is_negative)
		l = LONG_MIN;
	else if (index != -1)
		l = LONG_MAX;
	else if (is_negative)
		l = -l;
	if (endptr != NULL)
		*endptr = (char *) nptr;
	return (l);
}

int		char_in_base(char c, int base, const char *base_arr)
{
	int	i;

	i = 0;
	while (i < base && base_arr[i] != c)
		i++;
	if (i == base)
		return (-1);
	return (i);
}
