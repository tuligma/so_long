/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_error_codes.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npentini <npentini@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 01:34:40 by npentini          #+#    #+#             */
/*   Updated: 2024/07/15 02:03:21 by npentini         ###   ########.fr       */
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

// ERROR MESSAGE

# define EMSG "ERROR\n"
# define EMSG_EARGC "Invalid number of arguments!\n"
# define EMSG_EARGF "The map file is not a \".ber\" file!\n"
# define EMSG_EARGX "The map file doesnt exit!\n"

# define EMSG_EMALL "Memory allocation failed!\n"
# define EMSG_EFILO "File cannot be opened!\n"

# define EMSG_IMP "Invalid Map: "
# define EMSG_EMPEY "Map is EMPTY!!!\n"
# define EMSG_EMPRT "Map is NOT RECTANGULAR!!!\n"
# define EMSG_EMPWL "Map wall is NOT FORTIFIED!!!\n"
# define EMSG_EMPOE "Map has OTHER ELEMENT!!!\n"
# define EMSG_EMPME "Map has MULTIPLE EXIT!!!\n"
# define EMSG_EMPMP "Map has MULTIPLE PLAYER!!!\n"
# define EMSG_EMPNC "Map has NO COLLECTIBLE/S!!!\n"
# define EMSG_EMPNP "Map has NO VALID PATH!!!\n"


#endif