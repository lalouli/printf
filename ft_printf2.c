/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlalouli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 12:57:49 by hlalouli          #+#    #+#             */
/*   Updated: 2021/11/30 17:59:59 by hlalouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"ft_printf.h"

void	ft_prthexa(unsigned long int n, char *base, int *len)
{
	if (n < 16 && n >= 0)
	{
		ft_putchar_fd(base[n], 1);
		(*len)++;
	}
	else
	{
		ft_prthexa(n / 16, base, len);
		ft_prthexa(n % 16, base, len);
	}
}

void	ft_prtpoint(unsigned long n, int *len)
{
	(*len) += 2;
	ft_putstr_fd("0x", 1);
	ft_prthexa(n, "0123456789abcdef", len);
}
