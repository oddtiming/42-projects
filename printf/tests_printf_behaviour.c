#include <stdio.h>

int	main()
{
	int	i;

	i = -42;
	puts("*****************************************\n");
	puts("---------TESTS FOR %%CONVERSIONS---------\n");
	puts("*****************************************\n");

	printf("%%d = %d\n", i);
	printf("%%i = %i\n", i);
	printf("%%u = %u\n", i);
	printf("%%x = %x\n", i);
	printf("%%X = %X\n", i);
	printf("%%o = %o\n", i);


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

	puts("\n----------TESTS FOR \"0\" FLAG----------\n");
	printf("%%0d = %0d\n", i);
	printf("%%0i = %0i\n", i);
	printf("%%0u = %0u\n", i);
	printf("%%0x = %0x\n", i);
	printf("%%0X = %0X\n", i);
	printf("%%0o = %0o\n", i);

	puts("\n----------TESTS FOR \".\" FLAG----------\n");
	printf("%%.d = %.d\n", i);
	printf("%%.i = %.i\n", i);
	printf("%%.u = %.u\n", i);
	printf("%%.x = %.x\n", i);
	printf("%%.X = %.X\n", i);
	printf("%%.o = %.o\n", i);

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

	puts("\n----------TESTS FOR \"0\" FLAG----------");
	printf("%%019d = %019d\n", i);
	printf("%%019i = %019i\n", i);
	printf("%%019u = %019u\n", i);
	printf("%%019x = %019x\n", i);
	printf("%%019X = %019X\n", i);
	printf("%%019o = %019o\n", i);
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
	puts("------EXTRA TESTS for extra types------");
	printf("%%.019a = %.019a\n", (double)i);
	printf("%%.019f = %.019f\n", (float)i);
}