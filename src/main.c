/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorazaye <yorazaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 00:16:01 by yorazaye          #+#    #+#             */
/*   Updated: 2019/11/16 02:11:01 by yorazaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int			main(void)
{	
	ft_printf("%Lf\n", 0.999999l);
	printf("%Lf\n", 0.999999l);
	return (0);
}
