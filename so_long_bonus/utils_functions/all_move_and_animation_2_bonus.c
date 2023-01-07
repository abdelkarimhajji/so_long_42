/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_move_and_animation_2.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahajji <ahajji@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 20:17:48 by ahajji            #+#    #+#             */
/*   Updated: 2022/12/19 20:17:49 by ahajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	move_enemy_help_1(t_data *data, int c, int t)
{
	if (data->m_p.ptr[c][t + 1] == 'P')
	{
		data->check = 2;
		data->data_2.check_lose = 1;
	}
	data->m_p.ptr[c][t] = '0';
	data->m_p.ptr[c][t + 1] = 'M';
}

void	move_enemy_help_2(t_data *data, int c, int t)
{
	if (data->m_p.ptr[c][t - 1] == 'P')
	{
		data->check = 2;
		data->data_2.check_lose = 1;
	}
	data->m_p.ptr[c][t] = '0';
	data->m_p.ptr[c][t - 1] = 'M';
}
