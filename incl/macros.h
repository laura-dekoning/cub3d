/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   macros.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/26 13:09:51 by lade-kon      #+#    #+#                 */
/*   Updated: 2025/04/04 12:19:47 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACROS_H
# define MACROS_H

# define SUCCESS 0
# define FAILURE 1

# define NONE 0
# define PATH 1
# define RGB 2

# define WINDOW_WIDTH	1000
# define WINDOW_HEIGHT	1000
# define WINDOW_TITLE	"L&L Cub3d"

# define PI				3.14159265359
# define ONE_D_RADIAN	0.0174533		// 1 degree = 0.0174533 radians

# define FOV			60.0
# define NUMB_RAYS		(WINDOW_WIDTH / 2)

# define RENDER_DIST	1000
# define SHADOW_ALPHA	100		// 0 is complete seetrough aka completely gray (max 255)
# define FOG_FACTOR		4		// smaller numebr is "thicker fog" effect

# define NORTH 			1
# define EAST 			2
# define SOUTH 			3
# define WEST 			4

# define DIR_NORTH 		(3 * (PI / 2))
# define DIR_EAST 		0
# define DIR_SOUTH 		(PI / 2)
# define DIR_WEST 		PI

# define MOVING_SPEED	4
# define ROTATING_SPEED	0.03

# define GRIDSIZE		64

// # define PLAYER_SIZE	(GRIDSIZE_MM / 4)
# define MINIMAP_SCALE	5 		// (the window size / MINIMAP_SCALE will be the size of the minimap.) (1 is fullsize, 5 is good)
# define MINIMAP_GRID	13 		// n X n grid

// Defined error strings to save space in the functions. 
# define ARGS "This is an invalid number of arguments. Provide 1 map file!"
# define FILE "Incorrect file format. Provide a .cub file!"
# define TEXTURE "Incorrect format for textures. Provide a .xpm file!"
# define MALLOC "Allocation failed =("
# define NEG "No negative numbers!\nRGB colors have to be between 0-255!"
# define ALPHA "There are not supposed to be letters in a number, stupid!"
# define BIG "This number is too big!!\nRGB colors have to be between 0-255!"
# define FILE_CONTENT "This content is not supposed to be in the file!"
# define MAP_LAST "The map should be at the end of the file! Nowhere else...."
# define MAP_CONTENT "Map does not contain correct content!!"
# define DUP_P "Map is not valid! Map has more than 1 player."
# define NO_P "Map is not valid! We're missing the player position."
# define NO_WALL "Map is not valid! Map is not surrounded by walls!"
# define DUP_TEXTURE "Map contains more than 1 path for one of the textures!"


#endif