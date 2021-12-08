/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pdiuxX.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyahoui- <iyahoui-@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 14:54:25 by iyahoui-          #+#    #+#             */
/*   Updated: 2021/11/16 15:02:21 by iyahoui-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_di(t_arg *arg, int nbr)
{
	int		str_len;

	str_len = ft_log_calc(nbr, 10);
	if ((FLAG_PREC & arg->flags) && arg->precision > str_len)
		str_len = arg->precision;
	if (!((FLAG_PREC & arg->flags) && !arg->precision && !nbr))
		arg->width -= str_len;
	if (nbr < 0 || ((FLAG_PLUS | FLAG_SPACE) & arg->flags))
		arg->width--;
	if (nbr < 0)
	{
		arg->flags |= FLAG_NEG;
		nbr = -nbr;
	}
	front_pad(arg);
	if (!((FLAG_PREC & arg->flags) && !arg->precision && !nbr))
		arg->n_bytes += ft_putnbr_unsigned_n_ret(nbr, str_len);
	while ((FLAG_MINUS & arg->flags) && arg->width-- > 0)
		arg->n_bytes += write(1, " ", 1);
}

void	ft_print_u(t_arg *arg, unsigned int nbr)
{
	int		str_len;

	str_len = ft_log_calc_size_t(nbr, 10);
	if ((FLAG_PREC & arg->flags) && (arg->precision > str_len))
		str_len = arg->precision;
	if (!((FLAG_PREC & arg->flags) && !arg->precision && !nbr))
		arg->width -= str_len;
	front_pad(arg);
	if (!((FLAG_PREC & arg->flags) && !arg->precision && !nbr))
		arg->n_bytes += ft_putnbr_unsigned_n_ret(nbr, str_len);
	while ((FLAG_MINUS & arg->flags) && (arg->width-- > 0))
		arg->n_bytes += write(1, " ", 1);
}

void	ft_print_x(t_arg *arg, unsigned int nbr)
{
	int	str_len;

	str_len = ft_log_calc_size_t(nbr, 16);
	if ((FLAG_PREC & arg->flags) && arg->precision > str_len)
		str_len = arg->precision;
	if (!((FLAG_PREC & arg->flags) && !arg->precision && !nbr))
		arg->width -= str_len;
	if (!nbr)
		arg->flags &= ~FLAG_HASH;
	if (FLAG_HASH & arg->flags)
		arg->width -= 2;
	front_pad(arg);
	str_len = ft_log_calc_size_t(nbr, 16);
	while ((FLAG_PREC & arg->flags) && arg->precision > str_len)
	{
		arg->n_bytes += write(1, "0", 1);
		arg->precision--;
	}
	if (!((FLAG_PREC & arg->flags) && !arg->precision && !nbr))
		ft_puthex_size_t(arg, nbr);
	while ((FLAG_MINUS & arg->flags) && arg->width-- > 0)
		arg->n_bytes += write(1, " ", 1);
}

void	ft_print_p(t_arg *arg, size_t addr)
{
	int	str_len;

	str_len = ft_log_calc_size_t(addr, 16);
	if ((FLAG_PREC & arg->flags) && arg->precision > str_len)
		str_len = arg->precision;
	if (!((FLAG_PREC & arg->flags) && !arg->precision && !addr))
		arg->width -= (str_len);
	arg->width -= 2;
	front_pad(arg);
	str_len = ft_log_calc_size_t(addr, 16);
	while ((FLAG_PREC & arg->flags) && arg->precision > str_len)
	{
		arg->n_bytes += write(1, "0", 1);
		arg->precision--;
	}
	if (!((FLAG_PREC & arg->flags) && !arg->precision && !addr))
		ft_puthex_size_t(arg, addr);
	while ((FLAG_MINUS & arg->flags) && arg->width-- > 0)
		arg->n_bytes += write(1, " ", 1);
}
