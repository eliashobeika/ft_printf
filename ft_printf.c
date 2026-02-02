/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliashobeika <eliashobeika@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 13:56:23 by ehobeika          #+#    #+#             */
/*   Updated: 2025/12/29 23:23:46 by eliashobeik      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_process(va_list args, char identifier, int *i)
{
	int	temp;

	*i = *i + 2;
	if (identifier == 'c')
		temp = ft_process_char(va_arg(args, int));
	else if (identifier == 'd' || identifier == 'i')
		temp = ft_process_int(va_arg(args, int));
	else if (identifier == 's')
		temp = ft_process_str(va_arg(args, char *));
	else if (identifier == 'p')
		temp = ft_process_ptr(va_arg(args, void *));
	else if (identifier == 'x')
		temp = ft_process_base(va_arg(args, unsigned int),
				"0123456789abcdef", 16);
	else if (identifier == 'X')
		temp = ft_process_base(va_arg(args, unsigned int),
				"0123456789ABCDEF", 16);
	else if (identifier == '%')
		temp = ft_process_char('%');
	else if (identifier == 'u')
		temp = ft_process_uint(va_arg(args, unsigned int));
	return (temp);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		total_printed;
	int		temp;

	va_start(args, format);
	i = 0;
	total_printed = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			temp = ft_process(args, format[i + 1], &i);
			total_printed += temp;
		}
		else
		{
			temp = write(1, &format[i++], 1);
			total_printed += temp;
		}
		if (temp == -1)
			return (-1);
	}
	va_end(args);
	return (total_printed);
}
