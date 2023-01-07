/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_bonus_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahajji <ahajji@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 10:20:27 by ahajji            #+#    #+#             */
/*   Updated: 2022/12/23 10:20:28 by ahajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	display_all_window_2_2(t_data *data, int keycode, int i, int j)
{
	if (data->m_p.ptr[i][j] == '1')
		mlx_put_image_to_window(data->data_2.mlx, data->w_n.mlx_win,
			data->b_x.new_box, j * 106, i * 106);
	if (data->m_p.ptr[i][j] == 'P')
	{
		print_position(keycode, data, i, j);
		data->p_l.y = i;
		data->p_l.x = j;
	}
	if (data->m_p.ptr[i][j] == 'C')
		mlx_put_image_to_window(data->data_2.mlx, data->w_n.mlx_win,
			data->c_o.new_coin, j * 106, i * 106);
}
