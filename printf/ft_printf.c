#include "ft_printf.h"

int	ft_printf(char const *format, ...)
{
	va_list	ap;
	t_arg	holder;

	va_start(ap, format);
	printf_struct_init(&holder, format);
	printf("holder.n_bytes = %d\n", holder.n_bytes);
	va_end(ap);
	return (holder.n_bytes);
}
/*	
 *	oct 18th 2021 todo
 *	List of proceedings:
 *	In ft_printf iterate through the string, if hit a % sign, pass to 
 *	printf_arg_parse;
 *	NOTE: width and precision are important variables, but meaningless as standalone, since we can have a width = 0 as an active
 *		, so a width flag needs to be set in addition to the 6 required flags.
 *		I also believe that width and precisio0n are set as unsigned ints, since -1 gives the full length of any string with no warning
 *	else write(s[holder.index]; holder.index++; holder.n_bytes++;)
 *	printf_arg_parse will increment holder.index and instigate the corresponding flags and var_type, then call 
 *	printf_arg_dispatch that will call relevant function depending on the var_type.
 *	Each subfunction will increment holder.n_bytes.
 */

int	main(void)
{
	int		i1, i2, i3;
	char	*str1 = "This is the first string";
	char	*str2 = " And I shall want to add this";
	char	*format = " 1 = %%d : %d, 2 = %%i: %i, %u, %%x of str1: %x, %s, %s, %c, %%p of str1: %p, %%X of i1: %X\n";
	int		return_value;

	i1 = -48;
	i2 = 2;
	i3 = 49;
	printf("format = %s\n", format);
	return_value = ft_printf(format, i1, i1, i1, str1, str1, str2, 'c', str1, i1);
	printf("The return value of ft_printf is '%d'\n", return_value);
	return_value = printf(format, i1, i1, i1, str1, str1, str2, 'c', str1, i1);
	printf("The return value of printf is '%d'\n", return_value);
	return (0);
}