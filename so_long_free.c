/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 13:05:36 by npentini          #+#    #+#             */
/*   Updated: 2024/07/15 14:27:14 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

void	free_str(char **str)
{
	if (str != NULL && *str != NULL)
	{
		free(*str);
		*str = NULL;
		str = NULL;
	}
}

void	free_array(char ***array, int len, int x)
{
	if (array != NULL && *array != NULL)
	{
		while (++x < len)
		{
			if ((*array)[x] != NULL)
				free((*array)[x]);
			(*array)[x] = NULL;
		}
		free(*array);
		*array = NULL;
	}
}

void	free_struct(void **data)
{
	if (data != NULL && *data != NULL)
	{
		free(*data);
		*data = NULL;
	}
}

int	free_data(t_sl_hub **data, int which_to_free, int x)
{
	if (data != NULL && which_to_free != -1)
	{
		if (which_to_free == 11 && (*data)->error != NULL
			&& (*data)->error->map_str != NULL)
			free_str(&(*data)->error->map_str);
		else if (which_to_free == 12 && (*data)->error != NULL
			&& (*data)->error->map != NULL)
		{
			free_data(data, 11, x);
			free_array(&(*data)->error->map, (*data)->error->line_count, x);
		}
		else if (which_to_free == 1 && *data != NULL && (*data)->error != NULL)
		{
			free_data(data, 12, x);
			free_struct((void **)&(*data)->error);
		}
		else if (which_to_free == 0)
		{
			free_data(data, 1, x);
			free(*data);
			*data = NULL;
			data = NULL;
		}
	}
	return (1);
}
