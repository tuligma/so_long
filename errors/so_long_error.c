/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 22:58:21 by npentini          #+#    #+#             */
/*   Updated: 2024/07/26 19:22:40 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	error_func_init(int (**error_function)(t_sl_hub*))
{
	error_function[0] = is_map_empty;
	error_function[1] = is_map_rectangular;
	error_function[2] = is_map_walls;
	error_function[3] = is_map_one_epc;
	error_function[4] = is_map_valid_path;
	error_function[5] = NULL;
}

int	map_error_checker(t_sl_hub *data)
{
	int	(**error_function)(t_sl_hub*);
	int	y;
	int	result;

	error_function = malloc(sizeof(int (*)(t_sl_hub *)) * (ERR_FUNC_COUNT + 1));
	if (error_function == NULL)
		return (error_print_free(EMALL, EMSG_EMALL));
	error_func_init(error_function);
	y = -1;
	result = 0;
	while (error_function[++y] != NULL)
	{
		result = error_function[y](data);
		if (result != 0)
		{
			free(error_function);
			return (result);
		}
	}
	free(error_function);
	free_data(&data, 1, -1);
	return (0);
}