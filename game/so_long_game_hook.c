/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_game_hook.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 15:18:10 by npentini          #+#    #+#             */
/*   Updated: 2024/07/26 18:48:22 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	keycode_verifier(int keycode)
{
	int	key[4];
	int	value[4];
	int	x;

	if (keycode == ESC)
		return (ESC);
	key[0] = FWD;
	key[1] = BWD;
	key[2] = RGT;
	key[3] = LFT;
	value[0] = UP;
	value[1] = DN;
	value[2] = RT;
	value[3] = LT;
	x = -1;
	while (++x < 4)
	{
		if (key[x] == keycode)
			return (value[x]);
	}
	return (-1);
}

int	click_close(t_sl_hub *data)
{
	free_data(&data, 0, -1);
	exit(0);
	return (0);
}

int	key_hook(int keycode, t_sl_hub *data)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	data->mlx->next_pov = keycode_verifier(keycode);
	if (data->mlx->next_pov == -1)
		return (0);
	else if (data->mlx->next_pov == ESC)
		return (click_close(data));
	else if (data->mlx->next_pov == UP)
		y = -1;
	else if (data->mlx->next_pov == DN)
		y = 1;
	else if (data->mlx->next_pov == RT)
		x = 1;
	else if (data->mlx->next_pov == LT)
		x = -1;
	if (data->mlx->next_pov == data->mlx->prev_pov)
		move_player(data, y, x);
	else
		rotate_player(data, data->curr_y, data->curr_x, data->mlx->next_pov);
	return (print_move(data));
}
