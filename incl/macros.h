/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   macros.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/26 13:09:51 by lade-kon      #+#    #+#                 */
/*   Updated: 2025/04/24 12:28:18 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACROS_H
# define MACROS_H

# define SUCCESS 0
# define FAILURE 1

# define NONE 0
# define PATH 1
# define RGB 2

# define WINDOW_WIDTH	1800
# define WINDOW_HEIGHT	1800
# define WINDOW_TITLE	"L&L Cub3d"

# define PI				3.141592654
# define ONE_D_RADIAN	0.0174533	// 1 degree = 0.0174533 radians

# define FOV			60.0
# define NUMB_RAYS		900

# define RENDER_DIST	1000
# define SHADOW_ALPHA	100
# define FOG_FACTOR		4

# define DIR_NORTH 		4.71238898
# define DIR_EAST 		0
# define DIR_SOUTH 		1.570796327
# define DIR_WEST 		3.141592654

# define MOVING_SPEED	4
# define ROTATING_SPEED	0.03

# define GRIDSIZE		64

# define MINIMAP_SCALE	5			// (1 is fullscreen, 5 is good)
# define MINIMAP_GRID	13

// Defined error strings to save space in the functions. 
# define ARGS "This is an invalid number of arguments. Provide 1 map file!"
# define FILE "Incorrect file format. Provide a .cub file!"
# define TEXTURE "Incorrect format for texture. Provide a .png file!"
# define MALLOC "Allocation failed =("
# define NEG "No negative numbers!\nRGB colors have to be between 0-255!"
# define ALPHA "There are not supposed to be letters in a number, stupid!"
# define EMPTY "File is empty. Needs textures, rgb and a map."
# define BIG "This number is too big!!\nRGB colors have to be between 0-255!"
# define FILE_CONTENT "This content is not supposed to be in the file!"
# define MAP_LAST "Some data is missing. Map should be at the end of the file!"
# define MAP_CONTENT "Invalid map! Only '0' '1' ' ' 'N' 'E' 'S' 'W' allowed"
# define DUP_P "Map is not valid! Map has more than 1 player."
# define NO_P "Map is not valid! We're missing the player position."
# define NO_WALL "Map is not valid! Map is not surrounded by walls!"
# define NO_MAP "Map is missing bro =("
# define DUP_TEXTURE "Map contains more than 1 path for one of the textures!"
# define SYMBOLS "Only numbers and komma's are allowed in rgb!!!" 

#endif