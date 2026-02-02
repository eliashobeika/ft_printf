/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_processing_utils2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliashobeika <eliashobeika@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 23:17:55 by eliashobeik       #+#    #+#             */
/*   Updated: 2025/12/29 23:19:37 by eliashobeik      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
