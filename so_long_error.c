/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 22:58:21 by npentini          #+#    #+#             */
/*   Updated: 2024/07/14 23:14:58 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

void	error_func_init(int (**error_function)(t_sl_hub*))
{
	error_function[0] = is_map_empty;
	error_function[1] = is_map_rectangular;
	error_function[2] = is_map_walls;
	error_function[3] = is_map_one_epc;
	error_function[4] = is_map_valid_path;
	error_function[5] = NULL;
}

int	map_error_checker(t_sl_hub *data)
{
	int	(**error_function)(t_sl_hub*);
	int	x;
	int	result;

	error_function = malloc(sizeof(int (*)(t_sl_hub *)) * (ERR_FUNC_COUNT + 1));
	if (error_function == NULL)
		return (ENOMEM);
	error_func_init(error_function);
	x = -1;
	result = 0;
	while (error_function[++x] != NULL)
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

char	*line_extraction(int fd, t_sl_err *error,
	char *map_str, char *(*f)(int))
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

int	map_extraction(t_sl_err *error, char *file)
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
	result = map_extraction(data->error, argv[1]);
	if (result != 0)
		return (error_printer(result, data, NULL, NULL));
	result = map_error_checker(data);
	if (result != 0)
		return (result);
	free_malloc(NULL, data->error->map, data->error->map_str, -1);
	free(data->error);
	free(data);
	return (0);
}
