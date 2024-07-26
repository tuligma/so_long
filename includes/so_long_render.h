/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_render.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 19:31:31 by npentini          #+#    #+#             */
/*   Updated: 2024/07/26 20:52:06 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_RENDER_H
# define SO_LONG_RENDER_H

# include "so_long.h"

void	tile_to_wall(t_sl_hub *data);
void	punch_ebc(t_sl_hub *data, int y, int x, char c);
void	tile_to_elem(t_sl_hub *data);
void	tile_to_player(t_sl_hub *data);
int		render_layers(t_sl_hub *data);
void	elem_punch(t_sl_hub *data, int y, int x);
void	bground_punch(t_sl_hub *data, int y, int x);
void	collect_punch(t_sl_hub *data, int y, int x);
void	exit_punch(t_sl_hub *data, int y, int x);
void	player_punch(t_sl_hub *data, int y, int x);
void	wall_up_punch(t_sl_hub *data, int y, int x);
void	set_string_on_screen(t_sl_hub *data);
void	wall_dn_punch(t_sl_hub *data, int y, int x);
void	wall_lr_punch(t_sl_hub *data, int y, int x);

#endif