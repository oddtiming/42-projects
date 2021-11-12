/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyahoui- <iyahoui-@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 14:07:21 by iyahoui-          #+#    #+#             */
/*   Updated: 2021/11/12 16:09:58 by iyahoui-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	arg_dispatch(t_arg *arg, va_list ap)
{
	arg->index += 1;
	arg->var_type = arg->fmt[arg->index];
	if (arg->var_type == 'c')
		arg->n_bytes += ft_putchar_ret((char)va_arg(ap, int));
	else if (arg->var_type == '%')
		arg->n_bytes += ft_putchar_ret('%');
	else if (arg->var_type == 's')
		arg->n_bytes += ft_putstr_ret(va_arg(ap, char *));
	else if (is_set(arg->var_type, "di"))
		arg->n_bytes += ft_putnbr_ret(va_arg(ap, int));
	else if (arg->var_type == 'u')
		arg->n_bytes += ft_putnbr_unsigned_ret(va_arg(ap, int));
	else if (arg->var_type == 'p')
	{
		arg->n_bytes += ft_putstr_ret("0x");
		ft_puthex_size_t(arg, (size_t)va_arg(ap, void *));
	}
	else if (is_set(arg->var_type, "xX"))
		ft_puthex_int(va_arg(ap, int), arg);
	arg->index += 1;
}

void	arg_parse(t_arg *arg, va_list ap)
{
	arg_dispatch(arg, ap);
}

int	ft_printf(char const *format, ...)
{
	va_list	ap;
	t_arg	arg;

	va_start(ap, format);
	printf_struct_init(&arg, format);
	while (format[arg.index])
	{
		if (format[arg.index] == '%')
			arg_parse(&arg, ap);
		else
		{
			write(1, &format[arg.index], 1);
			arg.index += 1;
			arg.n_bytes += 1;
		}
	}
	va_end(ap);
	free(arg.fmt);
	return (arg.n_bytes);
}
