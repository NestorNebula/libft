/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_number.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhoussie <nhoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/31 15:40:15 by nhoussie          #+#    #+#             */
/*   Updated: 2026/03/31 15:47:50 by nhoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdint.h>
#include "libft.h"

int		ft_get_number(char *s, int *n)
{
	uint64_t	nbr;
	int			is_negative;

	is_negative = *s == '-';
	if (*s == '-' || *s == '+')
		s++;
	nbr = 0;
	while (ft_isdigit(*s) && nbr <= (uint64_t) INT_MAX - !is_negative)
	{
		nbr = nbr * 10 + (*s - '0');
		s++;
	}
	if (*s != '\0')
		return (0);
	if (is_negative)
		*n = -nbr;
	else
		*n = nbr;
	return (1);
}
