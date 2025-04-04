/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parsing.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/26 15:04:44 by lade-kon      #+#    #+#                 */
/*   Updated: 2025/04/04 12:48:38 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

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

// PARSING //
char	*read_file(t_data *data, const char *file);
int		is_setting(char *line);
bool	is_map_last(t_data *data);
void	get_data(t_game *game, t_data *data, const char *file);
void	init_texture_data(t_data *data, char *line, int flag);
int		validate_texture_id(t_data *data, char *line);
void	validate_file_and_init_data(t_data *data, char **file);
void	parse_validate_init_textures(t_data *data, char *line);
void	parse_validate_init_map(t_data *data, char **file_as_arr, int y);
void	string_to_rgb(t_data *data, int **target, char *line, int i);
void	parse_validate_init_rgb(t_data *data, char *line);
void	map_content_valid(t_data *data);
void	validate_map(t_data *data);
void	fill_and_replace_space(t_data *data);
bool	is_map_content(char *line);
void	validate_data(t_data *data);

#endif