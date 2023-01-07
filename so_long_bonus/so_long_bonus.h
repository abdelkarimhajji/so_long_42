/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahajji <ahajji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 20:04:21 by ahajji            #+#    #+#             */
/*   Updated: 2023/01/07 10:20:17 by ahajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "../ft_printf/ft_printf.h"
# include "./utils_functions/get_next_line_bonus.h"
# include <fcntl.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct player
{
	char		*img_player;
	char		*img_player_2;
	void		*new_player;
	void		*new_player_2;
	int			x;
	int			y;
	int			count_move;
}				t_player;

typedef struct coin
{
	char		*img_coin;
	void		*new_coin;
}				t_coin;

typedef struct window
{
	void		*mlx_win;
	char		*img_bg;
	void		*new_bg;
	int			width_win;
	int			height_win;
}				t_window;

typedef struct box
{
	char		*img_box;
	void		*new_box;
}				t_box;

typedef struct door
{
	char		*img_door;
	void		*new_door;
}				t_door;

typedef struct map
{
	char		**ptr;
	char		**ptr_2;
	int			x;
	int			y;
}				t_map;

typedef struct t_data_2
{
	char		*ptr[6];
	void		*mlx;
	char		*img_floor;
	int			i;
	int			j;
	int			check_win;
	int			check_lose;
	int			sum_coin;
	int			sum_in_map;
}				t_data_2;

typedef struct s_data
{
	t_data_2	data_2;
	t_data_2	l_s;
	t_data_2	floor;
	t_door		win;
	t_window	w_n;
	t_player	p_l;
	t_box		b_x;
	t_map		m_p;
	t_coin		c_o;
	t_door		d_r;
	int			width;
	int			height;
	int			check;
	int			just_one_coin;
}				t_data;

void			display_all_window(int keycode, t_data *data);
int				ft_check_and_display(int keycode, t_data *data);
void			ft_check_and_display_2(t_data *data, int keycode, int *k);
void			ft_check_and_display_3(t_data *data, int keycode);
t_data			all_img_con(t_data data);
void			check_map(t_data *data);
void			check_path(t_data *data, char *argv);
int				go_left(t_data *data);
int				go_down(t_data *data);
int				go_top(t_data *data);
void			check_found_exit_coin_2(t_data *data, int *valid_3);
void			check_coins_2(t_data *data, int *count_coins);
void			fast_check_1_1(t_data *data, int i, int j);
char			*ft_itoa(int n);
void			display_empty_space(t_data *data);
void			move_enemy_help_1(t_data *data, int c, int t);
void			move_enemy_help_2(t_data *data, int c, int t);
int				move(t_data *data);
void			eroor_map(void);
void			initialize_some_struct(t_data *data);
void			check_name_map(char *argv);
void			check_length_map(t_data *data);
void			fast_check_1_2(int *valid, int *valid_2, int *valid_3, int *i);
void			go_right_2(t_data *data);
void			go_top_2(t_data *data);
void			go_left_2(t_data *data);
void			go_down_2(t_data *data);
void			display_all_window_2_2(t_data *data, int keycode, int i, int j);
void			print_position(int keycode, t_data *data, int i, int j);

#endif