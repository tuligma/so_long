/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_error_func2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 22:26:50 by npentini          #+#    #+#             */
/*   Updated: 2024/07/14 23:18:49 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

int	error_argument(int argc, char *argv[])
{
	if (argc != 2)
		return (error_printer(E2BIG, NULL, NULL, NULL));
	if (argv[1] == NULL)
		return (error_printer(EINVAL, NULL, NULL, NULL));
	return (0);
}

int	find_path(t_sl_hub *data, int x, int y)
{
	int	temp_x;
	int	temp_y;

	if (x < 1 || x >= data->error->line_count - 1
		|| y < 1 || y >= data->error->line_len - 1)
		return (0);
	if (data->error->map_path[x][y] == '1'
		|| data->error->map_path[x][y] == 'V')
		return (0);
	if (data->error->map_path[x][y] == 'E')
		return (1);
	if (data->error->map_path[x][y] == '0')
		data->error->map_path[x][y] = 'V';
	temp_x = x;
	temp_y = y;
	if (find_path(data, temp_x + 1, temp_y) == 1)
		return (1);
	if (find_path(data, temp_x - 1, temp_y) == 1)
		return (1);
	if (find_path(data, temp_x, temp_y + 1) == 1)
		return (1);
	if (find_path(data, temp_x, temp_y - 1) == 1)
		return (1);
	data->error->map_path[x][y] = '0';
	return (0);
}

void	find_epc_location_ext(t_sl_hub *data, char **map, int x)
{
	int	y;

	y = -1;
	while (map[x][++y] != '\0')
	{
		if (y == 0 || y == data->error->line_len)
			continue ;
		if (map[x][y] == 'E')
		{
			data->error->exit_x = x;
			data->error->exit_y = y;
		}
		else if (map[x][y] == 'P')
		{
			data->error->player_x = x;
			data->error->player_y = y;
		}
		else if (map[x][y] == 'C')
		{
			data->error->collect_x = x;
			data->error->collect_y = y;
		}
	}
}

void	find_epc_location(t_sl_hub *data)
{
	char	**map;
	int		x;

	map = data->error->map;
	x = -1;
	while (map[++x] != NULL)
	{
		if (x == 0 || x == data->error->line_count - 1)
			continue ;
		find_epc_location_ext(data, map, x);
	}
}

int	is_map_valid_path(t_sl_hub *data)
{
	char	**map_path;

	map_path = ft_split(data->error->map_str, '\n');
	if (map_path == NULL)
		return (error_printer(ENOMEM, data,
				data->error->map, data->error->map_str));
	data->error->map_path = map_path;
	find_epc_location(data);
	data->error->current_x = data->error->player_x;
	data->error->current_y = data->error->player_y;
	data->error->valid_path = find_path(data,
			data->error->current_x, data->error->current_y);
	if (data->error->valid_path == 0)
		return (error_printer(1001, data,
				data->error->map, data->error->map_str));
	ft_printf("%d\n", data->error->valid_path);
	free_malloc(NULL, data->error->map_path, NULL, -1);
	return (0);
}
