/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahajji <ahajji@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 21:54:43 by ahajji            #+#    #+#             */
/*   Updated: 2022/12/13 12:56:19 by ahajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	fast_check_1_1(t_data *data, int i, int j)
{
	int	empty;

	if (data->m_p.ptr[i][j] == 'E' || data->m_p.ptr[i][j] == 'P'
		|| data->m_p.ptr[i][j] == '1' || data->m_p.ptr[i][j] == '0'
		|| data->m_p.ptr[i][j] == 'C' || data->m_p.ptr[i][j] == 'M')
		empty = 0;
	else
		exit(1);
}

void	fast_check_1_2(int *valid, int *valid_2, int *valid_3, int *i)
{
	*valid = 0;
	*valid_2 = 0;
	*valid_3 = 0;
	*i = 0;
}
