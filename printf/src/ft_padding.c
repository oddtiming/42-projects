/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_padding.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyahoui- <iyahoui-@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 13:47:27 by iyahoui-          #+#    #+#             */
/*   Updated: 2021/11/16 14:50:57 by iyahoui-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//Prints whatever needs to be outputted between width and FLAG_ZERO
//e.g. %5d of d == -1 --> "   -1", but %05d of d == -1 --> "-0001"
void	print_modifier(t_arg *arg)
{
	if (is_set(arg->var_type, "di"))
	{
		//I implemented FLAG_NEG to print '-' as a modifier in order to treat
		//all numbers as positive numbers
		if (FLAG_NEG & arg->flags)
			arg->n_bytes += write(1, "-", 1);
		//only prints '+' if non-negative
		else if (FLAG_PLUS & arg->flags)
			arg->n_bytes += write(1, "+", 1);
		//only prints ' ' if non-negative and FLAG_PLUS is unset
		else if (FLAG_SPACE & arg->flags)
			arg->n_bytes += write(1, " ", 1);
	}
	//Prints '0x' for addresses and FLAG_HASH for 'x'
	else if ((arg->var_type == 'p') || \
		(arg->var_type == 'x' && FLAG_HASH & arg->flags))
		arg->n_bytes += ft_putstr_n_ret("0x", 2);
	//Prints FLAG_HASH for 'X'
	else if (arg->var_type == 'X' && (FLAG_HASH & arg->flags))
		arg->n_bytes += ft_putstr_n_ret("0X", 2);
	// else if (arg->var_type == 'p')
	// 	arg->n_bytes += ft_putstr_n_ret("0x", 2);
}

//Only takes care of leading padding before the actual converted value output.
//Could easily take care of all padding if converted values were converted to strings
//before being outputted.
void	front_pad(t_arg *arg)
{
	//Lead padding is null (i.e. spaces) if there's no FLAG_MINUS, and FLAG_ZERO 
	//is inactive (i.e. if it's unset, or if it is set but so is FLAG_PREC)
	while (!(FLAG_MINUS & arg->flags) && !((FLAG_ZERO & arg->flags) && \
		!(FLAG_PREC & arg->flags)) && arg->width > 0)
	{
		arg->n_bytes += write(1, " ", 1);
		arg->width--;
	}
	print_modifier(arg);
	//Lead padding is done with zeroes and after the modifier if FLAG_ZERO is set, but
	//not precision nor FLAG_MINUS, as they both have precedence over FLAG_ZERO
	while ((FLAG_ZERO & arg->flags) && \
		!((FLAG_MINUS + FLAG_PREC) & arg->flags) && arg->width > 0)
	{
		arg->n_bytes += write(1, "0", 1);
		arg->width--;
	}
}
