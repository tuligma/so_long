/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_render_punch2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 23:11:59 by npentini          #+#    #+#             */
/*   Updated: 2024/07/26 20:51:43 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	wall_up_punch(t_sl_hub *data, int y, int x)
{
	char	**map;
	void	*img;

	map = data->map;
	while (map[y][++x] != '\0')
	{
		if (x == 0)
			img = data->tiles->img_wul;
		else if (x == data->map_x - 1)
			img = data->tiles->img_wur;
		else
			img = data->tiles->img_wu;
		mlx_put_image_to_window(data->mlx->mlx, data->mlx->win, img,
			x * data->xpm_w, y * data->xpm_h);
	}
}

void	set_string_on_screen(t_sl_hub *data)
{
	mlx_string_put(data->mlx->mlx, data->mlx->win,
		(data->xpm_w / 2) - 7,
		((data->map_y - 1) * data->xpm_h) + 16, 0xBFD9C6, "move:");
	mlx_string_put(data->mlx->mlx, data->mlx->win,
		data->xpm_w / 2,
		((data->map_y - 1) * data->xpm_h) + 32, 0xFF5D73, "0");
	mlx_string_put(data->mlx->mlx, data->mlx->win,
		3 * ((data->xpm_w / 2) - 7),
		((data->map_y - 1) * data->xpm_h) + 16, 0xBFD9C6, "key:");
	mlx_string_put(data->mlx->mlx, data->mlx->win, 3 * (data->xpm_w / 2),
		((data->map_y - 1) * data->xpm_h) + 32, 0x8CBA98, "XX");
}

void	wall_dn_punch(t_sl_hub *data, int y, int x)
{
	char	**map;
	void	*img;

	map = data->map;
	while (map[y][++x] != '\0')
	{
		if (x == 0)
			img = data->tiles->img_wdr;
		else if (x == data->map_x - 1)
			img = data->tiles->img_wdl;
		else
			img = data->tiles->img_wd;
		mlx_put_image_to_window(data->mlx->mlx, data->mlx->win, img,
			x * data->xpm_w, y * data->xpm_h);
		set_string_on_screen(data);
	}
}

void	wall_lr_punch(t_sl_hub *data, int y, int x)
{
	void	*img;
	int		h;
	int		w;

	w = x * data->xpm_w;
	h = y * data->xpm_h;
	img = data->tiles->img_wl;
	mlx_put_image_to_window(data->mlx->mlx, data->mlx->win, img, w, h);
	w = (data->map_x - 1) * data->xpm_w;
	h = y * data->xpm_h;
	img = data->tiles->img_wr;
	mlx_put_image_to_window(data->mlx->mlx, data->mlx->win, img, w, h);
}
