/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliashobeika <eliashobeika@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 21:07:37 by eliashobeik       #+#    #+#             */
/*   Updated: 2025/12/29 23:12:42 by eliashobeik      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_printf(char const *str, ...);
int		ft_process_char(int arg);
int		ft_process_int(int arg);
int		ft_process_str(char *arg);
int		ft_process_base(unsigned long nb, char *base, unsigned long base_len);
int		ft_process_ptr(void *arg);
int		ft_process_uint(unsigned int arg);
char	*ft_utoa(unsigned int n);
char	*ft_itoa(int n);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlen(const char *str);

#endif