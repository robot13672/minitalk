/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhristi <ikhristi@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 23:01:02 by ikhristi          #+#    #+#             */
/*   Updated: 2023/01/15 23:01:02 by ikhristi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_length(int n)
{
	int	count;

	count = 0;
	if (n < 9 && n >= 0)
		return (1);
	if (n < 0)
	{
		n *= -1;
		count++;
	}
	while (n != 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

void	write_nbr(int nbr)
{
	nbr += 48;
	write(1, &nbr, 1);
}

void	put_nbr(int nbr)
{
	if (nbr == -2147483648)
	{
		write (1, "-2147483648", 11);
		return ;
	}
	if (nbr < 0)
	{
		nbr *= -1;
		write(1, "-", 1);
	}
	if (nbr >= 10)
	{
		put_nbr(nbr / 10);
		write_nbr(nbr % 10);
	}
	else
		write_nbr(nbr);
}

int	print_nbr(int nbr)
{
	put_nbr(nbr);
	return (get_length(nbr));
}
