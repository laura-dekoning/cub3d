/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/26 13:05:32 by lade-kon      #+#    #+#                 */
/*   Updated: 2025/03/11 21:13:07 by lade-kon      ########   odam.nl         */
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





void	*safe_calloc(size_t count, size_t size);
void	error_message(char *str);
char	*read_file(const char *file);
void	print_data(t_data *data);
void	print_player(t_player *player);
void	print_map(t_map *map);
void	print_floor_and_ceiling(int *floor, int *ceiling);
void	validate_file_and_init_data(t_data *data, char *file_as_str);
bool	is_texture(char *line);
void	set_default(t_data *data);




// void	free_data(t_data *data);
// void	get_data(t_data *data, const char *file);
// void	validate_file(char *file_str);
// void	parse_data(t_data *data, char *file_str);
// void	init_data(t_data *data, char *file_str);


#endif