/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 03:14:55 by npentini          #+#    #+#             */
/*   Updated: 2024/07/13 19:02:23 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

int	error_printer(int error_code, t_sl_hub *data, char **map, char *map_str)
{	
	if (error_code != 0)
	{
		ft_putstr_fd("Error\n", STDERR_FILENO);
		if (error_code == E2BIG)
			ft_putstr_fd("Please provide the only one map file!", STDERR_FILENO);
		else if (error_code == EINVAL)
			ft_putstr_fd("Please provide a valid map!", STDERR_FILENO);
		else if (error_code == ENOMEM)
			ft_putstr_fd("No Memory available!\n", STDERR_FILENO);
		else if (error_code == ENOENT)
			ft_putstr_fd("Can't open the map!\n", STDERR_FILENO);
		else if (error_code == 1001)
			ft_putstr_fd("Invalid map data!\n", STDERR_FILENO);
		else
			ft_putstr_fd("Unknown error occured!\n", STDERR_FILENO);
		free_malloc(data, map, map_str, -1);
	}
	return (1);
}

void	print_map_array(char **map_array)
{
	int	x;

	x = -1;
	while (map_array[++x] != NULL)
		ft_printf("%s\n", map_array[x]);
}

void	print_map_array_colored(char **map, int line_count, int line_len)
{
	int x;
	int y;
	
	ft_printf("%s", BUHB);
	x = -1;
	while (map[++x] != NULL)
	{
		if (x == 0 || x == line_count - 1)
			ft_printf("%s%s%s\n", BL, map[x], CR);
		else
		{
			y = -1;
			while (map[x][++y] != '\0')
			{
				if (map[x][y] == '1' || y == 0 || y == line_len - 1)
					ft_printf("%s%c%s", BL, map[x][y], CR);
				else if (map[x][y] == '0')
					ft_printf("%s%c%s", WH, map[x][y], CR);
				else if (map[x][y] == 'P')
					ft_printf("%s%c%s", BHBL, map[x][y], CR);
				else if (map[x][y] == 'E')
					ft_printf("%s%c%s", BHRE, map[x][y], CR);
				else if (map[x][y] == 'C')
					ft_printf("%s%c%s", BHYE, map[x][y], CR);
			}
			ft_printf("\n");
		}
	}
	ft_printf("%s\n", CR);
}