/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chpark <chpark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 14:34:19 by chpark            #+#    #+#             */
/*   Updated: 2022/03/13 14:42:59 by chpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>

size_t	int_form(int n);
size_t	unsignedint_form(unsigned int n, char *form);
size_t	pointer_form(long long n);
size_t	char_form(int c);
size_t	str_form(char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(const char *str);
size_t	ft_strlcpy(char *dest, const char *src, size_t dstsize);
size_t	ft_strlen(const char *s);
int		ft_putstr(char *s);
int		ft_putchar(char c);
char	*put_hex(unsigned int nbr, char *base);
int		ft_printf(const char *str, ...);
char	*ft_itoa(int n);
char	*ft_uitoa(unsigned long n);
char	*ft_substr(char const *s, unsigned int start, size_t len);
#endif
