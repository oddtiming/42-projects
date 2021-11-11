#include "ft_printf.h"
#include <stdio.h>

int	stdarg_test(char *str, ...)
{
	va_list	arg_ptr;
//	va_list	arg_ptr_copy;
	int		i = 0;
	int 	sum_total = 0;
	char	*joined_string;
	int		temp_int = 0;
	void	*temp_ptr;

	va_start(arg_ptr, str);
	while (str[i])
	{
		if (str[i] == 'd')
		{
			//This is a valid way to store any and all types of variable in va_arg
			temp_ptr = va_arg(arg_ptr, void *);
			sum_total += (int)((int *)temp_ptr);
		}
		else if (str[i] == 's')
		{
			joined_string = ft_strjoin_free(joined_string, va_arg(arg_ptr, char *));
		}
		else if (str[i] == 'c')
		{
			printf("char c = %c\n", va_arg(arg_ptr, int));
		}
		i++;
	}
	va_end(arg_ptr);
	printf("sum_total at the end of stdarg_test = '%d'\n", sum_total);
	printf("str_joined at the end of stdarg_test = '%s'\n", joined_string);
	return (ft_strlen(joined_string));
}

int	main()
{
	int		i1, i2, i3;
	char	*str1 = "This is the first string";
	char	*str2 = " And I shall want to add this";
	char	*format = "dddss";
	int		return_value;
	
	i1 = 48;
	i2 = 2;
	i3 = 49;
	printf("format = %s\n", format);
	return_value = stdarg_test(format, i1, i2, i3, str1, str2);
	printf("The return value is '%d'\n", return_value);
	return (0);
}