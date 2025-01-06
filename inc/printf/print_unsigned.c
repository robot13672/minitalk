/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhristi <ikhristi@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 11:14:39 by ikhristi          #+#    #+#             */
/*   Updated: 2023/01/16 11:14:39 by ikhristi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_lenght(unsigned int num)
{
	int	count;

	count = 0;
	if (num == 0)
		return (1);
	while (num != 0)
	{
		num /= 10;
		count++;
	}
	return (count);
}

static void	write_num(int n)
{
	n += 48;
	write(1, &n, 1);
}

static void	put_unsigned(unsigned int n)
{
	if (n >= 10)
	{
		put_unsigned(n / 10);
		write_num(n % 10);
	}
	else
		write_num(n);
}

int	print_unsigned(unsigned int n)
{
	put_unsigned(n);
	return (get_lenght(n));
}
