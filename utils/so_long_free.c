/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 13:05:36 by npentini          #+#    #+#             */
/*   Updated: 2024/07/25 16:36:22 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_img(void *mlx, void **img)
{
	if (img != NULL && *img != NULL)
	{
		mlx_destroy_image(mlx, *img);
		*img = NULL;
	}
}

void	free_win(void *mlx, void **win)
{
	if (win != NULL && *win != NULL)
	{
		mlx_destroy_window(mlx, *win);
		*win = NULL;
	}
}

void	free_mlx(void **mlx)
{
	if (mlx != NULL && *mlx != NULL)
	{
		mlx_destroy_display(*mlx);
		free(*mlx);
		*mlx = NULL;
	}
}

void	free_str(char **str)
{
	if (str != NULL && *str != NULL)
	{
		free(*str);
		*str = NULL;
		str = NULL;
	}
}

void	free_array(char ***array, int y_len, int y)
{
	if (array != NULL && *array != NULL)
	{
		while (++y < y_len)
		{
			if ((*array)[y] != NULL)
				free((*array)[y]);
			(*array)[y] = NULL;
		}
		free(*array);
		*array = NULL;
	}
}

void	free_struct(void **data)
{
	if (data != NULL && *data != NULL)
	{
		free(*data);
		*data = NULL;
	}
}

void	destroy_img(void **data, void *mlx, int x, int len)
{
	if (data != NULL && *data != NULL)
	{
		while (++x < len)
		{
			if (data[x] == NULL)
				continue ;
			mlx_destroy_image(mlx, data[x]);
			data[x] = NULL;
		}
	}
	
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
		{
			free_data(data, 11, x);
			free_array(&(*data)->error->map, (*data)->error->line_count, x);
		}
		else if (which_to_free == 1 && *data != NULL && (*data)->error != NULL)
		{
			free_data(data, 12, x);
			free_struct((void **)&(*data)->error);
		}
		else if (which_to_free == 2 && *data != NULL && (*data)->mlx != NULL)
		{
			destroy_img(&(*data)->tiles->img_g, (*data)->mlx->mlx, -1, PATH_COUNT);
			free_img((*data)->mlx->mlx, &(*data)->mlx->img_sample);
			free_win((*data)->mlx->mlx, &(*data)->mlx->win);
			free_mlx(&(*data)->mlx->mlx);
			free_struct((void **)&(*data)->tiles);
			free_struct((void **)&(*data)->mlx);
		}
		else if (which_to_free == 0)
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
	}
	return (1);
}
