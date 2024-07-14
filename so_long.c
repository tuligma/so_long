/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 22:54:44 by npentini          #+#    #+#             */
/*   Updated: 2024/07/14 05:47:04 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

void	print_struct(t_sl_err *error)
{
	int	x;

	x = 1;
	ft_printf("member%d:\n%s\n\n", x++, error->map_str);
	ft_printf("member%d:\n", x++);
	while (*error->map != NULL)
		ft_printf("%s\n", *error->map++);
	ft_printf("member%d:\n", x++);
	while (*error->map_path != NULL)
		ft_printf("%s\n", *error->map_path++);
	ft_printf("member%d:%d\n\n", x++, error->line_count);
	ft_printf("member%d:%d\n", x++, error->line_len);
	ft_printf("member%d:%d\n", x++, error->close_wall);
	ft_printf("member%d:%d\n", x++, error->path);
	ft_printf("member%d:%d\n", x++, error->wall);
	ft_printf("member%d:%d\n", x++, error->collectible);
	ft_printf("member%d:%d\n", x++, error->exit);
	ft_printf("member%d:%d\n", x++, error->player);
	ft_printf("member%d:%d\n", x++, error->valid_path);
}

char	**array_init(int size, int len)
{
	char	**map_path;
	int		x;

	map_path = (char **)malloc(sizeof(char *) * (size + 1));
	if (map_path == NULL)
		return (NULL);
	x = 0;
	while (x < size)
	{
		map_path[x] = (char *)malloc(sizeof(char) * (len + 1));
		if (map_path == NULL)
			return (NULL);
		ft_memset(map_path[x], '0', len);
		map_path[x][len] = '\0';
		x++;
	}
	map_path[size] = NULL;
	return (map_path);
}

void	find_epc_location(t_sl_hub *data)
{
	char	**map;
	int		x;
	int		y;

	map = data->error->map;
	x = -1;
	while (map[++x] != NULL)
	{
		if (x == 0 || x == data->error->line_count - 1)
			continue ;
		y = -1;
		while (map[x][++y] != '\0')
		{
			if (y == 0 || y == data->error->line_len)
				continue;
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
}

int move_xy(t_sl_hub *data, int x, int y)
{
	data->error->current_x = x;
	data->error->current_y = y;
	return (find_path(data));
}

int	find_path(t_sl_hub *data)
{
	int	x;
	int	y;
	int temp_x;
	int	temp_y;

	x = data->error->current_x;
	y = data->error->current_y;

	if (x < 1 || x >= data->error->line_count - 1 || y < 1 || y >= data->error->line_len - 1)
		return (0);
	if (data->error->map_path[x][y] == '1' || data->error->map_path[x][y] == 'V')
		return (0);
	if (data->error->map_path[x][y] == 'E')
		return (1);
	ft_printf("Checking x: %d, y: %d\n", x, y);
	print_map_array(data->error->map_path);
	ft_printf("\n\n");
	if (data->error->map_path[x][y] == '0')
		data->error->map_path[x][y] = 'V';
	temp_x = x;
	temp_y = y;
	if (move_xy(data, temp_x + 1, temp_y) == 1)
		return (1);
	if (move_xy(data, temp_x - 1, temp_y) == 1)
		return (1);
	if (move_xy(data, temp_x, temp_y + 1) == 1)
		return (1);
	if (move_xy(data, temp_x, temp_y - 1) == 1)
		return (1);
	data->error->map_path[x][y] = '0';
	return (0);
}

int	is_map_valid_path(t_sl_hub *data)
{
	char	**map_path;

	map_path = ft_split(data->error->map_str, '\n');
	if (map_path == NULL)
		return (error_printer(ENOMEM, data, data->error->map, data->error->map_str));
	data->error->map_path = map_path;
	find_epc_location(data);
	data->error->current_x = data->error->player_x;
	data->error->current_y = data->error->player_y;
	data->error->valid_path = find_path(data);
	if (data->error->valid_path == 0)
		return (error_printer(1001, data, data->error->map, data->error->map_str));
	ft_printf("%d\n", data->error->valid_path);
	free_malloc(NULL, data->error->map_path, NULL, -1);
	return (0);
}

int	map_error_checker(t_sl_hub *data)
{
	int	(**error_function)(t_sl_hub*);
	int	x;
	int	result;

	error_function = malloc(sizeof(int (*)(t_sl_hub*)) * (ERR_FUNC_COUNT + 1));
	if (error_function == NULL)
		return (ENOMEM);
	error_function[0] = is_map_empty;
	error_function[1] = is_map_rectangular;
	error_function[2] = is_map_walls;
	error_function[3] = is_map_one_epc;
	error_function[4] = is_map_valid_path;
	error_function[5] = NULL;
	x = -1;
	result = 0;
	while(error_function[++x] != NULL)
	{
		result = error_function[x](data);
		if (result != 0)
		{
			free(error_function);
			return (result);
		}	
	}
	free(error_function);
	return (0);
}

int	error_argument(int argc, char *argv[])
{
	if (argc != 2)
		return (error_printer(E2BIG, NULL, NULL, NULL));
	if (argv[1] == NULL)
		return (error_printer(EINVAL, NULL, NULL, NULL));
	return (0);
}

char *line_extraction(int fd, t_sl_err *error, char *map_str, char *(*f)(int))
{
	char	*line;
	char	*temp;
	int		count;

	count = 0;
	line = f(fd);
	while (line != NULL)
	{
		count++;
		if (map_str != NULL)
		{
			temp = ft_strjoin(map_str, line);
			free(map_str);
			map_str = temp;
		}
		else
			map_str = ft_strdup(line);
		free(line);
		line = f(fd);
	}
	error->line_count = count;
	return (map_str);
}

int	map_extaction(t_sl_err *error, char *file)
{
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (ENOENT);
	error->map_str = line_extraction(fd, error, NULL, get_next_line);
	if (error->map_str == NULL || error->line_count == 0)
		return (1001);
	error->map = ft_split(error->map_str, '\n');
	if (error->map == NULL || error->line_count == 0)
		return (1001);
	error->line_len = ft_strlen(error->map[0]);
	return (0);
}

int	error_handler(int argc, char *argv[])
{
	t_sl_hub	*data;
	int			result;

	result = error_argument(argc, argv);
	if (result != 0)
		return (1);
	result = struct_init((void **)&data, sizeof(t_sl_err));
	if (result == ENOMEM)
		return (error_printer(result, NULL, NULL, NULL));
	result = struct_init((void **)&data->error, sizeof(t_sl_err));
	if (result == ENOMEM)
		return (error_printer(result, NULL, NULL, NULL));
	// print_struct_init((void **)&data->error, sizeof(t_sl_err));
	result = map_extaction(data->error, argv[1]);
	if (result != 0)
		return (error_printer(result, data, NULL, NULL));
	// print_struct(data->error);
	print_map_array(data->error->map);
	ft_printf("\n");
	result = map_error_checker(data);
	if (result != 0)
		return (result);
	ft_printf("Success!\n");
	free_malloc(NULL, data->error->map, data->error->map_str, -1);
	free(data->error);
	free(data);
	return (0);
}

int	main(int argc, char *argv[])
{
	int	error;

	error = error_handler(argc, argv);
	if (error != 0)
		return (1);
	return (0);
}
