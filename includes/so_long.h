/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 05:22:11 by npentini          #+#    #+#             */
/*   Updated: 2024/07/14 22:40:58 by npentini         ###   ########.fr       */
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
// dependencies
# include "../mlx/mlx.h"
# include "../libft/includes/libft.h"
# include "so_long_errror.h"

typedef struct s_sl_hub
{
	t_sl_err	*error;
	t_sl_vmap	*path;
}	t_sl_hub;

int		struct_init(void **struct_ptr, size_t struct_size);
void	print_struct_init(void **struct_ptr, size_t struct_size);
void	free_malloc(t_sl_hub *data, char **map_array, char *map_str, int x);

#endif