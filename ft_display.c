/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahajji <ahajji@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 20:28:33 by ahajji            #+#    #+#             */
/*   Updated: 2022/11/30 20:28:35 by ahajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_position(int keycode, t_data *data, int i, int j)
{
	if (keycode == 0)
	{
		mlx_put_image_to_window(data->data_2.mlx, data->w_n.mlx_win,
			data->p_l.new_player_2, j * 106, i * 106);
		data->check = 0;
	}
	else if (keycode == 2)
	{
		mlx_put_image_to_window(data->data_2.mlx, data->w_n.mlx_win,
			data->p_l.new_player, j * 106, i * 106);
		data->check = 1;
	}
	else if (data->check == 1)
		mlx_put_image_to_window(data->data_2.mlx, data->w_n.mlx_win,
			data->p_l.new_player, j * 106, i * 106);
	else if (data->check == 0)
		mlx_put_image_to_window(data->data_2.mlx, data->w_n.mlx_win,
			data->p_l.new_player_2, j * 106, i * 106);
}

void	display_all_window_2(int keycode, t_data *data, int i, int j)
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
	if (data->m_p.ptr[i][j] == 'E')
		mlx_put_image_to_window(data->data_2.mlx, data->w_n.mlx_win,
			data->d_r.new_door, j * 106, i * 106);
}

void	display_all_window(int keycode, t_data *data)
{
	int	i;
	int	j;

	i = 0;
	display_empty_space(data);
	while (data->m_p.ptr[i])
	{
		j = 0;
		while (data->m_p.ptr[i][j] != '\0')
		{
			display_all_window_2(keycode, data, i, j);
			j++;
		}
		i++;
	}
}
