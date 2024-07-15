/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_misc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 02:19:41 by npentini          #+#    #+#             */
/*   Updated: 2024/07/15 05:14:16 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

int	struct_init(void **struct_ptr, size_t struct_size)
{
	*struct_ptr = ft_calloc(1, struct_size);
	if (*struct_ptr == NULL)
		return (error_print_free(EMALL, EMSG_EMALL));
	return (0);
}

// int	struct_len(size_t	struct_size)
// {
// 	int	len;
// 	size_t	size;

// 	len = 0;
// 	size = 0;
// 	while (size < struct_size)
// 	{
// 		if (size <= 16)
// 		{
// 			len++;
// 			size += 8;
// 		}
// 		else
// 		{
// 			len++;
// 			size += 4;
// 		}
// 	}
// 	return (len + 1);
// }

// void	print_struct_init(void **struct_ptr, size_t struct_size)
// {
// 	char	*str;
// 	int	len;
// 	int	x;
// 	int	y;

// 	len = struct_len(struct_size);
// 	x = -1;
// 	while (++x < len)
// 	{
// 		str = struct_ptr[x];
// 		if (x < 2)
// 		{
// 			if (x == 0)
// 			{
// 				if (*str == '\0')
// 					ft_printf("member%d:	%s\n", x + 1, "\\0");
// 				else
// 					ft_printf("member%d:	%s\n", x + 1, str);
// 			}
// 			if (x == 1)
// 			{
// 				ft_printf("member%d:\n", x + 1);
// 				y = 0;
// 				while ((str + y) != NULL)
// 				{
// 					ft_printf("%s\n", (str + y));
// 					y++;
// 				}
// 			}
// 		}
// 		else
// 			ft_printf("member%d:	%d\n", x + 1, struct_ptr[x]);
// 	}
// }

void	free_malloc(t_sl_hub *data, char **map_array, char *map_str, int x)
{
	if (map_str != NULL)
		free(map_str);
	if (map_array != NULL)
	{
		while (map_array[++x] != NULL)
			free(map_array[x]);
		free(map_array);
	}
	if (data != NULL)
		free(data);
}
