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

static void	handle_char(char c, t_string *str, bool *err);

static void	handle_conversion(const char **format, t_string *str,
				va_list *ap, bool *err);

static int	handle_output(t_string *str, bool err);

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
	str = new_string();
	if (str == NULL)
		return (-1);
	va_start(ap, format);
	while (*format != '\0')
	{
		if (*format != '%')
			handle_char(*format++, str, &err);
		else
			handle_conversion(&format, str, &ap, &err);
	}
	va_end(ap);
	return (handle_output(str, err));
}

static void	handle_char(char c, t_string *str, bool *err)
{
	if (string_cat(str, &c, 1) == NULL)
		*err = true;
}

static void	handle_conversion(const char **format, t_string *str,
				va_list *ap, bool *err)
{
	t_conv	conv;

	(*format)++;
	*format += read_conv(*format, &conv);
	check_conv(&conv);
	if (conv.err)
	{
		if (conv.type != '\0')
			handle_char('%', str, err);
	}
	else if (set_conv_val(ap, &conv) == NULL)
		*err = true;
	else
	{
		set_conv_pref(&conv);
		print_conv(&conv, str);
		free(conv.val);
	}
}

static int	handle_output(t_string *str, bool err)
{
	int	res;

	if (err || str->content == NULL)
	{
		free_string(str);
		return (-1);
	}
	res = write(STDOUT_FILENO, str->content, str->len);
	free_string(str);
	return (res);

}
