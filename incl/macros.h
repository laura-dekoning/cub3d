/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   macros.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/26 13:09:51 by lade-kon      #+#    #+#                 */
/*   Updated: 2025/02/28 15:44:50 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACROS_H
# define MACROS_H

# define SUCCESS 0
# define FAILURE 1

# define NORTH 1
# define SOUTH 2
# define WEST 3
# define EAST 4

# define ARGS "This is an invalid number of arguments. Provide 1 map file!"
# define FILE "Incorrect file format. Provide a .cub file!"
# define TEXTURE "Incorrect format for textures. Provide a .xpm file!"
# define DUP_P "Map is not valid! Map has more than 1 player."
# define DUP_E "Map is not valid! Map has more than 1 exit."
# define DUP_P_E "Map is not valid! Map has player and exit duplicates."
# define DUP_NO_C "Map is not valid! Map has duplicates and no collectables."
# define NO_P "Map is not valid! We're missing a player."
# define NO_E "Map is not valid! There is no exit."
# define NO_C "Map is not valid! No collectables available."
# define NO_WALL "Map is not valid! Map is not surrounded by walls!"
# define MALLOC "Malloc failed."


#endif