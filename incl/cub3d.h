/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/26 13:05:32 by lade-kon      #+#    #+#                 */
/*   Updated: 2025/04/17 15:09:54 by livliege      ########   odam.nl         */
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
# include "rgba.h"
# include "utils.h"

// MEMORY //
t_data	*alloc_mem_for_data(void);
t_game	*alloc_mem_for_game(t_data *data);
void	free_data(t_data *data);
void	free_game(t_game *game);
void	*safe_calloc(t_game *game, t_data *data, size_t count, size_t size);

// UTILS //
void	error_free_game_and_data(t_game *game, t_data *data, char *str);
void	error_free_game(t_game *game, char *str);
void	error_free_data(t_data *data, char *str);
void	error(char *str);

#endif
