#include "ft_printf_bonus.h"

//Here the idea is simply to print all the blank characters/zeros before or after the character
void	ft_printf_char(t_arg *arg, va_list ap)
{
	char	c;

	c = va_arg(ap, int);
	if ((FLAG_WIDTH & arg->flags) == 0)
	{
		arg->n_bytes += ft_putchar_ret(c);
		return ;
	}
	arg->n_bytes += arg->width;
	if (FLAG_MINUS & arg->flags)
	{
		write(1, &c, 1);
		arg->width--;
		while (arg->width--)
			write(1, " ", 1);
	}
	while (arg->width-- > 1)
	{
		if (FLAG_ZERO & arg->flags)
			write(1, "0", 1);
		else
			write(1, " ", 1);
	}
	if (arg->width)
		write(1, &c, 1);
}

void	ft_printf_char_dev(t_arg *arg, char c)
{
	if (!(FLAG_WIDTH & arg->flags) || (FLAG_MINUS & arg->flags))
		arg->n_bytes += ft_putchar_ret(c);
	if ((FLAG_ZERO & arg->flags) && !(FLAG_MINUS & arg->flags))
		arg->var_type = '0';
	else
		arg->var_type = ' ';
	while ((FLAG_WIDTH & arg->flags) && (arg->width-- > 1))
			arg->n_bytes += ft_putchar_ret(arg->var_type);
	if (!(FLAG_MINUS & arg->flags) && (FLAG_WIDTH & arg->flags))
		arg->n_bytes += ft_putchar_ret(c);
}

//WIP
void	ft_printf_str(t_arg *arg, va_list ap)
{
	char	*arg_to_str;
	int		str_len;

	arg_to_str = ft_strdup(va_arg(ap, char *));
	str_len = ft_strlen(arg_to_str);
	if (str_len >= arg->width)
}

void	ft_printf_nbr(t_arg *arg, va_list ap)
{
	
}

void	ft_printf_u_nbr(t_arg *arg, va_list ap)
{
	
}

void	ft_printf_addr(t_arg *arg, va_list ap)
{
	
}

void	ft_printf_hex(t_arg *arg, va_list ap)
{
	
}

int main(void)
{
	t_arg arg;

	arg.width = 5;
	// arg.flags = FLAG_ZERO + FLAG_WIDTH + FLAG_MINUS;
	// arg.flags = FLAG_ZERO + FLAG_WIDTH;
	// arg.flags = FLAG_WIDTH;
	arg.flags = 0;
	arg.n_bytes = 0;

	ft_printf_char_dev(&arg, 'a');
	printf("\narg->n_bytes = %d\n", arg.n_bytes);
	printf("arg->width = %d\n", arg.width);
	return (0);
}