/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhoussie <nhoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 08:45:55 by nhoussie          #+#    #+#             */
/*   Updated: 2025/11/12 17:07:42 by nhoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

/**
 *  Allocates memory (using malloc(3)) and returns a new string,
 *  which is the result of concatenating 's1' and 's2'.
 *
 *  @param s1 The prefix string
 *  @param s2 The suffix string
 *  @return The new string. NULL if the allocation fails
 */
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	size_t	size;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	join = malloc(sizeof(char) * size);
	if (join == NULL)
		return (NULL);
	ft_strlcpy(join, s1, size);
	ft_strlcat(join, s2, size);
	return (join);
}
