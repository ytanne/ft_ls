/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddress.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorazaye <yorazaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 13:27:59 by yorazaye          #+#    #+#             */
/*   Updated: 2019/11/01 14:35:55 by yorazaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_numlen_ll(unsigned long long int nb, int base)
{
	int		l;

	if (nb <= 0)
	{
		l = 1;
		nb *= -1;
	}
	else
		l = 0;
	while (nb)
	{
		l++;
		nb /= base;
	}
	return (l);
}

int				ft_putaddress_ll(void *address)
{
	char					*c;
	int						l;
	unsigned long long int	value;

	value = (unsigned long long int)address;
	l = ft_numlen_ll(value, 16);
	c = ft_strnew(l);
	c[l] = '\0';
	while (value && (l >= 0))
	{
		if (value % 16 <= 9)
			c[--l] = value % 16 + '0';
		else
			c[--l] = value % 16 - 10 + 'a';
		value /= 16;
	}
	ft_putstr("0x");
	ft_putstr(c);
	ft_putchar('\n');
	ft_strdel(&c);
	return (l);
}