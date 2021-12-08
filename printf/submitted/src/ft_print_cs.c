/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_cs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyahoui- <iyahoui-@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 14:54:22 by iyahoui-          #+#    #+#             */
/*   Updated: 2021/11/16 14:56:13 by iyahoui-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_c(t_arg *arg, char c)
{
	arg->width -= 1;
	front_pad(arg);
	arg->n_bytes += write(1, &c, 1);
	while ((FLAG_MINUS & arg->flags) && arg->width-- > 0)
		arg->n_bytes += write(1, " ", 1);
}

void	ft_print_s(t_arg *arg, char *arg_to_str)
{
	int		str_len;

	if (!arg_to_str)
		arg_to_str = ft_strdup("(null)");
	else
		arg_to_str = ft_strdup(arg_to_str);
	str_len = ft_strlen(arg_to_str);
	if ((FLAG_PREC & arg->flags) && arg->precision < str_len)
		str_len = arg->precision;
	arg->width -= str_len;
	front_pad(arg);
	arg->n_bytes += ft_putstr_n_ret(arg_to_str, str_len);
	while ((FLAG_MINUS & arg->flags) && arg->width-- > 0)
		arg->n_bytes += write(1, " ", 1);
	free (arg_to_str);
}
