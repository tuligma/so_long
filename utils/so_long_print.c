/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 03:14:55 by npentini          #+#    #+#             */
/*   Updated: 2024/07/26 19:25:36 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	print_struct(t_sl_err *error)
{
	int	x;

	x = 1;
	ft_printf("member%d:\n%s\n\n", x++, error->map_str);
	ft_printf("member%d:\n", x++);
	while (*error->map != NULL)
		ft_printf("%s\n", *error->map++);
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

void	print_map_array(char **map_array)
{
	int	x;

	x = -1;
	while (map_array[++x] != NULL)
		ft_printf("%s\n", map_array[x]);
}

