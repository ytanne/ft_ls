/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putdouble_l.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorazaye <yorazaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 17:19:37 by yorazaye          #+#    #+#             */
/*   Updated: 2019/11/16 01:49:57 by yorazaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static long double	ft_roundup(long double n, int afterpoint)
{
	long double	pwr;
	long double	numbs;
	long double tmp;

	tmp = n;
	pwr = ft_pow_ui(afterpoint);
	while (afterpoint--)
	{
		tmp *= 10.0;
		tmp = tmp - (long double)((int)tmp);
	}
	if (tmp > 0.5)
		n = n + 1.0 / pwr;
	return (n);
}

static void			deal_afterpoint(int ap, long double *rr)
{
	int			first;
	long double diff;

	ft_putchar('.');
	diff = (rr[1] - rr[0]) / 10;
	while (ap--)
	{
		rr[0] *= 10.0;
        diff *= 10.0;
        first = (int)(rr[0] + diff);
		rr[0] -= (long double)first;
		ft_putnbr(first);
	}
}

int					ft_putd_l(long double n, int ap, t_print *t, char sp)
{
	int			temp;
	int			first;
	long double	remainder[2];

	temp = ap;
	if (n >= 0 && t->f_p == 1 && sp == ' ')
		ft_putchar('+');
	if (n < 0 && (n *= -1) && sp == ' ')
		ft_putchar('-');
	first = (int)n;
	if ((remainder[0] = n - (long double)first) < 0)
		remainder[0] *= -1;
	remainder[1] = ft_roundup(remainder[0], ap);
	first += (int)remainder[0];
	remainder[0] -= ((int)remainder[0] > 0) ? 1.0 : 0.0;
	ft_putnbr(first);
	if (ap == 0 && t->f_h == -1)
		return (ft_numlen(first, 10));
	deal_afterpoint(ap, remainder);
	return (ft_numlen(first, 10) + 1 + temp);
}
