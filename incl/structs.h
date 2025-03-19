/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   structs.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/26 15:04:44 by lade-kon      #+#    #+#                 */
/*   Updated: 2025/03/19 14:08:16 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

//0: NORTH, 1: SOUTH, 2: EAST, 3: WEST, 4: FLOOR, 5: CEILING, 6: MAP.
typedef struct s_check
{
	bool	setting[7]; 
}				t_check;

typedef enum e_setting
{
	NORTH,
	EAST,
	SOUTH,
	WEST,
	FLOOR,
	CEILING,
	MAP
}			t_setting;

typedef struct s_map
{
	char	**map;
	size_t	rows; //rows = if (ft_strlen(map[x][y] > rows) rows = y;
	size_t	cols;
}				t_map;

typedef struct s_player
{
	int		x;
	int		y;
	int		dir;
	bool	pos;
}				t_player;

//0: NORTH, 1: SOUTH, 2: EAST, 3: WEST
// maybe we can put the textures in an array as well like this:
// char *textures[4]; // 0: NORTH, 1: SOUTH, 2: EAST, 3: WEST
typedef struct s_data
{
	char		*north_texture;
	char		*south_texture;
	char		*east_texture;
	char		*west_texture;
	int			*floor;
	int			*ceiling;
	t_map		*map;
	t_player	*player;
	t_check		*check;
}				t_data;

#endif