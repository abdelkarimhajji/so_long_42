/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahajji <ahajji@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 16:30:26 by ahajji            #+#    #+#             */
/*   Updated: 2022/12/06 16:30:35 by ahajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	fast_check_2(int j, int *len_line, int *valid)
{
	if (*valid == 0)
		*len_line = j;
	else if (*valid > 0 && *len_line != j)
		eroor_map();
	*valid = *valid + 1;
}

void	fast_check_1(t_data *data)
{
	int	i;
	int	j;
	int	valid;
	int	valid_2;
	int	valid_3;

	fast_check_1_2(&valid, &valid_2, &valid_3, &i);
	while (data->m_p.ptr[i])
	{
		j = 0;
		while (data->m_p.ptr[i][j] != '\n' && data->m_p.ptr[i][j] != '\0')
		{
			if (data->m_p.ptr[i][j] == 'P')
				valid++;
			if (data->m_p.ptr[i][j] == 'E')
				valid_2++;
			if (data->m_p.ptr[i][j] == 'M')
				valid_3++;
			fast_check_1_1(data, i, j);
			j++;
		}
		i++;
	}
	if (valid != 1 || valid_2 != 1 || valid_3 == 0)
		eroor_map();
}

void	fast_check_3(t_data *data)
{
	int	i;
	int	j;
	int	stock;

	i = 0;
	stock = data->m_p.y - 1;
	while (data->m_p.ptr[i])
	{
		j = 0;
		while (data->m_p.ptr[i][j] != '\n' && data->m_p.ptr[i][j] != '\0')
		{
			if ((data->m_p.ptr[i][j] != '1' && i == 0)
				|| (data->m_p.ptr[i][j] != '1' && i == stock))
				eroor_map();
			if (data->m_p.ptr[i][0] != '1' || data->m_p.ptr[i][data->m_p.x
				- 1] != '1')
				eroor_map();
			j++;
		}
		i++;
	}
}

void	fast_check_4(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->m_p.ptr[i])
	{
		j = 0;
		while (data->m_p.ptr[i][j] != '\n' && data->m_p.ptr[i][j] != '\0')
		{
			if (data->m_p.ptr[i][j] == 'C')
				data->data_2.sum_coin += 1;
			j++;
		}
		i++;
	}
}

void	check_map(t_data *data)
{
	int	i;
	int	j;
	int	valid;
	int	long_line;

	valid = 0;
	i = 0;
	fast_check_1(data);
	while (data->m_p.ptr[i])
	{
		j = 0;
		while (data->m_p.ptr[i][j] != '\n' && data->m_p.ptr[i][j] != '\0')
			j++;
		fast_check_2(j, &long_line, &valid);
		i++;
	}
	if (data->m_p.ptr[i - 1][j] == '\n')
		eroor_map();
	fast_check_3(data);
	fast_check_4(data);
}
