/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_free_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 18:52:20 by npentini          #+#    #+#             */
/*   Updated: 2024/07/26 19:13:28 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_str(char **str)
{
	if (str != NULL && *str != NULL)
	{
		free(*str);
		*str = NULL;
		str = NULL;
	}
}

void	free_array(char ***array, int y_len, int y)
{
	if (array != NULL && *array != NULL)
	{
		while (++y < y_len)
		{
			if ((*array)[y] != NULL)
				free((*array)[y]);
			(*array)[y] = NULL;
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
