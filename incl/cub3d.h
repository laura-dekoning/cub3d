/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/26 13:05:32 by lade-kon      #+#    #+#                 */
/*   Updated: 2025/04/07 15:36:00 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <math.h>
# include <sys/time.h>
# include "libft.h"
# include "MLX42.h"
# include "macros.h"
# include "game.h"
# include "parsing.h"
# include "utils.h"

// MEMORY //
void	*alloc_mem_for_data(void);
void	*alloc_mem_for_game(void);
void	free_data(t_data *data);
void	*safe_calloc(t_data *data, size_t count, size_t size);

// UTILS //
void	error_free_game(t_game *game, char *str)
void	error_free_data(t_data *data, char *str)


#endif
