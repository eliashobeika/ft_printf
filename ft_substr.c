/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehobeika <ehobeika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 16:46:13 by ehobeika          #+#    #+#             */
/*   Updated: 2025/11/26 16:46:15 by ehobeika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*result;
	size_t		sub_length;

	if (ft_strlen(s) < start)
	{
		result = malloc(1 * sizeof(char));
		if (result == NULL)
			return (NULL);
		result[0] = '\0';
		return (result);
	}
	sub_length = ft_strlen(s + start);
	if (sub_length > len)
		sub_length = len;
	result = malloc(sub_length + 1);
	if (!result)
		return (NULL);
	ft_strlcpy(result, s + start, sub_length + 1);
	return (result);
}
