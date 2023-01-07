/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahajji <ahajji@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 18:53:05 by ahajji            #+#    #+#             */
/*   Updated: 2022/10/23 15:42:23 by ahajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	count(unsigned int n)
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

static char	uppercase(unsigned int modilo)
{
	char			*p;
	unsigned int	i;
	char			c;

	i = 0;
	p = "0123456789ABCDEF";
	while (p[i])
	{
		if (i == modilo)
			c = p[i];
		i++;
	}
	return (c);
}

static char	hexadecimal(unsigned int modilo, char car)
{
	char			*p;
	unsigned int	i;
	char			c;

	i = 0;
	if (car == 'x')
	{
		p = "0123456789abcdef";
		while (p[i])
		{
			if (i == modilo)
				c = p[i];
			i++;
		}
	}
	else
		c = uppercase(modilo);
	return (c);
}

static void	storage_string(char *p, int cou, unsigned int nb, char car)
{
	int	modilo;

	p[cou--] = '\0';
	while (nb > 0)
	{
		modilo = nb % 16;
		if (modilo < 10)
			p[cou] = modilo + 48;
		else
			p[cou] = hexadecimal(modilo, car);
		nb /= 16;
		cou--;
	}
}

int	ft_putnbr_base(unsigned int nb, char car)
{
	char	*p;
	int		cou;

	if (!nb)
	{
		write(1, "0", 1);
		return (1);
	}
	cou = count(nb);
	p = malloc((cou + 1) * sizeof(char));
	if (!p)
		return (0);
	storage_string(p, cou, nb, car);
	ft_putstr(p);
	free(p);
	return (count(nb));
}
// int main()
//   {
//   int n;

//   //n = 1115;
//   //printf("%d",ft_putnbr_base(1115));

//   printf("%x", 0);
//   printf("\n");
//   ft_putnbr_base(0, 'x');
//   }
