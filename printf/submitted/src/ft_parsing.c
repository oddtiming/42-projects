/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyahoui- <iyahoui-@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 16:47:00 by iyahoui-          #+#    #+#             */
/*   Updated: 2021/11/16 16:47:03 by iyahoui-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	arg_parse(t_arg *arg, va_list ap)
{
	int		flags_index[6];
	int		num_value;

	num_value = 0;
	while (num_value < 6)
	{
		flags_index[num_value] = 1 << num_value;
		num_value++;
	}
	while (is_set(arg->fmt[++arg->index], "-0.# +123456789*") \
		&& arg->fmt[arg->index])
	{
		num_value = is_set_ret(arg->fmt[arg->index], FLAGS);
		if (num_value != -1)
			arg->flags |= flags_index[num_value];
		else if ((arg->fmt[arg->index] >= '1' && \
			arg->fmt[arg->index] <= '9') || arg->fmt[arg->index] == '*')
			arg_num_value(arg, ap);
	}
	arg_dispatch(arg, ap);
}

void	arg_num_value(t_arg *arg, va_list ap)
{
	int	num_value;

	if (arg->fmt[arg->index] == '*')
		num_value = va_arg(ap, int);
	else
	{
		num_value = ft_atoi(&arg->fmt[arg->index]);
		arg->index += ft_log_calc(num_value, 10) - 1;
	}
	if (FLAG_PREC & arg->flags)
	{
		arg->precision = num_value;
		if (num_value < 0)
			arg->flags &= ~FLAG_PREC;
		return ;
	}
	if (num_value < 0)
	{
		num_value *= -1;
		arg->flags |= FLAG_MINUS;
	}
	arg->width = num_value;
}

void	arg_dispatch(t_arg *arg, va_list ap)
{
	arg->var_type = arg->fmt[arg->index];
	if (arg->var_type == 'c')
		ft_print_c(arg, (char)va_arg(ap, int));
	else if (arg->var_type == 's')
		ft_print_s(arg, va_arg(ap, char *));
	else if (arg->var_type == 'p')
		ft_print_p(arg, (size_t)va_arg(ap, void *));
	else if (is_set(arg->var_type, "di"))
		ft_print_di(arg, va_arg(ap, int));
	else if (arg->var_type == 'u')
		ft_print_u(arg, va_arg(ap, int));
	else if (is_set(arg->var_type, "xX"))
		ft_print_x(arg, va_arg(ap, int));
	else
		ft_print_c(arg, arg->var_type);
	arg->index += 1;
}
