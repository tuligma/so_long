/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_errror.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 18:47:04 by npentini          #+#    #+#             */
/*   Updated: 2024/07/13 19:10:20 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_ERROR_H
# define SO_LONG_ERROR_H

typedef struct s_sl_hub t_sl_hub;


typedef struct s_sl_err
{
	char *map_str;
	char **map;
	char **map_path;
	int	line_count;
	int	line_len;
	int	close_wall;
	int	path;
	int	wall;
	int	collectible;
	int	exit;
	int	player;
	int	valid_path;
	int	exit_x;
	int	exit_y;
	int	player_x;
	int	player_y;
	int	collect_x;
	int	collect_y;
	int	current_x;
	int	current_y;
}	t_sl_err;

typedef struct s_sl_vmap
{
	int	exit_x;
	int	exit_y;
	int	player_x;
	int	player_y;
	int	collect_x;
	int	collect_y;
	int	current_x;
	int	current_y;
}	t_sl_vmap;

# include "mycolors.h"

int	error_printer(int error_code, t_sl_hub *data, char **map, char *map_str);
// print array func 
void	print_map_array(char **map_array);
void	print_map_array_colored(char **map, int line_count, int line_len);

// error function pointers
int	is_map_empty(t_sl_hub *data);
int	is_map_rectangular(t_sl_hub *data);
int	is_map_walls(t_sl_hub *data);
int	is_map_one_epc(t_sl_hub *data);

#define ERR_FUNC_COUNT 5

#endif