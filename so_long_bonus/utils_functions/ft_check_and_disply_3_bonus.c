/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_and_disply_3_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahajji <ahajji@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 09:53:07 by ahajji            #+#    #+#             */
/*   Updated: 2022/12/23 09:53:12 by ahajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	go_right_2(t_data *data)
{
	if (data->m_p.ptr[data->p_l.y][data->p_l.x + 1] == '0')
	{
		data->p_l.count_move += 1;
		data->m_p.ptr[data->p_l.y][data->p_l.x] = '0';
		data->m_p.ptr[data->p_l.y][data->p_l.x + 1] = 'P';
	}
	else if (data->m_p.ptr[data->p_l.y][data->p_l.x + 1] == 'C')
	{
		data->p_l.count_move += 1;
		data->m_p.ptr[data->p_l.y][data->p_l.x] = '0';
		data->m_p.ptr[data->p_l.y][data->p_l.x + 1] = 'P';
		data->just_one_coin += 1;
	}
}

void	go_top_2(t_data *data)
{
	if (data->m_p.ptr[data->p_l.y - 1][data->p_l.x] == '0')
	{
		data->p_l.count_move += 1;
		data->m_p.ptr[data->p_l.y][data->p_l.x] = '0';
		data->m_p.ptr[data->p_l.y - 1][data->p_l.x] = 'P';
	}
	else if (data->m_p.ptr[data->p_l.y - 1][data->p_l.x] == 'C')
	{
		data->p_l.count_move += 1;
		data->m_p.ptr[data->p_l.y][data->p_l.x] = '0';
		data->m_p.ptr[data->p_l.y - 1][data->p_l.x] = 'P';
		data->just_one_coin += 1;
	}
}

void	go_left_2(t_data *data)
{
	if (data->m_p.ptr[data->p_l.y][data->p_l.x - 1] == '0')
	{
		data->p_l.count_move += 1;
		data->m_p.ptr[data->p_l.y][data->p_l.x] = '0';
		data->m_p.ptr[data->p_l.y][data->p_l.x - 1] = 'P';
	}
	else if (data->m_p.ptr[data->p_l.y][data->p_l.x - 1] == 'C')
	{
		data->p_l.count_move += 1;
		data->m_p.ptr[data->p_l.y][data->p_l.x] = '0';
		data->m_p.ptr[data->p_l.y][data->p_l.x - 1] = 'P';
		data->just_one_coin += 1;
	}
}

void	go_down_2(t_data *data)
{
	if (data->m_p.ptr[data->p_l.y + 1][data->p_l.x] == '0')
	{
		data->p_l.count_move += 1;
		data->m_p.ptr[data->p_l.y][data->p_l.x] = '0';
		data->m_p.ptr[data->p_l.y + 1][data->p_l.x] = 'P';
	}
	else if (data->m_p.ptr[data->p_l.y + 1][data->p_l.x] == 'C')
	{
		data->p_l.count_move += 1;
		data->m_p.ptr[data->p_l.y][data->p_l.x] = '0';
		data->m_p.ptr[data->p_l.y + 1][data->p_l.x] = 'P';
		data->just_one_coin += 1;
	}
}
