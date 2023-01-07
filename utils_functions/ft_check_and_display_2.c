/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_and_display_2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahajji <ahajji@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 17:45:39 by ahajji            #+#    #+#             */
/*   Updated: 2022/12/10 17:45:40 by ahajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	display_empty_space(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->m_p.ptr[i])
	{
		j = 0;
		while (data->m_p.ptr[i][j] != '\0')
		{
			mlx_put_image_to_window(data->data_2.mlx, data->w_n.mlx_win,
				data->floor.mlx, j * 106, i * 106);
			j++;
		}
		i++;
	}
}

void	ft_check_and_display_2(t_data *data, int keycode, int *k)
{
	if (go_top(data))
		*k = 1;
	display_all_window(keycode, data);
	if (*k == 1)
	{
		mlx_put_image_to_window(data->data_2.mlx, data->w_n.mlx_win,
			data->win.new_door, ((data->m_p.x * 106) - 345) / 2,
			((data->m_p.y * 106) - 220) / 2);
		data->check = 2;
	}
}

void	ft_check_and_display_3_3(t_data *data, int keycode, int *k)
{
	if (go_down(data))
		*k = 1;
	display_all_window(keycode, data);
	if (*k == 1)
	{
		mlx_put_image_to_window(data->data_2.mlx, data->w_n.mlx_win,
			data->win.new_door, ((data->m_p.x * 106) - 345) / 2,
			((data->m_p.y * 106) - 220) / 2);
		data->check = 2;
	}
}

void	ft_check_and_display_3(t_data *data, int keycode)
{
	int	k;

	k = 0;
	if (keycode == 0 && data->check != 2)
	{
		if (go_left(data))
			k = 1;
		display_all_window(keycode, data);
		if (k == 1)
		{
			mlx_put_image_to_window(data->data_2.mlx, data->w_n.mlx_win,
				data->win.new_door, ((data->m_p.x * 106) - 345) / 2,
				((data->m_p.y * 106) - 220) / 2);
			data->check = 2;
		}
		ft_printf("%d\n", data->p_l.count_move);
	}
	else if (keycode == 1 && data->check != 2)
	{
		ft_check_and_display_3_3(data, keycode, &k);
		ft_printf("%d\n", data->p_l.count_move);
	}
}
