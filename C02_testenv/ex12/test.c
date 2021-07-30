#include <unistd.h>
#include <stdio.h>
#include <string.h>
void	printhex(unsigned int i);
int		char_is_printable(char	c);

void	ft_putstr(unsigned char *str)
{
	//unsigned int ptr;

	//ptr = &str;
	printhex((unsigned int)str);
	write(1, ":", 1);
}

void	printhex(unsigned int i)
{
	char	*hexBase;

	hexBase = "0123456789abcdef";
	if (i > 15)
		printhex(i / 16);
	write(1, &hexBase[i % 16], 1);
}

void	print_endline (char *str)
{
	int	i;

	i = 0;
	while (i < 16)
	{
		if (char_is_printable(str[i]))
			write(1, &str[i], 1);
		else
			write(1, ".", 1);
		i++;
	}
	write(1, "\n", 1);
}

void	void_to_str(char *str, void *addr, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (i < size)
	{
		str = addr;
		i++;
		addr++;
	}
}

void	ft_print_memory(void *addr, unsigned int size)
{
	int		i;
	char	str[size + 1];

	i = 0;
	void_to_str(str, addr, size);
	while (str[i] != '\0')
	{
		if (i == 0)
			ft_putstr((unsigned char *)str);
		else if (i % 16 == 0)
		{
			print_endline(&addr[i - 16]);
			ft_putstr((unsigned char*)&str[i]);
		}
		if (i % 2 == 0)
			write(1, " ", 1);
		printhex(str[i]);
		i++;
	}
	print_endline(&str[i - (i % 16)]);
}

int	main(void)
{
	char	*str;

	str = "This is a test string with a total of 45 char";
	printf("%s, size = %lu\n", str, strlen(str));
	printf("Address : %p\n", str);
	ft_print_memory(str, sizeof(str));
	return (0);
}

int	char_is_printable(char c)
{
	if (c < 32 || c > 127)
		return (0);
	return (1);
}
