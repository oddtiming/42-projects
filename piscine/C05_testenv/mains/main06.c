#include <stdio.h>
#include <limits.h>
int	ft_is_prime(int nb);

int check_prime(int a)
{
   int c;

   if (a < 2)
	   return (0);
   for ( c = 2 ; c <= a - 1 ; c++ )
   {
      if ( a%c == 0 )
     return 0;
   }
   return 1;
}

int	main(void)
{
	int i;

	i = 0;
	printf("Prime numbers from [0-100]:\n"); 
	while (i < 100)
	{
		if (ft_is_prime(i))
			printf("%d", i);
		if (check_prime(i))
			printf("  |  %d\n", i);
		i++;
	}	
	i = INT_MAX - 30;
	printf("Prime numbers from [INT_MAX - 30, INT_MAX]:\n"); 
	while (i < INT_MAX)
	{
		if (ft_is_prime(i))
			printf("%d", i);
		if (check_prime(i))
			printf("  |  %d\n", i);
		i++;
	}	
	if (ft_is_prime(i))
		printf("%d", i);
	if (check_prime(i))
		printf("  |  %d\n", i);
}
