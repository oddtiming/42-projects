/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iyahoui- <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 10:55:16 by iyahoui-          #+#    #+#             */
/*   Updated: 2021/09/20 10:55:45 by iyahoui-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 

int	get_magnitude(int n)
{
	int	magnitude;

	magnitude = 1;
	if (n >= 0)
	{	
		while (n >= 10)
		{
			magnitude *= 10;
			n /= 10;
		}
	}
	else if (n < 0)
	{	
		while (n <= -10)
		{
			magnitude *= 10;
			n /= 10;
		}
	}
	return (magnitude);
}

void	ft_putnbr_fd(int n, int fd)
{
	int		magnitude;
	char	nb;

	magnitude = get_magnitude(n);
	if (n < 0)
	{
		write(fd, "-", sizeof(char));
		if (n == INT_MIN)
		{
			nb = n / magnitude * -1 + '0';
			write(fd, &nb, sizeof(char));
			n = n % magnitude;
			magnitude /= 10;
		}
		n *= -1;
	}
	while (magnitude)
	{
		nb = n / magnitude + '0';
		write(fd, &nb, sizeof(char));
		n = n % magnitude;
		magnitude /= 10;
	}
}
