/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 05:22:11 by npentini          #+#    #+#             */
/*   Updated: 2024/07/26 00:02:55 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <errno.h>
# include <math.h>
# include <string.h>
// dependencies
# include "../mlx/mlx.h"
# include "../libft/includes/libft.h"
# include "so_long_error.h"
# include "so_long_error_codes.h"
# include "so_long_mlx.h"

typedef struct s_sl_hub
{
	t_sl_err	*error;
	t_sl_mlx	*mlx;
	t_sl_tiles	*tiles;
	char	*map_str;
	char	**map;
	int		map_y;
	int		map_x;
	int		xpm_w;
	int		xpm_h;
	int		e_y;
	int		e_x;
	int		p_y;
	int		p_x;
	int		collect;
	int		curr_y;
	int		curr_x;
	int		movement;
}	t_sl_hub;

int		struct_init(void **struct_ptr, size_t struct_size);
void	print_struct_init(void **struct_ptr, size_t struct_size);
void	free_malloc(t_sl_hub *data, char **map_array, char *map_str, int x);
void	free_str(char **str);
void	free_array(char ***array, int len, int x);
void	free_struct(void **data);
int		free_data(t_sl_hub **data, int which_to_free, int x);
int		move_player(t_sl_hub *data, int y, int x);
int		key_hook(int keycode, t_sl_hub *data);

# define ESC 65307
# define FWD 119
# define BWD 115
# define LFT 97
# define RGT 100

# define UP 0
# define DN 1
# define RT 2
# define LT 3

#endif