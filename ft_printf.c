/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlalouli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 17:27:17 by hlalouli          #+#    #+#             */
/*   Updated: 2021/11/30 21:35:40 by hlalouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int			l;
	va_list		ptr;

	va_start(ptr, format);
	l = ft_prtf((char *)format, ptr);
	va_end(ptr);
	return (l);
}

int	ft_prtf(char *format, va_list ptr)
{
	int	m;
	int	n;

	m = 0;
	while (*format)
	{
		n = ft_printfid(*format, *(format + 1), ptr);
		if (n == -1)
			return (m);
		m += n;
		if (*format == '%')
			format++;
		format++;
	}
	return (m);
}

int	ft_printfid(char a, char b, va_list ptr)
{
	int	n;

	n = 0;
	if (a == '%' && b == '%')
		n += ft_prtchar('%');
	else if (a == '%' && b == 'c')
		n += ft_prtchar(va_arg(ptr, int));
	else if (a == '%' && b == 'p')
		ft_prtpoint(va_arg(ptr, unsigned long), &n);
	else if (a == '%' && b == 's')
		n += ft_prtstr(va_arg(ptr, char *));
	else if (a == '%' && (b == 'i' || b == 'd'))
			n += ft_prtint(va_arg(ptr, int));
	else if (a == '%' && b == 'u')
		n += ft_prtunint(va_arg(ptr, unsigned int));
	else if (a == '%' && b == 'x')
		ft_prthexa(va_arg(ptr, unsigned int), "0123456789abcdef", &n);
	else if (a == '%' && b == 'X')
		ft_prthexa(va_arg(ptr, unsigned int), "0123456789ABCDEF", &n);
	else if (a != '%')
		n += ft_prtchar(a);
	else
		return (-1);
	return (n);
}
