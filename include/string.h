/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhoussie <nhoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 08:48:08 by nhoussie          #+#    #+#             */
/*   Updated: 2026/01/30 08:55:57 by nhoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRING_H
# define STRING_H

# include <stddef.h>

typedef struct s_string {
	char	*content;
	size_t	size;
	size_t	len;
}				t_string;

/**
 * Initializes a string structure.
 *
 * @return A pointer to a string structure on success.
 * A NULL pointer on error
 *
 */
t_string	*new_string(void);

/**
 * Concatenates the content of a string to the content actually stored
 * in a string structure.
 *
 * @param str_ptr A pointer to a string structure
 * @param str A string
 * @return A pointer to the resulting string on success.
 * A NULL pointer on error.
 */
char		*string_cat(t_string *str_ptr, const char *str);

/**
 * Frees a string structure
 *
 * @param str_ptr A pointer to a string structure
 */
void		free_string(t_string *str_ptr);

#endif // !STRING_H
