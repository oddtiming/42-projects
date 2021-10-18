#include "ft_printf.h"

void	printf_struct_init(t_arg *holder, char const *format)
{
	holder->n_bytes = 0;
	holder->index = 0;
	holder->precision = 0;
	holder->width = 0;
	holder->var_type = 0;
	holder->format = ft_strdup(format);
}