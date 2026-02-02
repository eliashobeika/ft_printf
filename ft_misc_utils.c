/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_misc_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliashobeika <eliashobeika@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 21:14:08 by eliashobeik       #+#    #+#             */
/*   Updated: 2025/12/29 23:15:47 by eliashobeik      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_getdigit(unsigned int num)
{
	if (num < 10)
		return (1);
	return (1 + ft_getdigit(num / 10));
}

static char	ft_convert_to_char(int digit)
{
	return ((char)digit + 48);
}

static void	ft_fill_arr(char *arr, unsigned int n, int i)
{
	arr[i--] = '\0';
	while (n > 0)
	{
		arr[i--] = ft_convert_to_char(n % 10);
		n /= 10;
	}
}

char	*ft_utoa(unsigned int n)
{
	int		digit_num;
	char	*result;

	digit_num = ft_getdigit(n);
	result = malloc((digit_num + 1) * sizeof(char));
	if (!result)
		return (NULL);
	if (n == 0)
	{
		ft_strlcpy(result, "0", 2);
		return (result);
	}
	ft_fill_arr(result, n, digit_num);
	return (result);
}
