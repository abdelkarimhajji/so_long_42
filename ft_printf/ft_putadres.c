/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putadres.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahajji <ahajji@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 12:46:18 by ahajji            #+#    #+#             */
/*   Updated: 2022/10/23 15:38:26 by ahajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	count(unsigned long int n)
{
	int	i;

	i = 0;
	if (n == 0)
		i++;
	while (n > 0)
	{
		n /= 16;
		i++;
	}
	return (i);
}

static char	hexadecimal(unsigned long int modilo)
{
	char				*p;
	unsigned long int	i;
	char				c;

	i = 0;
	p = "0123456789abcdef";
	while (p[i])
	{
		if (i == modilo)
			c = p[i];
		i++;
	}
	return (c);
}

static void	storage_str(unsigned long int nb, char *p, int cou)
{
	unsigned long int	modilo;

	p[cou--] = '\0';
	while (nb > 0)
	{
		modilo = nb % 16;
		if (modilo < 10)
			p[cou] = modilo + 48;
		else
			p[cou] = hexadecimal(modilo);
		nb /= 16;
		cou--;
	}
}

int	ft_putadres(unsigned long int nb)
{
	char	*p;
	int		cou;

	if (!nb)
	{
		write(1, "0x0", 3);
		return (3);
	}
	cou = count(nb);
	p = malloc((cou + 1) * sizeof(char));
	if (!p)
		return (0);
	storage_str(nb, p, cou);
	write(1, "0x", 2);
	ft_putstr(p);
	free(p);
	return (count(nb) + 2);
}
// int main()
// {
//     int n;

//     n = 1115;
//     printf("%d",ft_putnbr_base(1115));
// 	printf("\n");
// 	printf("%x", n);
// }
