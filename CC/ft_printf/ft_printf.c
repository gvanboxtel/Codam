/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 13:30:18 by marvin            #+#    #+#             */
/*   Updated: 2025/10/24 13:30:18 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft.h"

void util_format_specifier(const char *format, va_list ap);

int ft_printf(const char *format, ...)
{
	va_list ap;
	va_start(ap , *format);
	util_format_specifier(format, ap);

	return (0);
}

void util_format_specifier(const char *format, va_list ap)
{	
	int	d;
	int	i;
	char	c;
	char	*s;
	void	*p;
	
	while (*format)
	{
		if (*format == '%' && *(format + 1) == 's')
		{
			s = va_arg(ap, char *);
			ft_putstr_fd(s, 1);
			format += 2;
		}
		if (*format == '%' && *(format + 1) == 'c')
		{
			c = va_arg(ap, int);
			ft_putchar_fd(c, 1);
			format += 2;
		}
		if (*format == '%' && (*(format + 1) == 'd' || *(format + 1) == 'i'))
		{
			d = va_arg(ap, int);
			ft_itoa(d);
			format += 2;
		}
		if (*format == '%' && *(format + 1) == 'p')
		{
			p = va_arg(ap, void *);
		}
		if (*format == '%' && *(format + 1) == 'u')
		{

		}
		if (*format == '%' && *(format + 1) == 'x')
		{

		}
		if (*format == '%' && *(format + 1) == 'X')
		{

		}
		if (*format == '%' && *(format + 1) == '%')
			ft_putchar_fd('%', 1);
		
		
	}
	va_end(ap);
}

int main(void)
{
	char *str = "This is a test\n";

	ft_printf("%s", str);
}