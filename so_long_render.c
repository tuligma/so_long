/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_render.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 01:04:35 by npentini          #+#    #+#             */
/*   Updated: 2024/07/25 01:57:15 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

void	tile_to_wall(t_sl_hub *data)
{
	char **map;
	int	y;

	map = data->map;
	y = -1;
	while (map[++y] != NULL)
	{
		if (y == 0)
			wall_up_punch(data, y, -1);
		else if (y == data->map_y - 1)
			wall_dn_punch(data, y, -1);
		else 
			wall_lr_punch(data, y, 0);
	}
}

void	punch_ebc(t_sl_hub *data, int y, int x, char c)
{
	if (c == '1')
		elem_punch(data, y, x);
	else if (c == '0')
		bground_punch(data, y , x);
	else if (c == 'C')
		collect_punch(data, y, x);
}

void	tile_to_elem(t_sl_hub *data)
{
	char	**map;
	int		y;
	int		x;

	map = data->map;
	y = -1;
	while (map[++y] != NULL)
	{
		if (y == 0 || y == data->map_y - 1)
			continue ;
		else
		{
			x = -1;
			while (map[y][++x] != '\0')
			{
				if (x == 0 || x == data->map_x - 1)
					continue;
				punch_ebc(data, y, x, map[y][x]);
			}
		}
	}
}

void	tile_to_player(t_sl_hub *data)
{
	exit_punch(data, data->e_y, data->e_x);
	player_punch(data, data->p_y, data->p_x);
}


int render_layers(t_sl_hub *data)
{
	void	(**punch_func)(t_sl_hub*);
	int	i;

	punch_func = malloc(sizeof(int(**)(t_sl_hub)) * (CTLFUNC_COUNT + 1));
	if (punch_func == NULL)
		return (error_print_free(EMALL, EMSG_EMALL));
	punch_func[0] = tile_to_wall;
	punch_func[1] = tile_to_elem;
	punch_func[2] = tile_to_player;
	punch_func[3] = NULL;
	i = -1;
	while (punch_func[++i] != NULL)
		punch_func[i](data);
	free(punch_func);
	return (0);
}
