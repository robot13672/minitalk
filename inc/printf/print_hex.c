/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhristi <ikhristi@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 12:39:55 by ikhristi          #+#    #+#             */
/*   Updated: 2023/01/16 12:39:55 by ikhristi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	hex_convert(int j, const char *hex, unsigned int dec)
{
	char	hex_string[100];
	char	tmp;
	int		i;

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
		j++;
		i--;
	}
	j = 0;
	while (hex_string[j])
		write(1, &hex_string[j++], 1);
	return (j);
}

static int	hex_upper(unsigned int dec)
{
	char	*hex;
	int		i;

	i = 0;
	hex = "0123456789ABCDEF";
	return (hex_convert(i, hex, dec));
}

static int	hex_lower(unsigned int dec)
{
	char	*hex;
	int		i;

	i = 0;
	hex = "0123456789abcdef";
	return (hex_convert(i, hex, dec));
}

int	print_hex(const char *str, unsigned int arg, int i)
{
	if (arg == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	if (str[i] == 'X')
		return (hex_upper(arg));
	if (str[i] == 'x')
		return (hex_lower(arg));
	return (0);
}
