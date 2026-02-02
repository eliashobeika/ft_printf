/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_processing_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliashobeika <eliashobeika@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 21:03:54 by eliashobeik       #+#    #+#             */
/*   Updated: 2025/12/29 23:17:42 by eliashobeik      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_process_char(int arg)
{
	return (write(1, &arg, 1));
}

int	ft_process_int(int arg)
{
	char	*str;
	int		temp;

	str = ft_itoa(arg);
	if (str == NULL)
		return (-1);
	temp = write(1, str, ft_strlen(str));
	free(str);
	return (temp);
}

int	ft_process_str(char *arg)
{
	if (arg == NULL)
		return (write(1, "(null)", 6));
	return (write(1, arg, ft_strlen(arg)));
}

int	ft_process_base(unsigned long nb, char *base, unsigned long base_len)
{
	int	res;
	int	temp;

	res = 0;
	if (nb >= base_len)
	{
		res = ft_process_base(nb / base_len, base, base_len);
		if (res == -1)
			return (-1);
	}
	temp = write(1, &base[nb % base_len], 1);
	if (temp == -1)
		return (-1);
	return (res + temp);
}

int	ft_process_ptr(void *arg)
{
	unsigned long	nb;
	int				temp;

	if (arg == NULL)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	nb = (unsigned long)arg;
	temp = write(1, "0x", 2);
	if (temp == -1)
		return (-1);
	temp = ft_process_base(nb, "0123456789abcdef", 16);
	if (temp == -1)
		return (-1);
	return (temp + 2);
}
