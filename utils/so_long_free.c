/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 13:05:36 by npentini          #+#    #+#             */
/*   Updated: 2024/07/26 19:03:52 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_data_12(t_sl_hub **data, int x)
{
	free_data(data, 11, x);
	free_array(&(*data)->error->map, (*data)->error->line_count, x);
}

void	free_data_1(t_sl_hub **data, int x)
{
	free_data(data, 12, x);
	free_struct((void **)&(*data)->error);
}

void	free_data_2(t_sl_hub **data)
{
	destroy_img(&(*data)->tiles->img_g, (*data)->mlx->mlx, -1, PATH_COUNT);
	free_img((*data)->mlx->mlx, &(*data)->mlx->img_sample);
	free_win((*data)->mlx->mlx, &(*data)->mlx->win);
	free_mlx(&(*data)->mlx->mlx);
	free_struct((void **)&(*data)->tiles);
	free_struct((void **)&(*data)->mlx);
}

void	free_data_0(t_sl_hub **data, int x)
{
	free_data(data, 2, x);
	free_data(data, 1, x);
	if ((*data)->map_str != NULL)
		free_str(&(*data)->map_str);
	if ((*data)->map != NULL)
		free_array(&(*data)->map, (*data)->map_y, -1);
	free(*data);
	*data = NULL;
	data = NULL;
}

int	free_data(t_sl_hub **data, int which_to_free, int x)
{
	if (data != NULL && which_to_free != -1)
	{
		if (which_to_free == 11 && (*data)->error != NULL
			&& (*data)->error->map_str != NULL)
			free_str(&(*data)->error->map_str);
		else if (which_to_free == 12 && (*data)->error != NULL
			&& (*data)->error->map != NULL)
			free_data_12(data, x);
		else if (which_to_free == 1 && *data != NULL && (*data)->error != NULL)
			free_data_1(data, x);
		else if (which_to_free == 2 && *data != NULL && (*data)->mlx != NULL)
			free_data_2(data);
		else if (which_to_free == 0)
			free_data_0(data, x);
	}
	return (1);
}
