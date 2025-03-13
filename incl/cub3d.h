/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/26 13:05:32 by lade-kon      #+#    #+#                 */
/*   Updated: 2025/03/13 14:15:40 by lade-kon      ########   odam.nl         */
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
bool	is_texture(char *line);
void	get_data(t_data *data, const char *file);
void	init_texture_data(t_data *data, char *line, int i, int flag);
int		parse_and_validate_textures(t_data *data, char *line);
void	parse_validate_init_textures(t_data *data, char *line);
void	validate_file_and_init_data(t_data *data, char *file_as_str);
int		*string_to_rgb(t_data *data, char *str, int i);

// PRINTING //
void	print_data(t_data *data);
void	print_player(t_player *player);
void	print_map(t_map *map);
void	print_floor_and_ceiling(int *floor, int *ceiling);

#endif