/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliashobeika <eliashobeika@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 12:14:29 by ehobeika          #+#    #+#             */
/*   Updated: 2025/12/29 16:16:56 by eliashobeik      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_getdigit(int num)
{
	if (num == -2147483648)
		return (10);
	if (num < 0)
		return (ft_getdigit(-num));
	if (num < 10)
		return (1);
	return (1 + ft_getdigit(num / 10));
}

static char	ft_convert_to_char(int digit)
{
	return ((char)digit + 48);
}

static void	ft_fill_arr(char *arr, int n, int i)
{
	if (n == -2147483648)
	{
		arr[1] = '2';
		ft_fill_arr(arr, -147483648, i);
	}
	else if (n < 0)
		ft_fill_arr(arr, -n, i);
	else
	{
		arr[i--] = '\0';
		while (n > 0)
		{
			arr[i--] = ft_convert_to_char(n % 10);
			n /= 10;
		}
	}
}

char	*ft_itoa(int n)
{
	int		digit_num;
	char	*result;
	int		i;

	digit_num = ft_getdigit(n);
	if (n >= 0)
	{
		result = malloc((digit_num + 1) * sizeof(char));
		if (n == 0)
		{
			ft_strlcpy(result, "0", 2);
			return (result);
		}
		i = digit_num;
		ft_fill_arr(result, n, i);
	}
	else
	{
		result = malloc((digit_num + 2) * sizeof(char));
		i = digit_num + 1;
		result[0] = '-';
		ft_fill_arr(result, n, i);
	}
	return (result);
}
