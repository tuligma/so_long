/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_free_utils_mlx.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 18:53:21 by npentini          #+#    #+#             */
/*   Updated: 2024/07/26 19:13:18 by npentini         ###   ########.fr       */
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
