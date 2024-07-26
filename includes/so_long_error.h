/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_error.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 18:47:04 by npentini          #+#    #+#             */
/*   Updated: 2024/07/26 19:21:38 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_ERROR_H
# define SO_LONG_ERROR_H

typedef struct s_sl_hub t_sl_hub;


typedef struct s_sl_err
{
	char *map_str;
	char **map;
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

int		error_print_free(int error_code, char *error_message);
void	print_struct(t_sl_err *error);
void	print_map_array(char **map_array);


int		map_error_checker(t_sl_hub *data);
void	error_func_init(int (**error_function)(t_sl_hub*));


// error function pointers
int		error_argument(int argc, char *argv[]);
int		is_map_empty(t_sl_hub *data);
int		is_map_rectangular(t_sl_hub *data);
int		is_map_walls(t_sl_hub *data);
int		find_epc(t_sl_hub *data, char **map, int y, int len);
int		is_map_one_epc(t_sl_hub *data);
void	find_epc_location_ext(t_sl_hub *data, char **map, int y);
void	find_epc_location(t_sl_hub *data);
int		find_path(t_sl_hub *data, int y, int x);
int		is_map_valid_path(t_sl_hub *data);

#define ERR_FUNC_COUNT 5

#endif