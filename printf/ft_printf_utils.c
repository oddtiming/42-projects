/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyahoui- <iyahoui-@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 14:12:08 by iyahoui-          #+#    #+#             */
/*   Updated: 2021/11/01 19:01:52 by iyahoui-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	printf_struct_init(t_arg *arg, char const *format)
{
	arg->n_bytes = 0;
	arg->index = 0;
	arg->precision = 0;
	arg->width = 0;
	arg->var_type = 0;
	arg->flags = 0;
	arg->format = ft_strdup(format);
}

int	ft_putchar_ret(const char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr_ret(const char *s)
{
	int	i;

	i = 0;
	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (s[i])
		write(1, &s[i++], 1);
	return (i);
}

/*
static long	get_magnitude_hex(unsigned long n)
{
	long	magnitude;

	magnitude = 1;
	while (n >= 16)
	{
		magnitude *= 16;
		n /= 16;
	}
	return (magnitude);
}

int	ft_putaddress_ret(unsigned long address)
{
	int		i;
	long	magnitude;
	char	*hex_base;

	i = 0;
	hex_base = "0123456789abcdef";
	magnitude = get_magnitude_hex(address);
	printf("magnitude = %lu\n", magnitude);
	printf("address = %lu\n", address);
	write(1, "0x", 2);
	i += 2;
	while (magnitude)
	{
		write(1, &hex_base[address / magnitude], sizeof(char));
		i++;
		address = address % magnitude;
		magnitude /= 10;
	}
	return (i);
}

void	ft_puthex_long_long(long long i, t_arg *arg)
{
	char	*hex_base;

	hex_base = "0123456789abcdef";
	if (i > 15)
		ft_puthex_long_long(i / 16, arg);
	write(1, &hex_base[i % 16], 1);
	arg->n_bytes += 1;
}

void	ft_puthex_long(long i, t_arg *arg)
{
	char	*hex_base;

	hex_base = "0123456789abcdef";
	if (i > 15)
		ft_puthex_long(i / 16, arg);
	write(1, &hex_base[i % 16], 1);
	arg->n_bytes += 1;
}
*/

void	ft_puthex_size_t(t_arg *arg, size_t i)
{
	char	*hex_base;

	hex_base = "0123456789abcdef";
	if (i > 15)
		ft_puthex_size_t(i / 16, arg);
	write(1, &hex_base[i % 16], 1);
	arg->n_bytes += 1;
}

void	ft_puthex_int(unsigned int i, t_arg *arg)
{
	char	*hex_base;

	if (arg->var_type == 'x')
		hex_base = "0123456789abcdef";
	else
		hex_base = "0123456789ABCDEF";
	if (i > 15)
		ft_puthex_int(i / 16, arg);
	write(1, &hex_base[i % 16], 1);
	arg->n_bytes += 1;
}
