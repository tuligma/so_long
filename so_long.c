/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 22:54:44 by npentini          #+#    #+#             */
/*   Updated: 2024/07/26 19:24:01 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

int	main(int argc, char *argv[])
{
	t_sl_hub	*data;
	int			(**f)(t_sl_hub*);
	int			result;
	int			x;

	data = init_handler(argc, argv);
	if (data == NULL)
		return (1);
	f = f_main_init();
	if (f == NULL)
		return (free_data(&data, 0, -1));
	x = -1;
	while (++x < FMAIN_COUNT)
	{
		result = f[x](data);
		if (result != 0)
			return (free(f), free_data(&data, 0, -1));
	}
	free(f);
	mlx_hook(data->mlx->win, 17, 0, click_close, data);
	mlx_key_hook(data->mlx->win, key_hook, data);
	mlx_loop(data->mlx->mlx);
	free_data(&data, 0, -1);
	return (0);
}
