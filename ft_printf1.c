/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlalouli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 12:56:26 by hlalouli          #+#    #+#             */
/*   Updated: 2021/11/30 20:51:48 by hlalouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"ft_printf.h"

int	ft_prtchar(char c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

int	ft_prtstr(char *s)
{
	int	m ;

	if (!s)
		s = "(null)";
	ft_putstr_fd(s, 1);
	m = ft_strlen(s);
	return (m);
}

int	ft_prtint(int n)
{
	char	*m;
	int		k;

	m = ft_itoa(n);
	ft_putstr_fd(m, 1);
	k = ft_strlen(m);
	free(m);
	return (k);
}

int	ft_prtunint(unsigned int n)
{
	int				len;
	int				k;
	unsigned int	l;
	int				m;

	l = n;
	len = 0;
	if (l == 0 && len == 0)
		len++;
	while (l > 0 && len == 0)
	{
		l = l / 10;
		len++;
	}
	if (n >= 0 && n <= 9)
	{
		ft_putchar_fd(n + '0', 1);
		return (len);
	}
	k = ft_prtunint(n / 10);
	ft_putchar_fd(n % 10 + '0', 1);
	m = len + k;
	return (m);
}
