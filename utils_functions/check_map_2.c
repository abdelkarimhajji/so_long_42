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

#include "../so_long.h"

void	fast_check_1_1(t_data *data, int i, int j)
{
	int	empty;

	if (data->m_p.ptr[i][j] == 'E' || data->m_p.ptr[i][j] == 'P'
		|| data->m_p.ptr[i][j] == '1' || data->m_p.ptr[i][j] == '0'
		|| data->m_p.ptr[i][j] == 'C')
		empty = 0;
	else
		eroor_map();
}
