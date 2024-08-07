/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_misc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 02:19:41 by npentini          #+#    #+#             */
/*   Updated: 2024/07/26 19:28:30 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	error_print_free(int error_code, char *error_message)
{
	if (error_code != 0)
	{
		ft_putstr_fd(RE, STDERR_FILENO);
		ft_putstr_fd(EMSG, STDERR_FILENO);
		if (error_code != EARGC || error_code != EARGF
			|| error_code != EARGX || error_code != EMALL)
			ft_putstr_fd(EMSG_IMP, STDERR_FILENO);
		ft_putstr_fd(IWH, STDERR_FILENO);
		ft_putstr_fd(error_message, STDERR_FILENO);
		ft_putstr_fd(CR, STDERR_FILENO);
	}
	return (1);
}
