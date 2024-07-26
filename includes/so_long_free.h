/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_free.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 18:54:40 by npentini          #+#    #+#             */
/*   Updated: 2024/07/26 19:06:02 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_FREE_H
# define SO_LONG_FREE_H

#include "so_long.h"

void	free_str(char **str);
void	free_array(char ***array, int y_len, int y);
void	free_struct(void **data);
void	free_img(void *mlx, void **img);
void	free_win(void *mlx, void **win);
void	free_mlx(void **mlx);
void	destroy_img(void **data, void *mlx, int x, int len);
void	free_data_12(t_sl_hub **data, int x);
void	free_data_1(t_sl_hub **data, int x);
void	free_data_2(t_sl_hub **data);
void	free_data_0(t_sl_hub **data, int x);
int		free_data(t_sl_hub **data, int which_to_free, int x);

#endif