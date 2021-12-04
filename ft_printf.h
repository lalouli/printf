/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlalouli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 17:47:58 by hlalouli          #+#    #+#             */
/*   Updated: 2021/11/30 18:36:48 by hlalouli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include<stdlib.h>
# include<unistd.h>
# include<stdarg.h>

void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
void	ft_prtpoint(unsigned long n, int *len);
void	ft_prthexa(unsigned long int n, char *base, int *len);
char	*ft_itoa(int n);
size_t	ft_strlen(const char *s);
int		ft_prtchar(char c);
int		ft_prtstr(char *s);
int		ft_prtint(int n);
int		ft_prtunint(unsigned int n);
int		ft_printfid(char a, char b, va_list ptr);
int		ft_prtf(char *format, va_list ptr);
int		ft_printf(const char *format, ...);

#endif
