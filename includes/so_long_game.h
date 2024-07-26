/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_game.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 15:01:01 by npentini          #+#    #+#             */
/*   Updated: 2024/07/26 20:52:42 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_GAME_H
# define SO_LONG_GAME_H

#include "so_long.h"

void	*select_image_rotate_p(t_sl_hub *data, int pov);
void	*select_image_rotate_e(t_sl_hub *data, int pov);
void	*select_image_rotate_0(t_sl_hub *data, int pov);
void	rotate_player(t_sl_hub *data, int y, int x, int pov);
void	*select_image_tile_p(t_sl_hub *data);
void	*select_image_tile_e(t_sl_hub *data);
void	*select_image_tile_0(t_sl_hub *data);
void	*select_image(t_sl_hub *data, char tile);
void	punch_curr_tile(t_sl_hub *data);
int		is_valid_char(char tile, int collect);
int		move_player(t_sl_hub *data, int y, int x);
void	put_key_screen(t_sl_hub *data);
int		print_move(t_sl_hub *data);
int		keycode_verifier(int keycode);
int		click_close(t_sl_hub *data);
int		key_hook(int keycode, t_sl_hub *data);




#endif