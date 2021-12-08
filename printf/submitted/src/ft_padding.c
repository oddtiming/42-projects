/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_padding.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyahoui- <iyahoui-@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 13:47:27 by iyahoui-          #+#    #+#             */
/*   Updated: 2021/11/16 14:57:11 by iyahoui-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_modifier(t_arg *arg)
{
	if (is_set(arg->var_type, "di"))
	{
		if (FLAG_NEG & arg->flags)
			arg->n_bytes += write(1, "-", 1);
		else if (FLAG_PLUS & arg->flags)
			arg->n_bytes += write(1, "+", 1);
		else if (FLAG_SPACE & arg->flags)
			arg->n_bytes += write(1, " ", 1);
	}
	else if ((arg->var_type == 'p') || \
		(arg->var_type == 'x' && FLAG_HASH & arg->flags))
		arg->n_bytes += ft_putstr_n_ret("0x", 2);
	else if (arg->var_type == 'X' && (FLAG_HASH & arg->flags))
		arg->n_bytes += ft_putstr_n_ret("0X", 2);
}

void	front_pad(t_arg *arg)
{
	while (!(FLAG_MINUS & arg->flags) && !((FLAG_ZERO & arg->flags) && \
		!(FLAG_PREC & arg->flags)) && arg->width > 0)
	{
		arg->n_bytes += write(1, " ", 1);
		arg->width--;
	}
	print_modifier(arg);
	while ((FLAG_ZERO & arg->flags) && \
		!((FLAG_MINUS + FLAG_PREC) & arg->flags) && arg->width > 0)
	{
		arg->n_bytes += write(1, "0", 1);
		arg->width--;
	}
}
