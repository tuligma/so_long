/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 22:54:44 by npentini          #+#    #+#             */
/*   Updated: 2024/07/09 01:12:19 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

int	struct_init(void **struct_ptr, size_t struct_size)
{
	*struct_ptr = ft_calloc(1, struct_size);
	if ((*struct_ptr) == NULL)
		return (ENOMEM);
	ft_memset(*struct_ptr, 0, struct_size);
	return (0);
}

void	print_struct_init(void **struct_ptr, size_t struct_size)
{
	int	*p;
	int	struct_count;
	int	x;

	p = *struct_ptr;
	x = -1;
	struct_count = (int)struct_size / sizeof(int);
	while (++x < struct_count)
		ft_printf("%d:%d\n", x + 1, p[x]);
}

int	map_extaction(t_sl_err *error, char *str, char **map)
{
	char	*line;
	int		fd;

	fd = open(str, O_RDONLY);
	if (fd == -1)
		return (fd);
	line = get_next_line(fd);
	while (line != NULL)
	{
		error->line_count++;
		if (*map != NULL)
			*map = ft_strjoin(*map, line);
		else
		{
			*map = ft_strdup(line);
			error->line_len = ft_strlen(line);
		}
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}

int	error_handler(int argc, char *argv[])
{
	t_sl_err	*error;
	char		*map_str;
	char		**map_array;
	int			result;
	int			x;

	if (argc != 2)
	{	
		ft_putstr_fd("Error\nPlease provide ", STDERR_FILENO);
		if (argc < 2)
			ft_putstr_fd("the map .ber file!\n", STDERR_FILENO);
		else
			ft_putstr_fd("only 1 map .ber file!\n", STDERR_FILENO);
		return (1);
	}
	result = struct_init((void **)&error, sizeof(t_sl_err));
	if (result == ENOMEM)
		return (result);
	// print_struct_init((void **)&error, sizeof(t_sl_err));
	map_str = NULL;
	result = map_extaction(error, argv[1], &map_str);
	if (result != 0)
		return (result);
	map_array = ft_split(map_str, '\n');
	free(map_str);
	x = -1;
	while (map_array[++x] != NULL)
		ft_printf("line%d: %s\n", x + 1, map_array[x]);
	while (map_array[++x] != NULL)
		free(map_array[x]);
	free(map_array);
	free(error);
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
