/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_img_con.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahajji <ahajji@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 23:05:30 by ahajji            #+#    #+#             */
/*   Updated: 2022/12/05 23:05:34 by ahajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

t_data	all_img_con_2(t_data data)
{
	data.w_n.img_bg = "./so_long_bonus/img/BG.XPM";
	data.p_l.img_player = "./so_long_bonus/img/player.XPM";
	data.p_l.img_player_2 = "./so_long_bonus/img/player_2.XPM";
	data.b_x.img_box = "./so_long_bonus/img/box.XPM";
	data.c_o.img_coin = "./so_long_bonus/img/coin3.XPM";
	data.d_r.img_door = "./so_long_bonus/img/door.XPM";
	data.win.img_door = "./so_long_bonus/img/win.XPM";
	data.floor.img_floor = "./so_long_bonus/img/floor.XPM";
	data.l_s.img_floor = "./so_long_bonus/img/lose.XPM";
	data.data_2.ptr[0] = "./so_long_bonus/img/1.XPM";
	data.data_2.ptr[1] = "./so_long_bonus/img/2.XPM";
	data.data_2.ptr[2] = "./so_long_bonus/img/3.XPM";
	data.data_2.ptr[3] = "./so_long_bonus/img/4.XPM";
	data.data_2.ptr[4] = "./so_long_bonus/img/5.XPM";
	data.data_2.ptr[5] = "./so_long_bonus/img/6.XPM";
	return (data);
}

t_data	all_img_con(t_data data)
{
	data = all_img_con_2(data);
	data.p_l.count_move = 0;
	data.data_2.mlx = mlx_init();
	data.w_n.mlx_win = mlx_new_window(data.data_2.mlx, 106 * data.m_p.x, 106
			* data.m_p.y, "hello word");
	data.w_n.new_bg = mlx_xpm_file_to_image(data.data_2.mlx, data.w_n.img_bg,
			&data.width, &data.height);
	data.p_l.new_player = mlx_xpm_file_to_image(data.data_2.mlx,
			data.p_l.img_player, &data.width, &data.height);
	data.p_l.new_player_2 = mlx_xpm_file_to_image(data.data_2.mlx,
			data.p_l.img_player_2, &data.width, &data.height);
	data.b_x.new_box = mlx_xpm_file_to_image(data.data_2.mlx, data.b_x.img_box,
			&data.width, &data.height);
	data.c_o.new_coin = mlx_xpm_file_to_image(data.data_2.mlx,
			data.c_o.img_coin, &data.width, &data.height);
	data.d_r.new_door = mlx_xpm_file_to_image(data.data_2.mlx,
			data.d_r.img_door, &data.width, &data.height);
	data.win.new_door = mlx_xpm_file_to_image(data.data_2.mlx,
			data.win.img_door, &data.width, &data.height);
	data.floor.mlx = mlx_xpm_file_to_image(data.data_2.mlx,
			data.floor.img_floor, &data.width, &data.height);
	data.l_s.mlx = mlx_xpm_file_to_image(data.data_2.mlx, data.l_s.img_floor,
			&data.width, &data.height);
	display_empty_space(&data);
	return (data);
}
