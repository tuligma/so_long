/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_win_img_setup.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 00:38:04 by npentini          #+#    #+#             */
/*   Updated: 2024/07/25 01:55:26 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

void	path_init_ext(char **path_array)
{
	path_array[16] = PATH_P_BS;
	path_array[17] = PATH_P_BR;
	path_array[18] = PATH_P_BL;
	path_array[19] = PATH_PS_FS;
	path_array[20] = PATH_P_FS;
	path_array[21] = PATH_P_FR;
	path_array[22] = PATH_P_FL;
	path_array[23] = PATH_PS_LS;
	path_array[24] = PATH_P_LS;
	path_array[25] = PATH_P_LR;
	path_array[26] = PATH_P_LL;
	path_array[27] = PATH_PS_RS;
	path_array[28] = PATH_P_RS;
	path_array[29] = PATH_P_RR;
	path_array[30] = PATH_P_RL;
}

void	path_init(char **path_array)
{
	path_array[0] = PATH_G;
	path_array[1] = PATH_S;
	path_array[2] = PATH_WU;
	path_array[3] = PATH_WUR;
	path_array[4] = PATH_WUL;
	path_array[5] = PATH_WD;
	path_array[6] = PATH_WDR;
	path_array[7] = PATH_WDL;
	path_array[8] = PATH_WL;
	path_array[9] = PATH_WR;
	path_array[10] = PATH_EL;
	path_array[11] = PATH_ELR;
	path_array[12] = PATH_C;
	path_array[13] = PATH_XC;
	path_array[14] = PATH_XO;
	path_array[15] = PATH_PS_BS;
	path_init_ext(path_array);
}

int	image_init(t_sl_hub *data, char **path_array)
{
	void	**img_ptr;
	int		x;
	int		width;
	int		height;

	img_ptr = (void **)&data->tiles->img_g;
	x = -1;
	while (++x < PATH_COUNT)
	{
		img_ptr[x] = (void *)mlx_xpm_file_to_image(data->mlx->mlx,
				path_array[x], &width, &height);
		if (img_ptr[x] == NULL)
			return (error_print_free(EXFTI, EMSG_EXFTI));
	}
	return (0);
}

int	setup_image(t_sl_hub *data)
{
	char	**path_array;
	int		result;

	result = struct_init((void **)&data->tiles, sizeof(t_sl_tiles));
	if (result != 0)
		return (error_print_free(EMALL, EMSG_EMALL));
	path_array = (char **)malloc(sizeof(char *) * (PATH_COUNT));
	if (path_array == NULL)
		return (error_print_free(EMALL, EMSG_EMALL));
	path_init(path_array);
	result = image_init(data, path_array);
	if (result != 0)
		return (error_print_free(EXFTI, EMSG_EXFTI));
	free(path_array);
	return (0);
}

int	setup_window(t_sl_hub *data)
{
	int	result;

	result = struct_init((void **)&data->mlx, sizeof(t_sl_mlx));
	if (result != 0)
		return (error_print_free(EMALL, EMSG_EMALL));
	data->mlx->mlx = mlx_init();
	if (data->mlx->mlx == NULL)
		return (error_print_free(EXINI, EMSG_EXINI));
	data->mlx->img_sample = mlx_xpm_file_to_image(data->mlx->mlx,
			PATH_G, &data->xpm_w, &data->xpm_h);
	if (data->mlx->img_sample == NULL)
		return (error_print_free(EXFTI, EMSG_EXFTI));
	else if (data->xpm_w != data->xpm_h)
		return (error_print_free(EXFNP, EMSG_EXFNP));
	mlx_destroy_image(data->mlx->mlx, data->mlx->img_sample);
	data->mlx->img_sample = NULL;
	data->mlx->height = data->map_y * data->xpm_h;
	data->mlx->width = data->map_x * data->xpm_w;
	data->mlx->win = mlx_new_window(data->mlx->mlx,
			data->mlx->width, data->mlx->height, "so_long");
	if (data->mlx->win == NULL)
		return (error_print_free(EMALL, EMSG_EMALL));
	return (0);
}
