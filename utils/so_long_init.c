/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 19:22:26 by npentini          #+#    #+#             */
/*   Updated: 2024/07/26 19:28:40 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	struct_init(void **struct_ptr, size_t struct_size)
{
	*struct_ptr = ft_calloc(1, struct_size);
	if (*struct_ptr == NULL)
		return (error_print_free(EMALL, EMSG_EMALL));
	return (0);
}

int	(**f_main_init(void))(t_sl_hub *data)
{
	int			(**f)(t_sl_hub*);

	f = malloc(sizeof(int (*)(t_sl_hub *)) * (FMAIN_COUNT + 1));
	if (f == NULL)
		return (error_print_free(EMALL, EMSG_EMALL), NULL);
	f[0] = map_error_checker;
	f[1] = setup_window;
	f[2] = setup_image;
	f[3] = render_layers;
	f[4] = NULL;
	return (f);
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
	data->map_str = line_extraction(fd, data, NULL, get_next_line);
	if (data->map_str == NULL || data->error->line_count < 3)
		return (error_print_free(EMPEY, EMSG_EMPEY));
	data->error->map = ft_split(data->map_str, '\n');
	if (data->error->map == NULL)
		return (error_print_free(EMALL, EMSG_EMALL));
	data->error->line_len = ft_strlen(data->error->map[0]);
	if (data->error->line_len < 5)
		return (error_print_free(EMPEY, EMSG_EMPEY));
	data->map_y = data->error->line_count;
	data->map_x = data->error->line_len;
	data->map = ft_split(data->map_str, '\n');
	if (data->map == NULL)
		return (error_print_free(EMALL, EMSG_EMALL));
	return (0);
}

t_sl_hub	*init_handler(int argc, char *argv[])
{
	t_sl_hub	*data;
	int			result;

	result = error_argument(argc, argv);
	if (result != 0)
		return (NULL);
	result = struct_init((void **)&data, sizeof(t_sl_err));
	if (result == EMALL)
		return (NULL);
	result = struct_init((void **)&data->error, sizeof(t_sl_err));
	if (result == EMALL)
		return (free_data(&data, 0, -1), NULL);
	result = map_extraction(data, argv[1]);
	if (result != 0)
		return (free_data(&data, 11, -1), free_data(&data, 0, -1), NULL);
	return (data);
}
