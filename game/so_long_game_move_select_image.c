/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_game_move_select_image.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 15:11:12 by npentini          #+#    #+#             */
/*   Updated: 2024/07/26 18:47:39 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	*select_image_tile_p(t_sl_hub *data)
{
	void	*img;

	if (data->mlx->next_pov == UP)
		img = data->tiles->img_ps_bs;
	else if (data->mlx->next_pov == DN)
		img = data->tiles->img_ps_fs;
	else if (data->mlx->next_pov == RT)
		img = data->tiles->img_ps_ls;
	else if (data->mlx->next_pov == LT)
		img = data->tiles->img_ps_rs;
	return (img);
}

void	*select_image_tile_e(t_sl_hub *data)
{
	void	*img;

	if (data->mlx->next_pov == UP)
		img = data->tiles->img_pe_bs;
	else if (data->mlx->next_pov == DN)
		img = data->tiles->img_pe_fs;
	else if (data->mlx->next_pov == RT)
		img = data->tiles->img_pe_rs;
	else if (data->mlx->next_pov == LT)
		img = data->tiles->img_pe_ls;
	return (img);
}

void	*select_image_tile_0(t_sl_hub *data)
{
	void	*img;

	if (data->mlx->next_pov == UP)
		img = data->tiles->img_p_bs;
	else if (data->mlx->next_pov == DN)
		img = data->tiles->img_p_fs;
	else if (data->mlx->next_pov == RT)
		img = data->tiles->img_p_rs;
	else if (data->mlx->next_pov == LT)
		img = data->tiles->img_p_ls;
	return (img);
}

void	*select_image(t_sl_hub *data, char tile)
{
	void	*img;

	if (tile == '0' || tile == 'C')
		img = select_image_tile_0(data);
	else if (tile == 'P')
		img = select_image_tile_p(data);
	else if (tile == 'E' && data->collect == 0)
		img = select_image_tile_e(data);
	if (tile == 'C')
	{
		data->collect--;
		tile = '0';
		if (data->collect == 0)
			mlx_put_image_to_window(data->mlx->mlx, data->mlx->win,
				data->tiles->img_xo, data->e_x * data->xpm_w,
				data->e_y * data->xpm_h);
	}
	return (img);
}
