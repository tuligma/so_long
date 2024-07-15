/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 22:58:21 by npentini          #+#    #+#             */
/*   Updated: 2024/07/15 14:20:48 by npentini         ###   ########.fr       */
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
		return (error_print_free(EMALL, EMSG_EMALL));
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

char	*line_extraction(int fd, t_sl_hub *data,
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
	data->error->line_count = count;
	return (map_str);
}

int	map_extraction(t_sl_hub *data, char *file)
{
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (error_print_free(EFILO, EMSG_EMALL));
	data->error->map_str = line_extraction(fd, data, NULL, get_next_line);
	if (data->error->map_str == NULL || data->error->line_count < 3)
		return (error_print_free(EMPEY, EMSG_EMPEY));
	data->error->map = ft_split(data->error->map_str, '\n');
	if (data->error->map == NULL)
		return (error_print_free(EMALL, EMSG_EMALL));
	data->error->line_len = ft_strlen(data->error->map[0]);
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
	if (result == EMALL)
		return (1);
	result = struct_init((void **)&data->error, sizeof(t_sl_err));
	if (result == EMALL)
		return (free_data(&data, 0, -1));
	result = map_extraction(data, argv[1]);
	if (result != 0)
		return (free_data(&data, 11, -1), free_data(&data, 0, -1));
	ft_printf("Before: MAP\n");
	print_map_array(data->error->map);
	ft_printf("\n\n");
	result = map_error_checker(data);
	if (result != 0)
		return (free_data(&data, 0, -1));
	free_data(&data, 0, -1);
	return (0);
}
