/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbicer <vbicer@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 19:39:36 by vbicer            #+#    #+#             */
/*   Updated: 2024/11/21 08:54:54 by vbicer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <stddef.h>

static int	ft_format(va_list *args, char w)
{
	if (w == 'c')
		return (ft_putchar(va_arg((*args), int)));
	else if (w == 'd' || w == 'i')
		return (ft_int(va_arg((*args), int)));
	else if (w == 'u')
		return (ft_unsigned(va_arg((*args), unsigned int)));
	else if (w == 's')
		return (ft_string(va_arg((*args), char *)));
	else if (w == 'X' || w == 'x')
		return (ft_hex(va_arg((*args), unsigned int), w));
	else if (w == 'p')
		return (ft_point(va_arg((*args), unsigned long), 1));
	else if (w == '%')
		return (ft_putchar('%'));
	else
		return (0);
}

static int	ft_check(char str)
{
	if (str == 'c' || str == 'd' || str == 'i' || str == 'u' || str == '%'
		|| str == 's' || str == 'x' || str == 'X' || str == 'p')
		return (1);
	return (0);
}

static int	ft_count_check(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '%' && s[i + 1] == '\0')
			return (1);
		if (s[i] == '%' && !ft_check(s[i + 1]) && s[i + 1] != '\0')
			return (2);
		i++;
	}
	return (0);
}

static int	looper(va_list *args, const char *str, int fcc)
{
	int	counter;
	int	leng;
	int	tmp;

	counter = -1;
	leng = 0;
	while (str[++counter] != '\0')
	{
		if (str[counter] == '%' && ft_check(str[counter + 1]))
		{
			tmp = ft_format(args, str[++counter]);
			if (tmp == -1)
				return (-1);
			leng += tmp - 1;
		}
		else if (str[counter] == '%' && str[counter + 1] == '\0' && fcc != 2)
			return (-1);
		else
			if (ft_putchar(str[counter]) == -1)
				return (-1);
		leng++;
	}
	if (fcc == 1 && str[counter +1] != '%')
		return (-1);
	return (leng);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		fcc;
	int		len;

	if (str == NULL)
		return (-1);
	fcc = ft_count_check(str);
	va_start(args, str);
	len = looper(&args, str, fcc);
	return (va_end(args), len);
}
