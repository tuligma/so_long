/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_init.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 19:25:47 by npentini          #+#    #+#             */
/*   Updated: 2024/07/26 19:28:56 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_INIT_H
# define SO_LONG_INIT_H

#include "so_long.h"

int			struct_init(void **struct_ptr, size_t struct_size);
int			(**f_main_init(void))(t_sl_hub *data);
char		*line_extraction(int fd, t_sl_hub *data,
				char *map_str, char *(*f)(int));
int			map_extraction(t_sl_hub *data, char *file);
t_sl_hub	*init_handler(int argc, char *argv[]);

#endif