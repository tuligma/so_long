/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 03:14:55 by npentini          #+#    #+#             */
/*   Updated: 2024/07/15 14:28:49 by npentini         ###   ########.fr       */
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

int	error_print_free(int error_code, char *error_message)
{
	if (error_code != 0)
	{
		ft_putstr_fd(EMSG, STDERR_FILENO);
		if (error_code == EMPEY || error_code == EMPRT
			|| error_code == EMPWL || error_code == EMPOE
			|| error_code == EMPME || error_code == EMPMP
			|| error_code == EMPEY || error_code == EMPNC
			|| error_code == EMPNP)
			ft_putstr_fd(EMSG_IMP, STDERR_FILENO);
		ft_putstr_fd(error_message, STDERR_FILENO);
	}
	return (1);
}
