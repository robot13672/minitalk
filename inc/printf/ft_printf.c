/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikhristi <ikhristi@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 23:01:23 by ikhristi          #+#    #+#             */
/*   Updated: 2023/01/15 23:01:23 by ikhristi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_percent(const char *str, int i, va_list arg)
{
	int	num;

	num = 0;
	if ((str[i] == 'd' || str[i] == 'i'))
		num += print_nbr (va_arg(arg, int));
	if (str[i] == 'c')
		num += print_char(va_arg(arg, int));
	if (str[i] == 's')
		num += print_str(va_arg(arg, char *));
	if (str[i] == '%')
		num += print_char('%');
	if (str[i] == 'u')
		num += print_unsigned(va_arg(arg, unsigned int));
	if (str[i] == 'p')
		num += print_pointer(va_arg(arg, unsigned long long int));
	if (str[i] == 'x' || str[i] == 'X')
		num += print_hex(str, va_arg(arg, unsigned int), i);
	return (num);
}

int	ft_printf(const char *format, ...)
{
	va_list	arg;
	int		i;
	int		count;

	va_start (arg, format);
	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] != '%')
		{
			write(1, &format[i], 1);
			i++;
			count++;
		}
		else
		{
			count += check_percent(format, i + 1, arg);
			i += 2;
		}
	}
	va_end (arg);
	return (count);
}
