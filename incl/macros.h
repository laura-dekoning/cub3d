/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   macros.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/26 13:09:51 by lade-kon      #+#    #+#                 */
/*   Updated: 2025/03/13 18:37:37 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACROS_H
# define MACROS_H

# define SUCCESS 0
# define FAILURE 1

# define NONE 0
# define PATH 1
# define RGB 2

# define ARGS "This is an invalid number of arguments. Provide 1 map file!"
# define FILE "Incorrect file format. Provide a .cub file!"
# define TEXTURE "Incorrect format for textures. Provide a .xpm file!"
# define MALLOC "Allocation failed =("
# define NEG "Floor and ceiling can NOT have negative numbers!"
# define DUP_P "Map is not valid! Map has more than 1 player."
# define NO_P "Map is not valid! We're missing the player position."
# define NO_WALL "Map is not valid! Map is not surrounded by walls!"
# define DUP_TEXTURE "Map contains more than 1 path for one of the textures!"


#endif