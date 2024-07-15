/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_error_func1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 14:04:47 by npentini          #+#    #+#             */
/*   Updated: 2024/07/15 14:22:56 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

int	is_map_empty(t_sl_hub *data)
{
	char	**map;
	int		x;

	map = data->error->map;
	if (map == NULL)
		return (error_print_free(EMPEY, EMSG_EMPEY));
	x = -1;
	if (data->error->line_count == 0 || data->error->line_len == 0)
		return (error_print_free(EMPEY, EMSG_EMPEY));
	while (++x < data->error->line_count)
	{
		if (map[x] == NULL)
			return (error_print_free(EMPEY, EMSG_EMPEY));
	}
	return (0);
}

int	is_map_rectangular(t_sl_hub *data)
{
	char	**map;
	int		x;
	int		len;

	map = data->error->map;
	x = -1;
	while (map[++x] != NULL)
	{
		len = ft_strlen(map[x]);
		if (len != data->error->line_len)
			return (error_print_free(EMPRT, EMSG_EMPRT));
	}
	return (0);
}

int	is_map_walls(t_sl_hub *data)
{
	char	**map;
	int		x;
	int		y;
	int		line_count;

	map = data->error->map;
	line_count = data->error->line_count;
	x = -1;
	while (map[++x] != NULL)
	{
		y = 0;
		if (x == 0 || x == line_count - 1)
		{
			while (y < data->error->line_len && map[x][y] == '1')
				y++;
			if (y != data->error->line_len)
				return (error_print_free(EMPWL, EMSG_EMPWL));
		}
		else
			if (map[x][y] != '1' && map[x][data->error->line_len - 1] != '1')
				return (error_print_free(EMPWL, EMSG_EMPWL));
	}
	return (0);
}

int	find_epc(t_sl_hub *data, char **map, int x, int len)
{
	int	y;

	y = -1;
	while (++y < len - 1)
	{
		if (ft_strchr("10EPC", map[x][y]) == NULL)
			return (EMPOE);
		if (map[x][y] == 'E')
			data->error->exit++;
		else if (map[x][y] == 'P')
			data->error->player++;
		else if (map[x][y] == 'C')
			data->error->collectible++;
	}
	return (0);
}

int	is_map_one_epc(t_sl_hub *data)
{
	char	**map;
	int		x;
	int		y;
	int		line_count;

	map = data->error->map;
	line_count = data->error->line_count;
	x = -1;
	while (map[++x] != NULL)
	{
		if (x == 0 || x == line_count - 1)
			continue ;
		y = find_epc(data, map, x, data->error->line_len);
		if (y != 0)
			return (error_print_free(EMPOE, EMSG_EMPOE));
	}
	if (data->error->exit != 1)
		return (error_print_free(EMPME, EMSG_EMPME));
	if (data->error->player != 1)
		return (error_print_free(EMPMP, EMSG_EMPMP));
	if (data->error->exit == 0)
		return (error_print_free(EMPNC, EMSG_EMPNC));
	return (0);
}
