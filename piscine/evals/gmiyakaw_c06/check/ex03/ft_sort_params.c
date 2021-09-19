#include <unistd.h>

int	ft_strcmp(char	*s1, char	*s2)
{
	int i;

	i = 0;
	while (s1[i] && s1[i] == s2[i])
	{
		i++;
	}	
	return ((unsigned int)s1[i] - (unsigned int)s2[i]);
}

int	main(int	argc, char argv[])
{


	ft_strcmp(argv[argc - n])


}



					sort the order first: str_cpm
					compare the value returned from strcmp with the remaining values. If it is the highest, print it, reduce (number of prints) by one. repeat until (number of prints is 0)
	how do i remove the printed string from the pool of strings? 

					how to order using variable sizes?

					print them in order.


//functions:write
//We’re dealing with a programhere, you should therefore have a functionmaininyour.cfile.•
//
//Create a program that displays its given arguments sorted by ascii order.•
//It should display all arguments, except forargv[0].•
//One argument per line.
