/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/26 13:05:32 by lade-kon      #+#    #+#                 */
/*   Updated: 2025/03/28 12:23:09 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
// # include "MLX42.h"
# include "structs.h"
# include "macros.h"
# include "default.h"
# include "colors.h"
# include <math.h>


// UTILS //
void	*safe_calloc(t_data *data, size_t count, size_t size);
void	*alloc_mem_for_data(void);
void	error_message(t_data *data, char *str);
void	free_data(t_data *data);
void	set_default(t_data *data);


// PARSING //
char	*read_file(t_data *data, const char *file);
int		is_setting(char *line, size_t start);
bool	is_map_last(t_data *data);
void	get_data(t_data *data, const char *file);
size_t	init_texture_data(t_data *data, char *line, size_t start, int flag);
int		validate_texture_id(t_data *data, char *line, size_t start);
size_t	parse_validate_init_textures(t_data *data, char *line, size_t start);
void	validate_file_and_init_data(t_data *data, char *file_as_str);
int		*string_to_rgb(t_data *data, char *str, int i);
size_t	parse_validate_init_rgb(t_data *data, char *file_as_str, size_t start);
bool	map_content_valid(t_data *data, char *line, size_t start);
size_t	parse_validate_init_map(t_data *data, char *line, size_t start);
void	validate_map(t_data *data);
void	fill_map(t_data *data);
bool	is_map_content(char *str, int start);


// PRINTING //
void	print_data(t_data *data);
void	print_player(t_player *player);
void	print_map(t_map *map);
void	print_floor_and_ceiling(int *floor, int *ceiling);
void	print_check(t_check *check);
void	print_array_with_values(char **map);
void	print_string_with_values(char *str);
void	print_adjacent(char **map, int row, int col);

#endif