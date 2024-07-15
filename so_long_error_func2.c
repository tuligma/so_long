/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_error_func2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 22:26:50 by npentini          #+#    #+#             */
/*   Updated: 2024/07/15 14:25:13 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

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

int	find_path(t_sl_hub *data, int x, int y)
{
	int	temp_x;
	int	temp_y;

	if (x < 1 || x >= data->error->line_count - 1
		|| y < 1 || y >= data->error->line_len - 1)
		return (0);
	if (data->error->map[x][y] == '1'
		|| data->error->map[x][y] == 'V')
		return (0);
	if (data->error->map[x][y] == 'E')
		return (1);
	if (data->error->map[x][y] == '0')
		data->error->map[x][y] = 'V';
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
	data->error->map[x][y] = '0';
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
	find_epc_location(data);
	data->error->current_x = data->error->player_x;
	data->error->current_y = data->error->player_y;
	data->error->valid_path = find_path(data,
			data->error->current_x, data->error->current_y);
	if (data->error->valid_path == 0)
		return (error_print_free(EMPNP, EMSG_EMPNP));
	ft_printf("%d\n", data->error->valid_path);
	return (0);
}
