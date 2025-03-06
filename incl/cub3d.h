/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/26 13:05:32 by lade-kon      #+#    #+#                 */
/*   Updated: 2025/03/06 18:27:49 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# include "MLX42.h"
# include "structs.h"
# include "macros.h"
# include "colors.h"
# include <math.h>





void	error_message(char *str);
void	*safe_calloc(size_t count, size_t size);
void	free_data(t_data *data);
void	get_data(t_data *data, const char *file);
char	*read_file(const char *file);
void	validate_file(char *file_str);
void	parse_data(t_data *data, char *file_str);
void	init_data(t_data *data, char *file_str);


#endif