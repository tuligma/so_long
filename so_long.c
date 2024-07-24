/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 22:54:44 by npentini          #+#    #+#             */
/*   Updated: 2024/07/25 01:55:49 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

int	exit_hook(int keycode, t_sl_hub *data)
{
	(void)keycode;
	mlx_destroy_window(data->mlx->mlx, data->mlx->win);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_sl_hub	*data;
	int			result;
	
	data = init_handler(argc, argv);
	if (data == NULL)
		return (1);
	result = map_error_checker(data);
	if (result != 0)
		return (free_data(&data, 0, -1));
	ft_printf("Success!\n\n");
	print_map_array(data->map);
	ft_printf("\n\n");
	result = setup_window(data);
	if (result != 0)
		return (free_data(&data, 0, -1));
	result = setup_image(data);
	if (result != 0)
		return (free_data(&data, 0, -1));
	result = render_layers(data);
	if (result != 0)
		return (free_data(&data, 0, -1));
	// mlx_hook(data->mlx->win, 2, 1L<<0, exit_hook, data);
	// mlx_loop(data->mlx->mlx);
	// mlx_get_screen_size(data->mlx->mlx, &x, &y);
	// ft_printf("\ny: %d\nx: %d\n", y, x);
	free_data(&data, 0, -1);
	return (0);
}
