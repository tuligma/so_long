/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_game_rotation.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 14:59:53 by npentini          #+#    #+#             */
/*   Updated: 2024/07/26 18:47:44 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	*select_image_rotate_p(t_sl_hub *data, int pov)
{
	void	*img;

	img = NULL;
	if (pov == UP)
		img = data->tiles->img_ps_bs;
	else if (pov == DN)
		img = data->tiles->img_ps_fs;
	else if (pov == RT)
		img = data->tiles->img_ps_ls;
	else if (pov == LT)
		img = data->tiles->img_ps_rs;
	return (img);
}

void	*select_image_rotate_e(t_sl_hub *data, int pov)
{
	void	*img;

	img = NULL;
	if (pov == UP)
		img = data->tiles->img_pe_bs;
	else if (pov == DN)
		img = data->tiles->img_pe_fs;
	else if (pov == RT)
		img = data->tiles->img_pe_rs;
	else if (pov == LT)
		img = data->tiles->img_pe_ls;
	return (img);
}

void	*select_image_rotate_0(t_sl_hub *data, int pov)
{
	void	*img;

	img = NULL;
	if (pov == UP)
		img = data->tiles->img_p_bs;
	else if (pov == DN)
		img = data->tiles->img_p_fs;
	else if (pov == RT)
		img = data->tiles->img_p_rs;
	else if (pov == LT)
		img = data->tiles->img_p_ls;
	return (img);
}

void	rotate_player(t_sl_hub *data, int y, int x, int pov)
{
	void	*img;

	img = NULL;
	if (data->p_x == x && data->p_y == y)
		img = select_image_rotate_p(data, pov);
	else if (data->e_x == x && data->e_y == y)
		img = select_image_rotate_e(data, pov);
	else
		img = select_image_rotate_0(data, pov);
	mlx_put_image_to_window(data->mlx->mlx,
		data->mlx->win, img, x * data->xpm_w, y * data->xpm_h);
	data->mlx->prev_pov = data->mlx->next_pov;
}
