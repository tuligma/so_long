/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_error_func2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 22:26:50 by npentini          #+#    #+#             */
/*   Updated: 2024/07/25 00:28:09 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	error_argument(int argc, char *argv[])
{
	char	*str;
	int		x;
	int		len;
	int		fd;

	x = -1;
	str = argv[1];
	if (argc != 2)
		return (error_print_free(EARGC, EMSG_EARGC));
	if (str != NULL)
	{
		len = ft_strlen(str);
		x = len - 4;
		if (ft_strncmp(str + x, ".ber", 4) != 0)
			return (error_print_free(EARGF, EMSG_EARGF));
		fd = open(str, O_RDONLY);
		if (fd == -1)
		{
			close(fd);
			return (error_print_free(EARGX, EMSG_EARGX));
		}
		close(fd);
	}
	return (0);
}

int	find_path(t_sl_hub *data, int y, int x)
{
	if (y < 1 || y >= data->error->line_count - 1
		|| x < 1 || x >= data->error->line_len - 1)
		return (0);
	if (data->error->map[y][x] == '1'
		|| data->error->map[y][x] == 'V')
		return (0);
	if (data->error->map[y][x] == 'E')
		return (1);
	if (data->error->map[y][x] == '0'
		|| data->error->map[y][x] == 'C')
		data->error->map[y][x] = 'V';
	if (find_path(data, y + 1, x) == 1)
		return (1);
	if (find_path(data, y - 1, x) == 1)
		return (1);
	if (find_path(data, y, x + 1) == 1)
		return (1);
	if (find_path(data, y, x - 1) == 1)
		return (1);
	data->error->map[y][x] = '0';
	return (0);
}

void	find_epc_location_ext(t_sl_hub *data, char **map, int y)
{
	int	x;

	x = -1;
	while (map[y][++x] != '\0')
	{
		if (x == 0 || x == data->error->line_len)
			continue ;
		if (map[y][x] == 'E')
		{
			data->error->exit_y = y;
			data->error->exit_x = x;
		}
		else if (map[y][x] == 'P')
		{
			data->error->player_y = y;
			data->error->player_x = x;
		}
		else if (map[y][x] == 'C')
		{
			data->error->collect_y = y;
			data->error->collect_x = x;
		}
	}
}

void	find_epc_location(t_sl_hub *data)
{
	char	**map;
	int		y;

	map = data->error->map;
	y = -1;
	while (map[++y] != NULL)
	{
		if (y == 0 || y == data->error->line_count - 1)
			continue ;
		find_epc_location_ext(data, map, y);
	}
}

int	is_map_valid_path(t_sl_hub *data)
{
	find_epc_location(data);
	data->error->current_x = data->error->player_x;
	data->error->current_y = data->error->player_y;
	data->error->valid_path = find_path(data,
			data->error->current_y, data->error->current_x);
	if (data->error->valid_path == 0)
		return (error_print_free(EMPNP, EMSG_EMPNP));
	data->e_x = data->error->exit_x;
	data->e_y = data->error->exit_y;
	data->p_x = data->error->player_x;
	data->p_y = data->error->player_y;
	return (0);
}
