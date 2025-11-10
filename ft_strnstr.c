/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhoussie <nhoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 12:37:20 by nhoussie          #+#    #+#             */
/*   Updated: 2025/11/10 16:37:44 by nhoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	int		little_len;
	size_t	i;

	little_len = ft_strlen(little);
	if (little_len == 0)
		return ((char *) big);
	if (big == NULL)
		return (NULL);
	i = 0;
	while (i < len && big[i] != '\0')
	{
		if (ft_strncmp(big + i, little, little_len) == 0)
			return ((char *) big + i);
		i++;
	}
	return (NULL);
}
