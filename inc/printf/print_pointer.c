/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhristi <ikhristi@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 11:45:14 by ikhristi          #+#    #+#             */
/*   Updated: 2023/01/16 11:45:14 by ikhristi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	write_pointer(char *hex, int j, unsigned long long int dec)
{
	char	tmp;
	int		i;
	char	hex_string[100];

	i = 0;
	while (dec > 0)
	{
		hex_string[i++] = hex[dec % 16];
		dec /= 16;
	}
	hex_string[i--] = '\0';
	while (i > j)
	{
		tmp = hex_string[i];
		hex_string[i] = hex_string[j];
		hex_string[j] = tmp;
		i--;
		j++;
	}
	j = 0;
	while (hex_string[j])
		write(1, &hex_string[j++], 1);
	return (j);
}

int	print_pointer(unsigned long long int dec)
{
	int		i;
	char	*heximal;

	heximal = "0123456789abcdef";
	i = 0;
	if (dec == 0)
	{
		write(1, "0x0", 3);
		return (3);
	}
	write(1, "0x", 2);
	i = write_pointer(heximal, i, dec);
	return (i + 2);
}
