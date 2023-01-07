/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahajji <ahajji@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 18:27:12 by ahajji            #+#    #+#             */
/*   Updated: 2022/10/23 17:59:49 by ahajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check(const char *s, int *i, va_list ptr)
{
	int	count;

	count = 0;
	if (*(s + 1) == 's')
		count = ft_putstr(va_arg(ptr, char *));
	else if (*(s + 1) == '%')
		count = ft_putchar(*(s));
	else if (*(s + 1) == 'c')
		count = ft_putchar(va_arg(ptr, int));
	else if (*(s + 1) == 'd' || *(s + 1) == 'i')
		count = ft_putnbr(va_arg(ptr, int));
	else if (*(s + 1) == 'x')
		count = ft_putnbr_base(va_arg(ptr, unsigned int), 'x');
	else if (*(s + 1) == 'X')
		count = ft_putnbr_base(va_arg(ptr, unsigned int), 'X');
	else if (*(s + 1) == 'u')
		count = ft_putnbr_uns(va_arg(ptr, unsigned int));
	else if (*(s + 1) == 'p')
		count = ft_putadres(va_arg(ptr, unsigned long int));
	if (*(s + 1) == 's' || *(s + 1) == '%' || *(s + 1) == 'c' || *(s + 1) == 'u'
		|| *(s + 1) == 'd' || *(s + 1) == 'i' || *(s + 1) == 'x' || *(s
			+ 1) == 'X' || *(s + 1) == 'p')
		*i = *i + 1;
	return (count);
}

int	ft_printf(const char *s, ...)
{
	int		i;
	int		count;
	va_list	ptr;

	i = 0;
	count = 0;
	va_start(ptr, s);
	while (s[i])
	{
		if (s[i] == '%')
			count += check(&s[i], &i, ptr);
		else
		{
			ft_putchar(s[i]);
			count++;
		}
		i++;
	}
	return (count);
}

// int main()
// {
// 	//char s[100] = "hello";
// 	char o = 'i';
// 	int i = -1;
// 	//printf("%d", t);
// 	//printf("\n");
// 	//ft_printf("%x",pp);
// 	//ft_printf("%p",&o);
// 	//printf("\n%d\n", ft_printf("%p",NULL));
// 	//printf("\n");
// 	//printf("%p",NULL);
// 	printf(" %x ", -1);
// 	printf("\n");
// 	printf("\n%d",ft_printf("%x", -1));
// }
