/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_struct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyahoui- <iyahoui-@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 14:54:29 by iyahoui-          #+#    #+#             */
/*   Updated: 2021/11/16 14:54:30 by iyahoui-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//Sets everything to zero on first passage, not sure if necessary or if
//I could have declared a static struct in ft_printf
void	printf_struct_init(t_arg *arg, char const *format)
{
	arg->n_bytes = 0;
	arg->index = 0;
	arg->precision = 0;
	arg->width = 0;
	arg->var_type = 0;
	arg->flags = 0;
	arg->fmt = ft_strdup(format);
}

//Reset the conversion-specific values of the struct
void	printf_struct_reset(t_arg *arg)
{
	arg->precision = 0;
	arg->width = 0;
	arg->var_type = 0;
	arg->flags = 0;
}
