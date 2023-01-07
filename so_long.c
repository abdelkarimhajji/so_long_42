/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_next.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahajji <ahajji@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 20:02:52 by ahajji            #+#    #+#             */
/*   Updated: 2022/11/28 20:02:54 by ahajji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	len_line(char *buffer, int *chec)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (buffer[i] != '\0')
	{
		if (buffer[i] != '\n' && *chec == 0)
			j++;
		else
			*chec = 1;
		i++;
	}
	return (j);
}

int	count_of_line(char *buffer)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (buffer[i] != '\0')
	{
		if (buffer[i] == '\n')
			j++;
		i++;
	}
	return (j);
}

t_data	get_wid_hei(t_data data, char *argv)
{
	int			fd;
	int			r;
	int			chec;
	static int	valid;
	char		buffer[2];

	r = 1;
	chec = 0;
	fd = open(argv, O_RDWR);
	while (r)
	{
		r = read(fd, buffer, 1);
		buffer[r] = '\0';
		data.m_p.x += len_line(buffer, &chec);
		data.m_p.y += count_of_line(buffer);
		valid++;
	}
	if (valid > 1)
		data.m_p.y += 1;
	close(fd);
	return (data);
}

int	close_window(void)
{
	exit(1);
}

int	main(int argc, char *argv[])
{
	t_data	data;
	int		i;
	int		fd;

	if (argc != 2)
		return (1);
	initialize_some_struct(&data);
	i = 0;
	check_name_map(argv[1]);
	data = get_wid_hei(data, argv[1]);
	check_length_map(data);
	data.m_p.ptr = (char **)malloc((data.m_p.y + 1) * sizeof(char *));
	fd = open(argv[1], O_RDWR);
	while (i < data.m_p.y)
		data.m_p.ptr[i++] = get_next_line(fd);
	data.m_p.ptr[data.m_p.y] = 0;
	close(fd);
	check_map(&data);
	check_path(&data, argv[1]);
	data = all_img_con(data);
	display_all_window(9, &data);
	mlx_hook(data.w_n.mlx_win, 2, 0, &ft_check_and_display, &data);
	mlx_hook(data.w_n.mlx_win, 17, 0, close_window, NULL);
	mlx_loop(data.data_2.mlx);
	return (0);
}
