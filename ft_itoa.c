/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlalouli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 12:49:26 by hlalouli          #+#    #+#             */
/*   Updated: 2021/11/30 18:00:24 by hlalouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"ft_printf.h"

static char	*ft_rempli(char	*s, long long int n, long long int l)
{
	int	d ;

	s[l] = '\0';
	l = l - 1 ;
	if (n < 0)
	{
		n = n * -1;
		d = 1;
		s[0] = '-';
	}
	else
		d = 0;
	while (l >= d)
	{
		s[l] = n % 10 + '0';
		n = n / 10;
		l--;
	}
	return (s);
}

char	*ft_itoa(int n)
{
	char			*s;
	long long int	k;
	long long int	i;

	i = 1;
	k = n;
	if (k < 0)
		k = k * -1;
	while (k >= 10)
	{
		k = k / 10;
		i++;
	}
	k = n;
	if (k < 0)
		i = i + 1;
	s = malloc((i + 1) * sizeof(char));
	if (!s)
		return (NULL);
	s = ft_rempli(s, k, i);
	return (s);
}
