/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliashobeika <eliashobeika@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 13:56:23 by ehobeika          #+#    #+#             */
/*   Updated: 2025/12/29 16:34:34 by eliashobeik      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>
#include <stdio.h>

int	ft_process_char(int arg)
{
	return (write(1,&arg,1));
}

int	ft_process_int(int arg)
{
	char	*str;
	int		temp;

	str = ft_itoa(arg);
	if (str == NULL)
		return (-1);
	temp = write(1,str,ft_strlen(str));
	free(str);
	return (temp);
}

int ft_process_str(char *arg)
{
	if (arg == NULL)
		return write(1, "(null)", 6);
	return write(1, arg, ft_strlen(arg));
}

int ft_process_base(unsigned long nb, char *base, unsigned long base_len)
{
    int res = 0;
    int temp;

    if (nb >= base_len)
    {
        res = ft_process_base(nb / base_len, base, base_len);
        if (res == -1)
            return -1;
    }
    temp = write(1, &base[nb % base_len], 1);
    if (temp == -1)
        return -1;
    return res + temp;
}

int	ft_process_ptr(void *arg)
{
	unsigned long	nb;
	int				temp;
	
	if(arg == NULL)
	{
		write(1,"(nil)",5);
		return 5;
	}
	nb = (unsigned long)arg;
	temp = write(1,"0x",2);
	if(temp == -1)
		return -1;
	temp = ft_process_base(nb, "0123456789abcdef", 16);
	if(temp == -1)
		return -1;
	return (temp + 2);
}
int	ft_getdigit(unsigned int num)
{
	if (num < 10)
		return (1);
	return (1 + ft_getdigit(num / 10));
}

void	ft_fill_arr(char *arr, unsigned int n, int i)
{
	arr[i--] = '\0';
	while (n > 0)
	{
		arr[i--] = ft_convert_to_char(n % 10);
		n /= 10;
	}
}
char *ft_utoa(unsigned int n)
{
    int digit_num = ft_getdigit(n);
    char *result = malloc((digit_num + 1) * sizeof(char));
    if (!result)
        return NULL;

    if (n == 0)
    {
        ft_strlcpy(result, "0", 2);
        return result;
    }

    ft_fill_arr(result, n, digit_num);
    return result;
}

int	ft_process_uint(unsigned int arg)
{
	char	*str;
	int		temp;

	str = ft_utoa(arg);
	if (str == NULL)
		return (-1);
	temp = write(1, str, ft_strlen(str));
	free(str);
	return (temp);
}

int	ft_process(va_list args, char identifier, int *i)
{
	int	temp;
	
	*i = *i + 2;
	if(identifier == 'c')
		temp = ft_process_char(va_arg(args, int));
	else if(identifier == 'd' || identifier == 'i')
		temp = ft_process_int(va_arg(args, int));
	else if(identifier == 's')
		temp = ft_process_str(va_arg(args, char *));
	else if(identifier == 'p')
		temp = ft_process_ptr(va_arg(args, void *));
	else if(identifier == 'x')
		temp = ft_process_base(va_arg(args, unsigned int), "0123456789abcdef", 16);
	else if(identifier == 'X')
		temp = ft_process_base(va_arg(args, unsigned int), "0123456789ABCDEF", 16);
	else if(identifier == '%')
		temp = ft_process_char('%');
	else if(identifier == 'u')
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
			temp = write(1,&format[i++],1);
			total_printed += temp;
		}
		if(temp == -1)
			return -1;
	}	
	va_end(args);
	return total_printed;
}

int main(){
	int test;
	int a = 5;
	int *ptr = &a;
	test = ft_printf("hello world %p %s\n", ptr, "gay");
	printf("%p %i", ptr, test);
}
