/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyahoui- <iyahoui-@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 14:57:26 by iyahoui-          #+#    #+#             */
/*   Updated: 2021/11/16 15:07:09 by iyahoui-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"

# define FLAGS "-0.# +"

typedef struct s_arg
{
	char			*fmt;
	int				index;
	char			var_type;
	int				n_bytes;
	int				width;
	int				precision;
	unsigned int	flags;
}	t_arg;

typedef enum e_flags
{
	FLAG_MINUS = 0x1,
	FLAG_ZERO = 0x2,
	FLAG_PREC = 0x4,
	FLAG_HASH = 0x8,
	FLAG_SPACE = 0x10,
	FLAG_PLUS = 0x20,
	FLAG_NEG = 0x40
}	t_flags;

//INITIALIZING
int		ft_printf(const char *format, ...);
void	arg_parse(t_arg *arg, va_list ap);
void	arg_dispatch(t_arg *arg, va_list ap);
void	arg_num_value(t_arg *arg, va_list ap);
void	printf_struct_init(t_arg *arg, char const *format);
void	printf_struct_reset(t_arg *arg);

//PADDING
void	front_pad(t_arg *arg);
void	print_modifier(t_arg *arg);

//UTILS
void	ft_puthex_size_t(t_arg *arg, size_t i);
int		ft_putstr_n_ret(const char *s, int prec);
int		ft_putnbr_unsigned_n_ret(unsigned int n, int prec);

//PRINTING
void	ft_print_c(t_arg *arg, char c);
void	ft_print_s(t_arg *arg, char *arg_to_str);
void	ft_print_di(t_arg *arg, int nbr);
void	ft_print_u(t_arg *arg, unsigned int nbr);
void	ft_print_x(t_arg *arg, unsigned int nbr);
void	ft_print_p(t_arg *arg, size_t addr);

#endif