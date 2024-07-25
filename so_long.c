/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 22:54:44 by npentini          #+#    #+#             */
/*   Updated: 2024/07/26 03:23:20 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

void	punch_pov(t_sl_hub *data, int y, int x, int pov)
{
	void *img;

	if (data->p_x == x && data->p_y == y)
	{
		if (pov == UP)
			img = data->tiles->img_ps_bs;
		else if (pov == DN)
			img = data->tiles->img_ps_fs;
		else if (pov == RT)
			img = data->tiles->img_ps_ls;
		else if (pov == LT)
			img = data->tiles->img_ps_rs;
	}
	else if (data->e_x == x && data->e_y == y)
	{
		if (pov == UP)
			img = data->tiles->img_pe_bs;
		else if (pov == DN)
			img = data->tiles->img_pe_fs;
		else if (pov == RT)
			img = data->tiles->img_pe_rs;
		else if (pov == LT)
			img = data->tiles->img_pe_ls;
	}
	else
	{
		if (pov == UP)
			img = data->tiles->img_p_bs;
		else if (pov == DN)
			img = data->tiles->img_p_fs;
		else if (pov == RT)
			img = data->tiles->img_p_rs;
		else if (pov == LT)
			img = data->tiles->img_p_ls;
	}
	mlx_put_image_to_window(data->mlx->mlx, data->mlx->win, img, x * data->xpm_w, y * data->xpm_h);
}

// void	punch_move(t_sl_hub *data, int y, int x)
// {
	
// }

void punch_curr_tile(t_sl_hub *data)
{
	void *img;
	
	if (data->curr_x == data->p_x && data->curr_y == data->p_y)
		img = data->tiles->img_s;
	else if (data->curr_x == data->e_x && data->curr_y == data->e_y)
		img = data->tiles->img_xo;
	else
		img = data->tiles->img_g;
	mlx_put_image_to_window(data->mlx->mlx, data->mlx->win, img, data->curr_x * data->xpm_w, data->curr_y * data->xpm_h);
}

void punch_next_tile_0(t_sl_hub *data, int pos_y, int pos_x)
{
	void *img;

	if (data->mlx->next_pov == UP)
		img = data->tiles->img_p_bs;
	else if (data->mlx->next_pov == DN)
		img = data->tiles->img_p_fs;
	else if (data->mlx->next_pov == RT)
		img = data->tiles->img_p_rs;
	else if (data->mlx->next_pov == LT)
		img = data->tiles->img_p_ls;
	mlx_put_image_to_window(data->mlx->mlx, data->mlx->win, img, pos_x * data->xpm_w, pos_y * data->xpm_h);
	
}

void punch_next_tile_P(t_sl_hub *data, int pos_y, int pos_x)
{
	void *img;

	if (data->mlx->next_pov == UP)
		img = data->tiles->img_ps_bs;
	else if (data->mlx->next_pov == DN)
		img = data->tiles->img_ps_fs;
	else if (data->mlx->next_pov == RT)
		img = data->tiles->img_ps_rs;
	else if (data->mlx->next_pov == LT)
		img = data->tiles->img_ps_ls;
	mlx_put_image_to_window(data->mlx->mlx, data->mlx->win, img, pos_x * data->xpm_w, pos_y * data->xpm_h);
	
}

void punch_next_tile_E(t_sl_hub *data, int pos_y, int pos_x)
{
	void *img;

	if (data->mlx->next_pov == UP)
		img = data->tiles->img_pe_bs;
	else if (data->mlx->next_pov == DN)
		img = data->tiles->img_pe_fs;
	else if (data->mlx->next_pov == RT)
		img = data->tiles->img_pe_rs;
	else if (data->mlx->next_pov == LT)
		img = data->tiles->img_pe_ls;
	mlx_put_image_to_window(data->mlx->mlx, data->mlx->win, img, pos_x * data->xpm_w, pos_y * data->xpm_h);
	
}

int		move_player(t_sl_hub *data, int y, int x)
{
	char	**map;
	int		pos_y;
	int		pos_x;
	// void	*img;

	pos_y = y + data->curr_y;
	pos_x = x + data->curr_x;
	map = data->map;
	if (map[pos_y][pos_x] == '1')
		return (0);
	else if (map[pos_y][pos_x] == '0' || map[pos_y][pos_x] == 'C' || (map[pos_y][pos_x] == 'E' && data->collect == 0) || map[pos_y][pos_x] == 'P')
	{	
		punch_curr_tile(data);
		data->curr_y = pos_y;
		data->curr_x = pos_x;
		if (map[pos_y][pos_x] == '0')
			punch_next_tile_0(data, pos_y, pos_x);
		else if (map[pos_y][pos_x] == 'P')
			punch_next_tile_P(data, pos_y, pos_x);
		else if (map[pos_y][pos_x] == 'E' && data->collect == 0)
			punch_next_tile_E(data, pos_y, pos_x);
		else if (map[pos_y][pos_x] == 'C')
		{
			data->collect--;
			map[pos_y][pos_x] = '0';
			punch_next_tile_0(data, pos_y, pos_x);
			if (data->collect == 0)
				mlx_put_image_to_window(data->mlx->mlx, data->mlx->win, data->tiles->img_xo, data->e_x * data->xpm_w, data->e_y * data->xpm_h);
		}
	}
	return (0);
}

int	 keycode_verifier(int keycode)
{
	int	key[5];
	int	x;

	key[0] = ESC;
	key[1] = FWD;
	key[2] = BWD;
	key[3] = RGT;
	key[4] = LFT;
	x = -1;
	while (++x < 5)
	{
		if (key[x] == keycode)
			return (x);
	}
	return (-1);
}

int	key_hook(int keycode, t_sl_hub *data)
{
	char	*move;
	int	y;
	int	x;
	
	y = 0;
	x = 0;
	if (keycode == ESC)
	{
		free_data(&data, 0, -1);
		exit(0);
	}
	else if (keycode == FWD)
	{
		y = -1;
		data->mlx->next_pov = UP;
	}
	else if (keycode == BWD)
	{
		y = 1;
		data->mlx->next_pov = DN;
	}
	else if (keycode == RGT)
	{
		x = 1;
		data->mlx->next_pov = RT;
	}
	else if (keycode == LFT)
	{
		x = -1;
		data->mlx->next_pov = LT;
	}
	if (data->mlx->next_pov != data->mlx->prev_pov)
	{
		x = 0;
		y = 0;
		punch_pov(data, data->curr_y, data->curr_x, data->mlx->next_pov);
		data->mlx->prev_pov = data->mlx->next_pov;
	}
	else
		move_player(data, y, x);
	if (keycode_verifier(keycode) != -1)
	{
		move = ft_itoa(++data->movement);
		mlx_put_image_to_window(data->mlx->mlx, data->mlx->win, data->tiles->img_wdr, 0, (data->map_y - 1) * data->xpm_h);
		mlx_string_put(data->mlx->mlx, data->mlx->win,  (data->xpm_w / 2) - 7 , ((data->map_y - 1) * data->xpm_h) + 16, 0xBFD9C6, "move:");
		mlx_string_put(data->mlx->mlx, data->mlx->win,  data->xpm_w / 2 , ((data->map_y - 1) * data->xpm_h) + 32, 0x8CBA98, move);
		free(move);
		// ft_printf("This is your %s%d%s move!\n", BHGR, ++data->movement, CR);
	}
	return (0);
}

int	click_close(t_sl_hub *data)
{
	free_data(&data, 0, -1);
	exit(0);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_sl_hub	*data;
	int			result;
	
	data = init_handler(argc, argv);
	if (data == NULL)
		return (1);
	ft_printf("%d\n", (int)sizeof(t_sl_hub));
	result = map_error_checker(data);
	if (result != 0)
		return (free_data(&data, 0, -1));
	// ft_printf("Success!\n\n");
	// print_map_array(data->map);
	// ft_printf("\n\n");
	result = setup_window(data);
	if (result != 0)
		return (free_data(&data, 0, -1));
	result = setup_image(data);
	if (result != 0)
		return (free_data(&data, 0, -1));
	result = render_layers(data);
	if (result != 0)
		return (free_data(&data, 0, -1));
	mlx_hook(data->mlx->win, 17, 0, click_close, data);
	mlx_key_hook(data->mlx->win, key_hook, data);
	mlx_loop(data->mlx->mlx);
	free_data(&data, 0, -1);
	return (0);
}
