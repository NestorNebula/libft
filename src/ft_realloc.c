/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhoussie <nhoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 13:50:22 by nhoussie          #+#    #+#             */
/*   Updated: 2026/03/30 14:33:21 by nhoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_realloc(void *ptr, size_t initial_size, size_t size)
{
	char	*resized;

	if (ptr == NULL)
		return (malloc(size));
	if (size == 0)
	{
		free(ptr);
		return (NULL);
	}
	resized = malloc(size);
	if (resized == NULL)
		return (NULL);
	if (size >= initial_size)
		ft_memcpy(resized, ptr, initial_size);
	else
		ft_memcpy(resized, ptr, size);
	free(ptr);
	return (resized);
}
