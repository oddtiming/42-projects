/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmiyakaw <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 10:17:46 by gmiyakaw          #+#    #+#             */
/*   Updated: 2021/07/27 17:09:17 by iyahoui-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char	c)
{
	write(1, &c, 1);
}

int	main(int	argc, char	*argv[])
{
	int	i;
	int	arg_n;

	arg_n = argc - 1;
	while (arg_n > 0)
	{
		i = 0;
		while (argv[arg_n][i] != '\0')
		{
			ft_putchar(argv[arg_n][i]);
			i++;
		}
		ft_putchar('\n');
		arg_n--;
	}
}
