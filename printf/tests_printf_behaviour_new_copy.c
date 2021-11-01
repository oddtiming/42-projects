#include <stdio.h>
#include <unistd.h>
#include <limits.h>

void	printhex_long(long i)
{
	char	*hexBase;

	hexBase = "0123456789abcdef";
	if (i > 15)
		printhex_long(i / 16);
	write(1, &hexBase[i % 16], 1);
}

void	printhex_int(unsigned int i)
{
	char	*hexBase;

	hexBase = "0123456789abcdef";
	if (i > 15)
		printhex_int(i / 16);
	write(1, &hexBase[i % 16], 1);
}

int	main()
{
	int		i = -42;
	char	*s1 = "This is a pretty long string.";
	char	c = 'k';

	puts("*****************************************\n");
	puts("----------TESTS FOR %CONVERSIONS---------\n");
	puts("*****************************************\n");

	printf("%%d = %d\n", i);
	printf("%%i = %i\n", i);
	printf("%%u = %u\n", i);
	printf("%%x = %x\n", i);
	printf("%%X = %X\n", i);
	printf("%%o = %o\n", i);
	printf("%%s1 = %s\n", s1);
	printf("%%s1 = %s\n", s1);
	printf("%%c = %c\n", c);
	printf("%%p of s1 = %p\n", s1);



	puts("\n*****************************************\n");
	puts("----------TESTS FOR \"-0.\" FLAGS----------\n");
	puts("*****************************************\n");

	puts("----------TESTS FOR \"-\" FLAG----------\n");
	printf("%%-d = %-d\n", i);
	printf("%%-i = %-i\n", i);
	printf("%%-u = %-u\n", i);
	printf("%%-x = %-x\n", i);
	printf("%%-X = %-X\n", i);
	printf("%%-o = %-o\n", i);
	printf("%%-s1 = %-s\n", s1);
	printf("%%-c = %-c\n", c);
	printf("%%-p of s1 = %-p\n", s1);

	puts("\n----------TESTS FOR \"0\" FLAG----------\n");
	printf("%%0d = %0d\n", i);
	printf("%%0i = %0i\n", i);
	printf("%%0u = %0u\n", i);
	printf("%%0x = %0x\n", i);
	printf("%%0X = %0X\n", i);
	printf("%%0o = %0o\n", i);
	//0 conversions are UB for s, c, and p
//	printf("%%0s1 = %0s\n", s1);
//	printf("%%0c = %0c\n", c);
//	printf("%%0p of s1 = %0p\n", s1);

	puts("\n----------TESTS FOR \".\" FLAG----------\n");
	printf("%%.d = %.d\n", i);
	printf("%%.i = %.i\n", i);
	printf("%%.u = %.u\n", i);
	printf("%%.x = %.x\n", i);
	printf("%%.X = %.X\n", i);
	printf("%%.o = %.o\n", i);
	printf("%%.s1 = %.s\n", s1);
	printf("%%.c = %.c\n", c);
	printf("%%.p of s1 = %.p\n", s1);

	puts("\n*****************************************\n");
	puts("-----TESTS FOR \"-0.\" FLAGS W DIGITS----\n");
	puts("*****************************************\n");

	puts("----------TESTS FOR \"-\" FLAG----------");
	printf("%%-5d = %-5d\n", i);
	printf("%%-5i = %-5i\n", i);
	printf("%%-5u = %-5u\n", i);
	printf("%%-5x = %-5x\n", i);
	printf("%%-5X = %-5X\n", i);
	printf("%%-5o = %-5o\n", i);
	printf("%%-5s1 = %-5s\n", s1);
	printf("%%-5c = %-5c\n", c);
	printf("%%-5p of s1 = %-5p\n", s1);

	puts("\n----------TESTS FOR \"0\" FLAG----------");
	printf("%%019d = %019d\n", i);
	printf("%%019i = %019i\n", i);
	printf("%%019u = %019u\n", i);
	printf("%%019x = %019x\n", i);
	printf("%%019X = %019X\n", i);
	printf("%%019o = %019o\n", i);
	//0 conversions are UB for s, c, and p
//	printf("%%019s1 = %019s\n", s1);
//	printf("%%019c = %019c\n", c);
//	printf("%%019p of s1 = %019p\n", s1);
	puts("------EXTRA TESTS for extra types------");
	printf("%%019a = %019a\n", (double)i);
	printf("%%019f = %019f\n", (float)i);

	puts("\n----------TESTS FOR \".\" FLAG----------");
	printf("%%.51d = %.51d\n", i);
	printf("%%.5i = %.5i\n", i);
	printf("%%.5u = %.5u\n", i);
	printf("%%.5x = %.5x\n", i);
	printf("%%.5X = %.5X\n", i);
	printf("%%.5o = %.5o\n", i);
	printf("%%.5s1 = %.5s\n", s1);
	//'.' (precision) is UB with c and p
//	printf("%%.5c = %.5c\n", c);
//	printf("%%.5p of s1 = %.5p\n", s1);
	puts("------EXTRA TESTS for extra types------");
	printf("%%.5a = %.5a\n", (double)i);
	printf("%%.5f = %.5f\n", (float)i);

	puts("\n----------TESTS FOR \".0\" FLAG----------\n");
	printf("%%.051d = %.51d\n", i);
	printf("%%.05i = %.5i\n", i);
	printf("%%.019u = %.019u\n", i);
	printf("%%.019x = %.019x\n", i);
	printf("%%.019X = %.019X\n", i);
	printf("%%.019o = %.019o\n", i);
	printf("%%.019s1 = %.019s\n", s1);
	//'.' (precision) is UB with c and p
//	printf("%%.019c = %.019c\n", c);
//	printf("%%.019p of s1 = %.019p\n", s1);
	puts("------EXTRA TESTS for extra types------");
	printf("%%.019a = %.019a\n", (double)i);
	printf("%%.019f = %.019f\n", (double)i);
	printf("%%-.19f = %-.19f\n", (double)i);
	//Invalid conversion; "#-0 +" precede "."
//	printf("%%.-19f = %.-19f\n", (double)i);
	double db = -42.888;
	printf("For double db = -42.888, %%.019g = %.019g\n", (double)db);
	printf("%%e = %.32e\n", (double)db);

	puts("------COMBINATIONS------");
	printf("%%-.19d = %-.19d\n", i);
	printf("%%0+.19d = %0+.19d\n", i);
	//Invalid combination; "-" supercedes "0"
//	printf("%%-019d = %-019d\n", i);
	printf("%%019d = %019d\n", i);

	printf("%%p of s1 = %p\n", s1);
	printf("%%#x of (int)s1 = %#x\n", (int)s1);
	printf("%%#x of (long)s1 = %#lx\n", (long)s1);
	printf("%%p of (int)s1 = %p\n", (int)s1);
	printf("%%p of (long)s1 = %p\n", (long)s1);
	puts("");

	printf("sizeof(s1) = %lu\n", sizeof(s1));
	printf("sizeof(char *) = %lu\n", sizeof(char *));
	printf("sizeof(long) = %lu\n", sizeof(long));

	printf("Calling the printhex_long fct on (long) s1:\n");
	printhex_long((long)s1);
	printf("\nCalling the printhex_int fct on (int)s1:\n");
	printhex_int((int)s1);

	puts("");
	printf("%%19%% = %19%\n");
	printf("%%1$19s, %%1$0s, %%1$019s:\n %2$19s, %2$0s, %2$019s\n", "test1", s1, "test3");
	printf("%%x of s1 = %x\n", s1);
	printf("%%X of s1 = %X\n", s1);
	printf("%%#x of s1 = %#x\n", s1);
	printf("%%#X of s1 = %#X\n", s1);
	printf("%%#x of (long long)s1 = %#x\n", (long long)s1);
	printf("%%#X of (long long)s1 = %#X\n", (long long)s1);

	printf("%%x of 49 = %x\n", 49);

	printf("%%*.*f\nargs = '10, 10, 12345'\n%*.*d\n", 10, 10, 12345);
	printf("%%3$d\nargs = '10, \"test\", 12345'\n%3$d\n", 10, "test", 12345);
	int return_value;
	return_value = printf("c1 = '1': %c\nc2 = 0: %c\nc3 = '3': %c\n", '1', 0, '3');
//	return_value = printf("c1 = 0: %c\n", '1');
	printf("return value = '%d'\n", return_value);
	printf(" %c %c %c \n", 0, '1', '2');
	return_value = printf("%.10.5 10 9 8 728189 892 20s\n", "abcdefg");
	printf("return value = '%d'\n", return_value);
	return_value = printf("%*.*s!\n", 1, 1, "abcdefg");
	printf("%019s\n", "a");
	printf("%%0-10c of 'a': %0-10c\n", 'a');
	return_value = printf("%%s of empty string : %s\n", "");
	printf("return value = '%d'\n", return_value);
	return_value = printf("%%s of null string : %s\n", NULL);
	printf("return value = '%d'\n", return_value);
	printf("%d\n", 0x4);
	puts("------TESTS FOR %S------");
	printf("%%s for s = \"1234567890\":\n%s\n", "1234567890");
	printf("%%5s for s = \"1234567890\":\n%5s\n", "1234567890");
	printf("%%50s for s = \"1234567890\":\n%50s\n", "1234567890");
	printf("%%-50s for s = \"1234567890\":\n%-50s\n", "1234567890");
	printf("%%050s for s = \"1234567890\":\n%050s\n", "1234567890");
	printf("%%+50s for s = \"1234567890\":\n%+50s\n", "1234567890");
	printf("%%#50s for s = \"1234567890\":\n%#50s\n", "1234567890");
	printf("%% 50s for s = \"1234567890\":\n% 50s\n", "1234567890");
	printf("%%.5s for s = \"1234567890\":\n%.5s\n", "1234567890");
	printf("%%.50s for s = \"1234567890\":\n%.50s\n", "1234567890");
	printf("%%50.50s for s = \"1234567890\":\n%50.50s\n", "1234567890");
	printf("%%50.5s for s = \"1234567890\":\n%50.5s\n", "1234567890");
	printf("%%50.s for s = \"1234567890\":\n%50.s\n", "1234567890");


	puts("------TESTS FOR %c------");
	printf("%%10c of c = 'a': \"%10c\"\n", 'a');
	printf("%%0c of c = 'a': \"%0c\"\n", 'a');
	printf("%%010c of c = 'a': \"%010c\"\n", 'a');
	printf("%%-c of c = 'a': \"%-c\"\n", 'a');
	printf("%%-10c of c = 'a': \"%-10c\"\n", 'a');
	printf("%%-010c of c = 'a': \"%-010c\"\n", 'a');
	printf("%%.c of c = 'a': \"%.c\"\n", 'a');
	printf("%%.10c of c = 'a': \"%.10c\"\n", 'a');
	printf("%%.0c of c = 'a': \"%.0c\"\n", 'a');
	printf("%%0.0c of c = 'a': \"%0.0c\"\n", 'a');
	printf("%%+c of c = 'a': \"%+c\"\n", 'a');
	printf("%% c of c = 'a': \"% c\"\n", 'a');
	printf("%%00c of c = 'a': \"%00c\"\n", 'a');
	printf("%%-0c of c = 'a': \"%-0c\"\n", 'a');
	printf("%%*.*c of c = 'a': \"%*.*c\"\n", 0, 0, 'a');

	printf("\"%*.*s\"\nTest for width = %1$d and prec = %2$d for %%s of 0x0\n", 0, 10, NULL);
	printf("Tests for %%.0s: %.0s\n", s1);

	// int test_write_return_value;
	// printf("test for return value of write(1, \"blablabla\", 3): ");
	// test_write_return_value = write(1, "blablabla", 3);
	// printf("\ntest_write_return_value = %d\n", test_write_return_value);
	// printf("test for return value of write(1, \"blablabla\", 999): ");
	// test_write_return_value = write(1, "blablabla", 9);
	// printf("\ntest_write_return_value = %d\n", test_write_return_value);

	puts("*****************************************\n");
	puts("----------TESTS FOR %xX CONVERSIONS---------\n");
	puts("*****************************************\n");

	int x = 42;
	int prec = 10;
	int width = 15;

	printf("%%*.*x for width = %d, prec = %d and x = %d\n", width, prec, x);
	return_value = printf("\"%*.*x\"", width, prec, x);
	printf("\nreturn_value = %d\n", return_value);
	printf("%%#*.*x for width = %d, prec = %d and x = %d\n", width, prec, x);
	return_value = printf("\"%#*.*x\"", width, prec, x);
	printf("\nreturn_value = %d\n", return_value);
	printf("%%0*.*x for width = %d, prec = %d and x = %d\n", width, prec, x);
	return_value = printf("\"%0*.*x\"", width, prec, x);
	printf("\nreturn_value = %d\n", return_value);
	printf("%%0*x for width = %d, and x = %d\n", width, x);
	return_value = printf("\"%0*x\"", width, x);
	printf("\nreturn_value = %d\n", return_value);
	printf("%%0#*x for width = %d, and x = %d\n", width, x);
	return_value = printf("\"%0#*x\"", width, x);
	printf("\nreturn_value = %d\n", return_value);
	printf("%%0#-*x for width = %d, and x = %d\n", width, x);
	return_value = printf("\"%0#-*x\"", width, x);
	printf("\nreturn_value = %d\n", return_value);
	prec = 15;
	printf("%%#*.*x for width = %d, prec = %d and x = %d\n", width, prec, x);
	return_value = printf("\"%#*.*x\"", width, prec, x);
	printf("\nreturn_value = %d\n", return_value);
	x = -1;
	width = 10;
	printf("%%0#*x for width = %d, and x = %d\n", width, x);
	return_value = printf("\"%0#*x\"", width, x);
	printf("\nreturn_value = %d\n", return_value);

	x = 42;
	printf("%%#*x for width = %d, and x = %d\n", width, x);
	return_value = printf("\"%#*x\"", width, x);
	printf("\nreturn_value = %d\n", return_value);

	printf("%%#0*x for width = %d, and x = %d\n", width, x);
	return_value = printf("\"%#0*x\"", width, x);
	printf("\nreturn_value = %d\n", return_value);
	
	prec = 8;
	printf("%%#*x for width = %d, prec = %d and x = %d\n", width, prec, x);
	return_value = printf("\"%#*.*x\"", width, prec, x);
	printf("\nreturn_value = %d\n", return_value);	
	
	puts("*****************************************\n");
	puts("----------TESTS FOR %p CONVERSIONS---------\n");
	puts("*****************************************\n");

	printf("%%*.*p for width = %d, prec = %d and x = %p\n", width, prec, &x);
	return_value = printf("\"%*.*p\"", width, prec, &x);
	printf("\nreturn_value = %d\n", return_value);
	printf("%%#*.*p for width = %d, prec = %d and x = %p\n", width, prec, &x);
	return_value = printf("\"%#*.*p\"", width, prec, &x);
	printf("\nreturn_value = %d\n", return_value);
	printf("%%0*.*p for width = %d, prec = %d and x = %p\n", width, prec, &x);
	return_value = printf("\"%0*.*p\"", width, prec, &x);
	printf("\nreturn_value = %d\n", return_value);
	printf("%%0*p for width = %d, and x = %p\n", width, &x);
	return_value = printf("\"%0*p\"", width, &x);
	printf("\nreturn_value = %d\n", return_value);
	printf("%% #*p for width = %d, and x = %p\n", width, &x);
	return_value = printf("\"% #*p\"", width, &x);
	printf("\nreturn_value = %d\n", return_value);
	printf("%%0#-*p for width = %d, and x = %p\n", width, &x);
	return_value = printf("\"%0#-*p\"", width, &x);
	printf("\nreturn_value = %d\n", return_value);
	prec = 15;
	printf("%%#*.*p for width = %d, prec = %d and x = %p\n", width, prec, &x);
	return_value = printf("\"%#*.*p\"", width, prec, &x);
	printf("\nreturn_value = %d\n", return_value);
	x = -1;
	width = 18;
	printf("%%0#*p for width = %d, and x = %p\n", width, &x);
	return_value = printf("\"%0#*p\"", width, &x);
	printf("\nreturn_value = %d\n", return_value);

	x = 42;
	printf("%%#*p for width = %d, and x = %p\n", width, &x);
	return_value = printf("\"%#*p\"", width, &x);
	printf("\nreturn_value = %d\n", return_value);

	printf("%%0*p for width = %d, and x = %p\n", width, &x);
	return_value = printf("\"%0*p\"", width, &x);
	printf("\nreturn_value = %d\n", return_value);
	
	prec = 8;
	printf("%%#*p for width = %d, prec = %d and x = %p\n", width, prec, &x);
	return_value = printf("\"%#*.*p\"", width, prec, &x);
	printf("\nreturn_value = %d\n", return_value);
}