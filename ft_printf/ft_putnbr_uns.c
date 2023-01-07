/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_uns.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahajji <ahajji@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 23:12:55 by ahajji            #+#    #+#             */
/*   Updated: 2022/10/22 23:41:00 by ahajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	count(unsigned int n)
{
	int	i;

	i = 0;
	if (n <= 0)
		i++;
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

int	ft_putnbr_uns(unsigned int n)
{
	char	c;

	if (n < 10)
	{
		c = n + 48;
		write(1, &c, 1);
	}
	else
	{
		ft_putnbr_uns(n / 10);
		ft_putnbr_uns(n % 10);
	}
	return (count(n));
}
/*#include <stdio.h>
int	main(void)
{
	ft_putnbr_uns("%p", );
}*/
