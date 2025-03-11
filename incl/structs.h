/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   structs.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/26 15:04:44 by lade-kon      #+#    #+#                 */
/*   Updated: 2025/03/11 22:04:35 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_map
{
	char	**map;
	int		rows; //rows = if (ft_strlen(map[x][y] > rows) rows = y;
	int		cols;
}				t_map;

typedef struct s_player
{
	int	x;
	int	y;
	int	dir;
}				t_player;

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
}				t_data;

#endif