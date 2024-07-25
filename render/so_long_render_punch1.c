/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_render_punch1.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 22:55:04 by npentini          #+#    #+#             */
/*   Updated: 2024/07/26 03:18:24 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	elem_punch(t_sl_hub *data, int y, int x)
{
	void	*img;

	if (y == data->map_y / 2)
		img = data->tiles->img_elrm;
	else
		img = data->tiles->img_el;
	mlx_put_image_to_window(data->mlx->mlx, data->mlx->win, img,
		x * data->xpm_w, y * data->xpm_h);
}

void	bground_punch(t_sl_hub *data, int y, int x)
{
	void	*img;

	img = data->tiles->img_g;
	mlx_put_image_to_window(data->mlx->mlx, data->mlx->win, img,
		x * data->xpm_w, y * data->xpm_h);
}

void	collect_punch(t_sl_hub *data, int y, int x)
{
	void	*img;

	img = data->tiles->img_c;
	mlx_put_image_to_window(data->mlx->mlx, data->mlx->win, img,
		x * data->xpm_w, y * data->xpm_h);
}

void	exit_punch(t_sl_hub *data, int y, int x)
{
	void	*img;

	img = data->tiles->img_xc;
	mlx_put_image_to_window(data->mlx->mlx, data->mlx->win, img,
		x * data->xpm_w, y * data->xpm_h);
}

void	player_punch(t_sl_hub *data, int y, int x)
{
	void	*img;

	if (data->p_y <= data->map_y / 2)
	{
		img = data->tiles->img_ps_fs;
		data->mlx->prev_pov = DN;
	}
	else
	{
		img = data->tiles->img_ps_bs;
		data->mlx->prev_pov = UP;
	}
	mlx_put_image_to_window(data->mlx->mlx, data->mlx->win, img,
		x * data->xpm_w, y * data->xpm_h);
}
