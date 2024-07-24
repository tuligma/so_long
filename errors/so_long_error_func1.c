/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_error_func1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 14:04:47 by npentini          #+#    #+#             */
/*   Updated: 2024/07/20 21:36:10 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	is_map_empty(t_sl_hub *data)
{
	char	**map;
	int		y;

	map = data->error->map;
	if (map == NULL)
		return (error_print_free(EMPEY, EMSG_EMPEY));
	y = -1;
	if (data->error->line_count == 0 || data->error->line_len == 0)
		return (error_print_free(EMPEY, EMSG_EMPEY));
	while (++y < data->error->line_count)
	{
		if (map[y] == NULL)
			return (error_print_free(EMPEY, EMSG_EMPEY));
	}
	return (0);
}

int	is_map_rectangular(t_sl_hub *data)
{
	char	**map;
	int		y;
	int		len;

	map = data->error->map;
	y = -1;
	while (map[++y] != NULL)
	{
		len = ft_strlen(map[y]);
		if (len != data->error->line_len)
			return (error_print_free(EMPRT, EMSG_EMPRT));
	}
	return (0);
}

int	is_map_walls(t_sl_hub *data)
{
	char	**map;
	int		y;
	int		x;
	int		line_count;

	map = data->error->map;
	line_count = data->error->line_count;
	y = -1;
	while (map[++y] != NULL)
	{
		x = 0;
		if (y == 0 || y == line_count - 1)
		{
			while (x < data->error->line_len && map[y][x] == '1')
				x++;
			if (x != data->error->line_len)
				return (error_print_free(EMPWL, EMSG_EMPWL));
		}
		else
			if (map[y][x] != '1' && map[y][data->error->line_len - 1] != '1')
				return (error_print_free(EMPWL, EMSG_EMPWL));
	}
	return (0);
}

int	find_epc(t_sl_hub *data, char **map, int y, int len)
{
	int	x;

	x = -1;
	while (++x < len - 1)
	{
		if (ft_strchr("10EPC", map[y][x]) == NULL)
			return (EMPOE);
		if (map[y][x] == 'E')
			data->error->exit++;
		else if (map[y][x] == 'P')
			data->error->player++;
		else if (map[y][x] == 'C')
			data->error->collectible++;
	}
	return (0);
}

int	is_map_one_epc(t_sl_hub *data)
{
	char	**map;
	int		y;
	int		result;
	int		line_count;

	map = data->error->map;
	line_count = data->error->line_count;
	y = -1;
	while (map[++y] != NULL)
	{
		if (y == 0 || y == line_count - 1)
			continue ;
		result = find_epc(data, map, y, data->error->line_len);
		if (result != 0)
			return (error_print_free(EMPOE, EMSG_EMPOE));
	}
	if (data->error->exit != 1)
		return (error_print_free(EMPME, EMSG_EMPME));
	if (data->error->player != 1)
		return (error_print_free(EMPMP, EMSG_EMPMP));
	if (data->error->collectible == 0)
		return (error_print_free(EMPNC, EMSG_EMPNC));
	return (0);
}
