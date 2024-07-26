/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_game_move.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 15:14:43 by npentini          #+#    #+#             */
/*   Updated: 2024/07/26 20:54:16 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	punch_curr_tile(t_sl_hub *data)
{
	void	*img;

	if (data->curr_x == data->p_x && data->curr_y == data->p_y)
		img = data->tiles->img_s;
	else if (data->curr_x == data->e_x && data->curr_y == data->e_y)
		img = data->tiles->img_xo;
	else
		img = data->tiles->img_g;
	mlx_put_image_to_window(data->mlx->mlx, data->mlx->win,
		img, data->curr_x * data->xpm_w, data->curr_y * data->xpm_h);
}

int	is_valid_char(char tile, int collect)
{
	return (tile == '0' || tile == 'C'
		|| (tile == 'E' && collect == 0) || tile == 'P');
}

int	move_player(t_sl_hub *data, int y, int x)
{
	char	tile;
	int		pos_y;
	int		pos_x;
	void	*img;

	pos_y = y + data->curr_y;
	pos_x = x + data->curr_x;
	tile = data->map[pos_y][pos_x];
	if (tile == '1')
		return (0);
	else if (is_valid_char(tile, data->collect))
	{
		punch_curr_tile(data);
		img = select_image(data, tile);
		mlx_put_image_to_window(data->mlx->mlx, data->mlx->win,
			img, pos_x * data->xpm_w, pos_y * data->xpm_h);
		data->curr_y = pos_y;
		data->curr_x = pos_x;
	}
	return (0);
}

void	put_key_screen(t_sl_hub *data)
{
	char	*key;

	if (data->mlx->next_pov == UP)
		key = "UP";
	else if (data->mlx->next_pov == DN)
		key = "DN";
	else if (data->mlx->next_pov == RT)
		key = "RT";
	else if (data->mlx->next_pov == LT)
		key = "LT";
	mlx_put_image_to_window(data->mlx->mlx, data->mlx->win,
		data->tiles->img_wd, 64, (data->map_y - 1) * data->xpm_h);
	mlx_string_put(data->mlx->mlx, data->mlx->win,
		3 * ((data->xpm_w / 2) - 7),
		((data->map_y - 1) * data->xpm_h) + 16, 0xBFD9C6, "key:");
	mlx_string_put(data->mlx->mlx, data->mlx->win, 3 * (data->xpm_w / 2),
		((data->map_y - 1) * data->xpm_h) + 32, 0x8CBA98, key);
}

int	print_move(t_sl_hub *data)
{
	char	*move;
	char	*key[5];
	int		i;

	move = ft_itoa(++data->movement);
	if (move == NULL)
		return (error_print_free(EMALL, EMSG_EMALL));
	mlx_put_image_to_window(data->mlx->mlx, data->mlx->win,
		data->tiles->img_wdr, 0, (data->map_y - 1) * data->xpm_h);
	mlx_string_put(data->mlx->mlx, data->mlx->win,
		(data->xpm_w / 2) - 7,
		((data->map_y - 1) * data->xpm_h) + 16, 0xBFD9C6, "move:");
	mlx_string_put(data->mlx->mlx, data->mlx->win, data->xpm_w / 2,
		((data->map_y - 1) * data->xpm_h) + 32, 0x8CBA98, move);
	key[0] = "⬆️";
	key[1] = "⬇️";
	key[2] = "➡️";
	key[3] = "⬅️";
	put_key_screen(data);
	i = data->mlx->next_pov;
	ft_printf("move: 🚶 %s%s%s   %s\n", BHGR, move, CR, key[i]);
	free(move);
	return (0);
}
