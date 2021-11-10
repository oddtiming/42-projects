#include "ft_printf.h"
#include <limits.h>
#include <stdio.h>
#include <string.h>


//Function to print bits taken from https://stackoverflow.com/questions/111928/is-there-a-printf-converter-to-print-in-binary-format
const char *byte_to_binary(int x)
{
    static char b[9];
    b[0] = '\0';

    int z;
    for (z = 128; z > 0; z >>= 1)
    {
        strcat(b, ((x & z) == z) ? "1" : "0");
    }

    return b;
}

void	s_tester(void)
{
	int	return_value;

	return_value = 0;
	printf("--------TESTS FOR STRINGS--------\n");
	printf("*******************************\n");
	printf("-------- TESTS FOR '.' --------\n");
	printf("*******************************\n\n");
	printf("format string = \" %%.2s %%.1s \"\n");
	return_value = printf("\" %.2s %.1s \"", " - ", "");
	printf("\nreturn value of printf = %d\n", return_value);
	return_value = ft_printf("\" %.2s %.1s \"", "", "-");
	printf("\nreturn value of ft_printf = %d\n\n", return_value);
	printf("format string = \" %%.3s %%.2s \"\n");
	return_value = printf("\" %.3s %.2s \"", " - ", "");
	printf("\nreturn value of printf = %d\n", return_value);
	return_value = ft_printf("\" %.3s %.2s \"", " - ", "");
	printf("\nreturn value of ft_printf = %d\n\n", return_value);
	printf("format string = \"%%.1s %%.2s %%.3s %%.4s \"\n");
	return_value = printf("\" %.1s %.2s %.3s %.4s \"", " - ", "", "4", "");
	printf("\nreturn value of printf = %d\n", return_value);
	return_value = ft_printf("\" %.1s %.2s %.3s %.4s \"", " - ", "", "4", "");
	printf("\nreturn value of ft_printf = %d\n\n", return_value);
	printf("format string = \" %%.2s %%.3s %%.4s %%.5s %%.1s \"\n");
	return_value = printf("\" %.2s %.3s %.4s %.5s %.1s \"", " - ", "", "4", "", "2 ");
	printf("\nreturn value of printf = %d\n", return_value);
	return_value = ft_printf("\" %.2s %.3s %.4s %.5s %.1s \"", " - ", "", "4", "", "2 ");
	printf("\nreturn value of ft_printf = %d\n\n", return_value);

	printf("*******************************\n");
	printf("-------- TESTS FOR ' ' --------\n");
	printf("*******************************\n\n");
	printf("format string = \" %% s \", \"-\"\n");
	return_value = printf("\" % s \"", "-");
	printf("\nreturn value of printf = %d\n", return_value);
	return_value = ft_printf("\" % s \"", "-");
	printf("\nreturn value of ft_printf = %d\n\n", return_value);
	printf("format string = \" %% s %% s \", \"\", \"-\"\"\n");
	return_value = printf("\" % s % s \"", "", "-");
	printf("\nreturn value of printf = %d\n", return_value);
	return_value = ft_printf("\" % s % s \"", "", "-");
	printf("\nreturn value of ft_printf = %d\n\n", return_value);
	printf("format string = \" %% s %% s \", \" - \", \"\"\n");
	return_value = printf("\" % s % s \"", " - ", "");
	printf("\nreturn value of printf = %d\n", return_value);
	return_value = ft_printf("\" % s % s \"", " - ", "");
	printf("\nreturn value of ft_printf = %d\n\n", return_value);
	printf("format string = \" %% s %% s %% s %% s \", \" - \", \"\", \"4\", \"\"\n");
	return_value = printf("\" % s % s % s % s \"", " - ", "", "4", "");
	printf("\nreturn value of printf = %d\n", return_value);
	return_value = ft_printf("\" % s % s % s % s \"", " - ", "", "4", "");
	printf("\nreturn value of ft_printf = %d\n\n", return_value);
	printf("format string = \" %% s %% s %% s %% s %% s \", \" - \", \"\", \"4\", \"\", \"2 \"\n");
	return_value = printf("\" % s % s % s % s % s \"", " - ", "", "4", "", "2 ");
	printf("\nreturn value of printf = %d\n", return_value);
	return_value = ft_printf("\" % s % s % s % s % s \"", " - ", "", "4", "", "2 ");
	printf("\nreturn value of ft_printf = %d\n\n", return_value);

	printf("************************************\n");
	printf("-------- TESTS FOR GFIELDER --------\n");
	printf("************************************\n\n");
	char *s_hidden = "hi low\0don't print me lol\0";

	printf("arg = (\"%%.03s\", \"hi low\\0don't print me lol\\0a\")\n");
	return_value = printf("\"%.03s\"", s_hidden);
	printf("\nreturn value of printf = %d\n", return_value);
	return_value = ft_printf("\"%.03s\"", s_hidden);
	printf("\nreturn value of ft_printf = %d\n\n", return_value);

	printf("arg = (\"%%.09s\", \"hi low\\0don't print me lol\\0a\")\n");
	return_value = printf("\"%.09s\"", s_hidden);
	printf("\nreturn value of printf = %d\n", return_value);
	return_value = ft_printf("\"%.09s\"", s_hidden);
	printf("\nreturn value of ft_printf = %d\n\n", return_value);

	printf("arg = (\"%%.03s\", NULL)\n");
	return_value = printf("\"%.03s\"", NULL);
	printf("\nreturn value of printf = %d\n", return_value);
	return_value = ft_printf("\"%.03s\"", NULL);
	printf("\nreturn value of ft_printf = %d\n\n", return_value);

	printf("arg = (\"%%.09s\", NULL)\n");
	return_value = printf("\"%.09s\"", NULL);
	printf("\nreturn value of printf = %d\n", return_value);
	return_value = ft_printf("\"%.09s\"", NULL);
	printf("\nreturn value of ft_printf = %d\n\n", return_value);

	printf("arg = (\"%%.01s\", \"\\0\")\n");
	return_value = printf("\"%.01s\"", "\0");
	printf("\nreturn value of printf = %d\n", return_value);
	return_value = ft_printf("\"%.01s\"", "\0");
	printf("\nreturn value of ft_printf = %d\n\n", return_value);

	printf("arg = (\"%%.03s\", \"\\0\")\n");
	return_value = printf("\"%.03s\"", "\0");
	printf("\nreturn value of printf = %d\n", return_value);
	return_value = ft_printf("\"%.03s\"", "\0");
	printf("\nreturn value of ft_printf = %d\n\n", return_value);

	printf("arg = (\"%%.09s\", \"\\0\")\n");
	return_value = printf("\"%.09s\"", "\0");
	printf("\nreturn value of printf = %d\n", return_value);
	return_value = ft_printf("\"%.09s\"", "\0");
	printf("\nreturn value of ft_printf = %d\n\n", return_value);

	printf("arg = (\"%%-.09s\", \"hi low\\0don't print me lol\\0a\")\n");
	return_value = printf("\"%-.09s\"", s_hidden);
	printf("\nreturn value of printf = %d\n", return_value);
	return_value = ft_printf("\"%-.09s\"", s_hidden);
	printf("\nreturn value of ft_printf = %d\n\n", return_value);

	printf("arg = (\"%%*s\", 32, \"abc\")\n");
	return_value = printf("\"%*s\"", 32, "abc");
	printf("\nreturn value of printf = %d\n", return_value);
	return_value = ft_printf("\"%*s\"", 32, "abc");
	printf("\nreturn value of ft_printf = %d\n\n", return_value);

// "%*s", 32, "abc"
}

