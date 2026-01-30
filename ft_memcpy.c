/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehobeika <ehobeika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 12:14:40 by ehobeika          #+#    #+#             */
/*   Updated: 2025/11/25 12:14:43 by ehobeika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*dest_chr;
	unsigned char	*src_chr;
	size_t			i;
	void			*og_dest;

	og_dest = dest;
	dest_chr = (unsigned char *)dest;
	src_chr = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		*dest_chr = *src_chr;
		dest_chr++;
		src_chr++;
		i++;
	}
	return (og_dest);
}
