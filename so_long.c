/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 22:54:44 by npentini          #+#    #+#             */
/*   Updated: 2024/07/14 23:16:30 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

// char	**array_init(int size, int len)
// {
// 	char	**map_path;
// 	int		x;

// 	map_path = (char **)malloc(sizeof(char *) * (size + 1));
// 	if (map_path == NULL)
// 		return (NULL);
// 	x = 0;
// 	while (x < size)
// 	{
// 		map_path[x] = (char *)malloc(sizeof(char) * (len + 1));
// 		if (map_path == NULL)
// 			return (NULL);
// 		ft_memset(map_path[x], '0', len);
// 		map_path[x][len] = '\0';
// 		x++;
// 	}
// 	map_path[size] = NULL;
// 	return (map_path);
// }

int	main(int argc, char *argv[])
{
	int	error;

	error = error_handler(argc, argv);
	if (error != 0)
		return (1);
	ft_printf("Success!\n");
	return (0);
}
