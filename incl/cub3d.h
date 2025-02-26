/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: lade-kon <lade-kon@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/02/26 13:05:32 by lade-kon      #+#    #+#                 */
/*   Updated: 2025/02/26 14:49:43 by lade-kon      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# include "MLX42.h"
# include "macros.h"
# include "colors.h"
# include <math.h>

# define SUCCESS 0
# define FAILURE 1


typedef struct s_data
{
	char		*north_texture;
	char		*south_texture;
	char		*west_texture;
	char		*east_texture;
	int			*floor;
	int			*ceiling;
	t_map		*map;
	t_player	*player;
}				t_data;

typedef struct s_map
{
	char	**map;
	int		rows;
	int		cols;
}				t_map;

typedef struct s_player
{
	int	x;
	int	y;
	int	dir;
}				t_player;

#endif