/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahajji <ahajji@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 12:24:19 by ahajji            #+#    #+#             */
/*   Updated: 2022/12/22 12:24:21 by ahajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_name_map(char *argv)
{
	int			i;
	int			j;
	int			tmp;
	char		*ptr;
	static int	valid;

	ptr = ".ber";
	i = -1;
	while (argv[++i])
	{
		j = 0;
		tmp = i;
		while (argv[tmp] == ptr[j] && ptr[j])
		{
			tmp++;
			j++;
		}
		if (ptr[j] == '\0')
			valid = 1;
	}
	if (valid == 0)
	{
		ft_printf("Name map invalid !!!\n");
		exit(1);
	}
}

void	initialize_some_struct(t_data *data)
{
	data->just_one_coin = 0;
	data->data_2.sum_coin = 0;
	data->check = 0;
	data->m_p.y = 0;
	data->m_p.x = 0;
}

void	check_length_map(t_data data)
{
	if (data.m_p.y > 13 || data.m_p.x > 24)
	{
		ft_printf("length your map invalid !!!\n");
		exit(1);
	}
}

void	check_esp(int keycode)
{
	if (keycode == 53)
		exit(0);
}

void	eroor_map(void)
{
	ft_printf("you have error in your map");
	exit(1);
}
