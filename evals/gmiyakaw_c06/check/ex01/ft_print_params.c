/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmiyakaw <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 10:15:57 by gmiyakaw          #+#    #+#             */
/*   Updated: 2021/07/27 10:17:15 by gmiyakaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char	c)
{
	write(1, &c, 1);
}

int	main(int	argc, char	*argv [])
{
	int	i;
	int	n_arg;

	n_arg = 1;
	while (n_arg != argc)
	{
		i = 0;
		while (argv[n_arg][i] != '\0')
		{
			ft_putchar(argv[n_arg][i]);
			i++;
		}
		ft_putchar('\n');
		n_arg++;
	}
}