void	p_tester()
{
	int	return_value = 0;

	printf("**********************************\n");
	printf("--------TESTS FOR POINTERS--------\n");
	printf("**********************************\n\n");
	printf("*******************************\n");
	printf("-------- TESTS FOR '-' --------\n");
	printf("*******************************\n\n");
	printf("args = (\" %%-9p %%-10p \", LONG_MIN, LONG_MAX)\n");
	return_value = printf("\" %-9p %-10p \"", LONG_MIN, LONG_MAX);
	printf("\nreturn value of printf = %d\n", return_value);
	return_value = ft_printf("\" %-9p %-10p \"", LONG_MIN, LONG_MAX);
	printf("\nreturn value of ft_printf = %d\n\n", return_value);
	printf("args = (\" %%-13p %%-14p \", ULONG_MAX, -ULONG_MAX)\n");
	return_value = printf("\" %-13p %-14p \"", ULONG_MAX, -ULONG_MAX);
	printf("\nreturn value of printf = %d\n", return_value);
	return_value = ft_printf("\" %-13p %-14p \"", ULONG_MAX, -ULONG_MAX);
	printf("\nreturn value of ft_printf = %d\n\n", return_value);

}

void	d_tester()
{
	int	return_value = 0;

	printf("**********************************\n");
	printf("--------TESTS FOR INTEGERS(d)--------\n");
	printf("**********************************\n\n");
	printf("*******************************\n");
	printf("-------- TESTS FOR '-' --------\n");
	printf("*******************************\n\n");
	printf("arg = (\"%%-3d\", -11)\n");
	return_value = printf("\"%-3d\"", -11);
	printf("\nreturn value of printf = %d\n", return_value);
	return_value = ft_printf("\"%-3d\"", -11);
	printf("\nreturn value of ft_printf = %d\n\n", return_value);
	printf("arg = (\" %%-4d \", -14)\n");
	return_value = printf("\" %-4d \"", -14);
	printf("\nreturn value of printf = %d\n", return_value);
	return_value = ft_printf("\" %-4d \"", -14);
	printf("\nreturn value of ft_printf = %d\n\n", return_value);
	printf("arg = (\" %%-5d \", -15)\n");
	return_value = printf("\" %-5d \"", -15);
	printf("\nreturn value of printf = %d\n", return_value);
	return_value = ft_printf("\" %-5d \"", -15);
	printf("\nreturn value of ft_printf = %d\n\n", return_value);
	printf("arg = (\" %%-6d \", -16)\n");
	return_value = printf("\" %-6d \"", -16);
	printf("\nreturn value of printf = %d\n", return_value);
	return_value = ft_printf("\" %-6d \"", -16);
	printf("\nreturn value of ft_printf = %d\n\n", return_value);
	printf("arg = (\" %%-3d \", -101)\n");
	return_value = printf("\" %-3d \"", -101);
	printf("\nreturn value of printf = %d\n", return_value);
	return_value = ft_printf("\" %-3d \"", -101);
	printf("\nreturn value of ft_printf = %d\n\n", return_value);
	printf("arg = (\" %%-9d \", INT_MAX)\n");
	return_value = printf("\" %-9d \"", INT_MAX);
	printf("\nreturn value of printf = %d\n", return_value);
	return_value = ft_printf("\" %-9d \"", INT_MAX);
	printf("\nreturn value of ft_printf = %d\n\n", return_value);
	printf("arg = (\" %%-10d \", INT_MIN)\n");
	return_value = printf("\" %-10d \"", INT_MIN);
	printf("\nreturn value of printf = %d\n", return_value);
	return_value = ft_printf("\" %-10d \"", INT_MIN);
	printf("\nreturn value of ft_printf = %d\n\n", return_value);
	printf("arg = (\" %%-9d %%-10d %%-11d %%-12d %%-13d %%-14d %%-15d\", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42)\n");
	return_value = printf("\" %-9d %-10d %-11d %-12d %-13d %-14d %-15d\"", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	printf("\nreturn value of printf = %d\n", return_value);
	return_value = ft_printf("\" %-9d %-10d %-11d %-12d %-13d %-14d %-15d\"", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	printf("\nreturn value of ft_printf = %d\n\n", return_value);
	
	printf("*******************************\n");
	printf("-------- TESTS FOR '0' --------\n");
	printf("*******************************\n\n");
	printf("arg = (\"%%04d\", 9)\n");
	return_value = printf("\"%04d\"", 9);
	printf("\nreturn value of printf = %d\n", return_value);
	return_value = ft_printf("\"%04d\"", 9);
	printf("\nreturn value of ft_printf = %d\n\n", return_value);
	printf("arg = (\" %%03d \", 15)\n");
	return_value = printf("\" %03d \"", 15);
	printf("\nreturn value of printf = %d\n", return_value);
	return_value = ft_printf("\" %03d \"", 15);
	printf("\nreturn value of ft_printf = %d\n\n", return_value);
	printf("arg = (\" %%04d \", 16)\n");
	return_value = printf("\" %04d \"", 16);
	printf("\nreturn value of printf = %d\n", return_value);
	return_value = ft_printf("\" %04d \"", 16);
	printf("\nreturn value of ft_printf = %d\n\n", return_value);
	printf("arg = (\" %%05d \", 17)\n");
	return_value = printf("\" %05d \"", 17);
	printf("\nreturn value of printf = %d\n", return_value);
	return_value = ft_printf("\" %05d \"", 17);
	printf("\nreturn value of ft_printf = %d\n\n", return_value);
	printf("arg = (\" %%012d \", LONG_MIN)\n");
	return_value = printf("\" %012d \"", LONG_MIN);
	printf("\nreturn value of printf = %d\n", return_value);
	return_value = ft_printf("\" %012d \"", LONG_MIN);
	printf("\nreturn value of ft_printf = %d\n\n", return_value);
	printf("arg = (\" %%09d %%010d %%011d %%012d %%013d %%014d %%015d\", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42)\n");
	return_value = printf("\" %09d %010d %011d %012d %013d %014d %015d\"", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	printf("\nreturn value of printf = %d\n", return_value);
	return_value = ft_printf("\" %09d %010d %011d %012d %013d %014d %015d\"", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	printf("\nreturn value of ft_printf = %d\n\n", return_value);

	printf("********************************\n");
	printf("------ TESTS FOR prec = 0 ------\n");
	printf("********************************\n\n");
	printf("arg = (\" %%.0d \", 0)\n");
	return_value = printf("\" %.0d \"", 0);
	printf("\nreturn value of printf = %d\n", return_value);
	return_value = ft_printf("\" %.0d \"", 0);
	printf("\nreturn value of ft_printf = %d\n\n", return_value);
	printf("arg = (\" %%.d \", 0)\n");
	return_value = printf("\" %.d \"", 0);
	printf("\nreturn value of printf = %d\n", return_value);
	return_value = ft_printf("\" %.d \"", 0);
	printf("\nreturn value of ft_printf = %d\n\n", return_value);
	printf("arg = (\" %%.1d \", 0)\n");
	return_value = printf("\" %.1d \"", 0);
	printf("\nreturn value of printf = %d\n", return_value);
	return_value = ft_printf("\" %.1d \"", 0);
	printf("\nreturn value of ft_printf = %d\n\n", return_value);
	printf("arg = (\" %%01.0d \", 0)\n");
	return_value = printf("\" %01.0d \"", 0);
	printf("\nreturn value of printf = %d\n", return_value);
	return_value = ft_printf("\" %01.0d \"", 0);
	printf("\nreturn value of ft_printf = %d\n\n", return_value);

}

void	x_tester()
{
	int	return_value = 0;

	// printf("******************************\n");
	// printf("--------TESTS FOR HEXA--------\n");
	// printf("******************************\n\n");
	// printf("*******************************\n");
	// printf("-------- TESTS FOR '#' --------\n");
	// printf("*******************************\n\n");
	// printf("arg = (\" %%#x \", 0)\n");
	// return_value = printf("\" %#x \"", 0);
	// printf("\nreturn value of printf = %d\n", return_value);
	// return_value = ft_printf("\" %#x \"", 0);
	// printf("\nreturn value of ft_printf = %d\n\n", return_value);
	// printf("arg = (\" %%#x \", LONG_MIN)\n");
	// return_value = printf("\" %#x \"", LONG_MIN);
	// printf("\nreturn value of printf = %d\n", return_value);
	// return_value = ft_printf("\" %#x \"", LONG_MIN);
	// printf("\nreturn value of ft_printf = %d\n\n", return_value);
	// printf("arg = (\" %%#x %%#x %%#x %%#x %%#x %%#x %%#x\", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42)\n");
	// return_value = printf("\" %#x %#x %#x %#x %#x %#x %#x\"", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	// printf("\nreturn value of printf = %d\n", return_value);
	// return_value = ft_printf("\" %#x %#x %#x %#x %#x %#x %#x\"", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	// printf("\nreturn value of ft_printf = %d\n\n", return_value);
	// printf("arg = (\" %%#X \", 0)\n");
	// return_value = printf("\" %#X \"", 0);
	// printf("\nreturn value of printf = %d\n", return_value);
	// return_value = ft_printf("\" %#X \"", 0);
	// printf("\nreturn value of ft_printf = %d\n\n", return_value);
	// printf("arg = (\" %%#X \", LONG_MIN)\n");
	// return_value = printf("\" %#X \"", LONG_MIN);
	// printf("\nreturn value of printf = %d\n", return_value);
	// return_value = ft_printf("\" %#X \"", LONG_MIN);
	// printf("\nreturn value of ft_printf = %d\n\n", return_value);
	// printf("arg = (\" %%#X %%#X %%#X %%#X %%#X %%#X %%#X\", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42)\n");
	// return_value = printf("\" %#X %#X %#X %#X %#X %#X %#X\"", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	// printf("\nreturn value of printf = %d\n", return_value);
	// return_value = ft_printf("\" %#X %#X %#X %#X %#X %#X %#X\"", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	// printf("\nreturn value of ft_printf = %d\n\n", return_value);

	printf("********************************\n");
	printf("------ TESTS FOR prec = 0 ------\n");
	printf("********************************\n\n");
	printf("arg = (\"%%-10.X\", 0)\n");
	return_value = printf("\"%-10.X\"", 0);
	printf("\nreturn value of printf = %d\n", return_value);
	return_value = ft_printf("\"%-10.X\"", 0);
	printf("\nreturn value of ft_printf = %d\n\n", return_value);

	printf("arg = (\"%%01.1X\", 0)\n");
	return_value = printf("\"%01.1X\"", 0);
	printf("\nreturn value of printf = %d\n", return_value);
	return_value = ft_printf("\"%01.1X\"", 0);
	printf("\nreturn value of ft_printf = %d\n\n", return_value);
}

int	main(void)
{
	int	return_value;
	// s_tester();
	// p_tester();
	d_tester();
	// x_tester();

	printf("%%05c | 'a''\n");
	return_value = printf("\"%05c\"\n", 'a');
	printf("return_value = %d\n", return_value);
	return_value = ft_printf("\"%05c\"\n", 'a');
	printf("return_value = %d\n", return_value);
}