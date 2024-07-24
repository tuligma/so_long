/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_error_codes.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 01:34:40 by npentini          #+#    #+#             */
/*   Updated: 2024/07/25 00:56:59 by npentini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_ERROR_CODES_H
# define SO_LONG_ERROR_CODES_H

// ERROR CODES

// argument_errors
# define EARGC 1000 // if argument is > or < 2
# define EARGF 1001 // if argument is not .ber file
# define EARGX 1002 // if the .ber file does not exist

// memory and file error
# define EMALL 2001 // if no allocation by malloc
# define EFILO 2002 // if the file cant be open

// map validator
# define EMPEY 2003 // if the map is not valid :: map is empty
# define EMPRT 2004 // if the map is not valid :: map is not rectangular
# define EMPWL 2005 // if the map is not valid :: map has an invalid wall
# define EMPOE 2006 // if the map is not valid :: map has other element
# define EMPME 2007 // if the map is not valid :: map has multiple Exit
# define EMPMP 2008 // if the map is not valid :: map has multiple Player
# define EMPNC 2009 // if the map is not valid :: map has no Collectible/s
# define EMPNP 2010 // if the map is not valid :: map has no valid path

# define EXINI 3000 // if the mlx_init fails.
# define EXWIN 3001 // if the mlx_new_window fails.
# define EXFTI 3002 // if the mlx_xmp_file_to_images fails.
# define EXFNP 3003	// if the xpm file is not proportion.
# define EXIGA 3004 // if the mlx_get_data_addr fails;
// ERROR MESSAGE

# define EMSG "ERROR\n"
# define EMSG_EARGC "Invalid number of arguments!\n"
# define EMSG_EARGF "The map file is not a \".ber\" file!\n"
# define EMSG_EARGX "The map file doesn't exist!\n"

# define EMSG_EMALL "Memory allocation failed!\n"
# define EMSG_EFILO "File cannot be opened!\n"

# define EMSG_IMP "Invalid Map: "
# define EMSG_EMPEY "EMPTY!!!\n"
# define EMSG_EMPRT "NOT RECTANGULAR!!!\n"
# define EMSG_EMPWL "Wall IS NOT FORTIFIED!!!\n"
# define EMSG_EMPOE "HAS AN OTHER ELEMENT!!!\n"
# define EMSG_EMPME "HAS A MULTIPLE EXIT!!!\n"
# define EMSG_EMPMP "HAS A MULTIPLE PLAYER!!!\n"
# define EMSG_EMPNC "HAS NO COLLECTIBLE/S!!!\n"
# define EMSG_EMPNP "HAS NO VALID PATH!!!\n"

# define EMSG_EXINI "mlx_init() function failed!!!"
# define EMSG_EXWIN "mlx_new_window() function failed!!!"
# define EMSG_EXFTI "mlx_xpm_file_to_image() function failed!!!"
# define EMSG_EXFNP "the image's width and height are not proportion!!!"
# define EMSG_EXIGA "mlx_get_data_addr() function failed!!!"

#endif