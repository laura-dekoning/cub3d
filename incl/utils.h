/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/04/01 16:44:06 by lade-kon      #+#    #+#                 */
/*   Updated: 2025/04/23 15:54:27 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "cub3d.h"

char	**split_cub3d(char const *s, char c);

// PRINTING //
void	print_data(t_data *data);
void	print_player(t_player *player);
void	print_map(t_map *map);
void	print_floor_and_ceiling(int *floor, int *ceiling);
void	print_check(t_check *check);
void	print_array_with_values(char **map);
void	print_array_with_index(char **map);
void	print_string_with_index(char *str);
void	print_string_with_values(char *str);
void	print_adjacent(char **map, int row, int col);

#endif