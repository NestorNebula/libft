/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhoussie <nhoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 13:23:35 by nhoussie          #+#    #+#             */
/*   Updated: 2025/11/25 09:43:06 by nhoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include "conv.h"

static int	handle_char(char c, t_string *str, bool *err);

static int	handle_conversion(const char **format, t_string *str,
				va_list *ap, bool *err);

/**
 *  Writes formatted output to stdout using format and others arguments.
 *
 *  @param format The format of the output
 *  @param ... Optional arguments to use in combination with the format
 *  @return The number of characters printed. -1 if an error occurs
 */
int	ft_printf(const char *format, ...)
{
	int			res;
	bool		err;
	va_list		ap;
	t_string	*str;

	res = 0;
	err = false;
	if (format == NULL)
		return (-1);
	va_start(ap, format);
	while (*format != '\0')
	{
		if (*format != '%')
			res += handle_char(*format++, str, &err);
		else
			res += handle_conversion(&format, str, &ap, &err);
	}
	va_end(ap);
	if (err)
		return (-1);
	if (str->content == NULL)
		return (-1);
	return (write(STDOUT_FILENO, str->content, str->len));
}

static int	handle_char(char c, t_string *str, bool *err)
{
	string_cat(str, &c, 1);
	if (str->content != NULL)
	{
		*err = true;
		return (-1);
	}
	return (1);
}

static int	handle_conversion(const char **format, t_string *str,
				va_list *ap, bool *err)
{
	int		res;
	t_conv	conv;

	res = -1;
	(*format)++;
	*format += read_conv(*format, &conv);
	check_conv(&conv);
	if (conv.err)
	{
		if (conv.type != '\0')
			res = handle_char('%', str, err);
		if (res != 1)
			*err = true;
	}
	else if (set_conv_val(ap, &conv) == NULL)
		*err = true;
	else
	{
		set_conv_pref(&conv);
		res = print_conv(&conv, str);
		if (res == -1)
			*err = true;
		free(conv.val);
	}
	return (res);
}
