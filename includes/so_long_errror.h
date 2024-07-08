/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_errror.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 18:47:04 by npentini          #+#    #+#             */
/*   Updated: 2024/07/08 18:54:57 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_ERROR_H
# define SO_LONG_ERROR_H

typedef struct s_sl_err
{
	int	line_count;
	int	line_len;
	int	close_wall;
	int	path;
	int	wall;
	int	collectible;
	int	exit;
	int	player;
	int	valid_path;
	int	error;
}	t_sl_err;

#endif